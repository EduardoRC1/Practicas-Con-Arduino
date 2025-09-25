#include <AccelStepper.h>

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define POT A0

AccelStepper motor(AccelStepper::HALF4WIRE, IN1, IN3, IN2, IN4);

void setup() {
  motor.setMaxSpeed(5000);       
  motor.setAcceleration(5000);    
}

void loop() {
  int valor = analogRead(POT);   
  int centro = 512;
  int diferencia = valor - centro;
  
  if (abs(diferencia) < 50) {
    motor.setSpeed(0);
  } else {
    
    int direccion = (diferencia > 0) ? 1 : -1;

    float velocidad = map(abs(diferencia), 0, 512, 100, 1500);

    motor.setSpeed(direccion * velocidad);
  }

  motor.runSpeed();
}