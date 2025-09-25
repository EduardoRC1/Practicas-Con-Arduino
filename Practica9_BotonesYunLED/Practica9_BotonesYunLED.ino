int botonEncender = 3;   // Pin del botón para encender
int botonApagar = 4;     // Pin del botón para apagar
int led = 2;             // Pin del LED

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botonEncender, INPUT);
  pinMode(botonApagar, INPUT);
}

void loop() {
  // Si el botón de encender se presiona
  if (digitalRead(botonEncender) == HIGH) {
    digitalWrite(led, HIGH);  // Enciende LED
    delay(200); // Anti-rebote
  }

  // Si el botón de apagar se presiona
  if (digitalRead(botonApagar) == HIGH) {
    digitalWrite(led, LOW);   // Apaga LED
    delay(200); // Anti-rebote
  }
}
