#include <Stepper.h>

// Pines del sensor ultrasónico
const int trigPin = 7;
const int echoPin = 6;

// Motor paso a paso
const int stepsPerRevolution = 2048;
Stepper motor(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  motor.setSpeed(10); // Puedes subirlo si quieres que gire más rápido
}

void loop() {
  long duration;
  float distance;

  // Medición con el sensor ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.println(distance);

  if (distance < 20.0) {
    Serial.println("Objeto detectado: girando motor");
    motor.step(20); // Pequeños pasos para que gire mientras haya objeto
  } else {
    // No se hace nada, el motor se detiene
    Serial.println("No hay objeto: motor detenido");
  }

  delay(50); // Pequeño retraso para control de lectura y velocidad
}