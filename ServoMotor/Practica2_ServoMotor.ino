#include <Servo.h>

Servo Servo1;
int const pinPot = A0;
int valorPot;
int angulo;
int dt = 100;


void setup() {
  // put your setup code here, to run once:
  Servo1.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:

valorPot = analogRead(pinPot);
Serial.print("Posicion del potenciometro");
Serial.print(valorPot);
angulo = map(valorPot, 0, 1023, 0, 180);
Serial.print(", Angulo");
Servo1.write(angulo);
delay(dt);

}