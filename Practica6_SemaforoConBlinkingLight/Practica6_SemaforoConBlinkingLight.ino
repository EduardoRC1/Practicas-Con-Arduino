void setup() {
  pinMode(11, OUTPUT); // Verde
  pinMode(12, OUTPUT); // Amarillo
  pinMode(13, OUTPUT); // Rojo
}

void loop() {
  // Verde encendido 5 segundos
  digitalWrite(11, HIGH);
  delay(5000);
  digitalWrite(11, LOW);

  // Amarillo encendido 3 segundos
  digitalWrite(12, HIGH);
  delay(3000);
  digitalWrite(12, LOW);

  // Amarillo parpadea 3 veces (100 ms encendido, 100 ms apagado)
  for (int i = 0; i < 3; i++) {
    digitalWrite(12, HIGH);
    delay(500);
    digitalWrite(12, LOW);
    delay(500);
  }

  // Rojo encendido 4 segundos
  digitalWrite(13, HIGH);
  delay(4000);
  digitalWrite(13, LOW);
}