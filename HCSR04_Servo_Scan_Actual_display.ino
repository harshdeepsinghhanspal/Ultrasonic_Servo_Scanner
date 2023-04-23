#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

Servo myservo;
int pos = 0;

const int trigPin = 9;
const int echoPin = 10;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 128, 64);
  display.clearDisplay();
  display.display();

  myservo.attach(3);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  for(pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15);

    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration / 58.2;

    display.clearDisplay();
    display.drawCircle(64, 32, 30, WHITE);
    display.drawLine(64, 32, 64 + (pos * cos((pos - 90) * 0.0174533)), 32 + (pos * sin((pos - 90) * 0.0174533)), WHITE);
    display.display();
  }

  for(pos = 180; pos>=0; pos-=1) {
    myservo.write(pos);
    delay(15);

    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration / 58.2;

    display.clearDisplay();
    display.drawCircle(64, 32, 30, WHITE);
    display.drawLine(64, 32, 64 + (pos * cos((pos - 90) * 0.0174533)), 32 + (pos * sin((pos - 90) * 0.0174533)), WHITE);
    display.display();
  }
}
