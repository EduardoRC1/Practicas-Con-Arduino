int boton = 3;           // Pin del botón
int led = 2;             // Pin del LED
int estadoLED = LOW;     // Auxiliar: guarda el estado actual del LED
int ultimoEstadoBoton = LOW; // Para detectar cambio de pulsación

void setup() {
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT);
}

void loop() {
  int lectura = digitalRead(boton);

  // Detectamos el cambio de estado (cuando se presiona)
  if (lectura == HIGH && ultimoEstadoBoton == LOW) {
    // Cambiamos el estado del LED usando la auxiliar
    if (estadoLED == LOW) {
      estadoLED = HIGH;
    } else {
      estadoLED = LOW;
    }
    digitalWrite(led, estadoLED); // Encendemos o apagamos
    delay(200); // Anti-rebote (para que no detecte un solo clic como varios)
  }

  ultimoEstadoBoton = lectura;
}