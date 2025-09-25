#include <Ultrasonic.h>

const int trigPin = 7;
const int echoPin = 6;
const int buzzerPin = 8; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzerPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

long duration = pulseIn(echoPin, HIGH);
float distance = duration * 0.034/2;

Serial.print(distance);
Serial.print("Distancia");
Serial.println();

if (distance <= 20) {
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
  delay(100);
} else {
  digitalWrite(buzzerPin, LOW);
}

}
