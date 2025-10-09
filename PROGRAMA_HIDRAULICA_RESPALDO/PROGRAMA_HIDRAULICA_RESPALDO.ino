#include <Servo.h>

// Servos
Servo servo1;
Servo servo2;
const int servo1Pin = 8;
const int servo2Pin = 9;

// LEDs
const int ledVerde = 12;
const int ledAmarillo = 13;

// Sensor ultrasónico HC-SR04
const int trigPin = 3;
const int echoPin = 4;
const float distanciaActivacion = 20.0; // cm

// Posiciones iniciales
int posInicial1 = 90;
int posInicial2 = 90;
int giro = 40;

bool enProceso = false;

void setup() {
  Serial.begin(9600);

  // Configuración servos
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo1.write(posInicial1);
  servo2.write(posInicial2);

  // LEDs
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);

  // Sensor ultrasónico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracion = pulseIn(echoPin, HIGH, 30000); // timeout 30 ms
  float distancia = duracion * 0.0343 / 2; // cm
  return distancia;
}

void loop() {
  if (!enProceso) {
    float distancia = medirDistancia();

    if (distancia == 0) {
      Serial.println("No se detecta eco. Verifica conexiones o distancia del objeto.");
    } else {
      Serial.print("Distancia medida: ");
      Serial.print(distancia);
      Serial.println(" cm");

      if (distancia <= distanciaActivacion) {
        Serial.println("Objeto dentro del rango. Esperando 5 segundos...");
        delay(5000);

        distancia = medirDistancia();
        if (distancia > 0 && distancia <= distanciaActivacion) {
          Serial.println("Activando secuencia de servos...");
          enProceso = true;
          ejecutarSecuencia();
          enProceso = false;
          Serial.println("Secuencia completada.");
        } else {
          Serial.println("Objeto fuera del rango tras espera.");
        }
      }
    }
  }
}

void girarServo(Servo &servo, int inicio, int fin) {
  int paso = (inicio < fin) ? 1 : -1;
  for (int pos = inicio; pos != fin; pos += paso) {
    servo.write(pos);
    delay(15);
  }
}

void ejecutarSecuencia() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarillo, HIGH);

  girarServo(servo1, posInicial1, posInicial1 + giro);
  delay(2000);
  girarServo(servo2, posInicial2, posInicial2 + giro);
  delay(2000);
  girarServo(servo1, posInicial1 + giro, posInicial1);
  delay(2000);
  girarServo(servo2, posInicial2 + giro, posInicial2);
  delay(2000);

  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledVerde, HIGH);
}
