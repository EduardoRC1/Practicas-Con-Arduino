int boton1 = 3;
int boton2 = 4;
int led1 = 8;
int led2 = 9;

void setup() {
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int estadoBoton1 = digitalRead(boton1);
  int estadoBoton2 = digitalRead(boton2);

  // Caso 1: SOLO botón1 presionado
  if (estadoBoton1 == HIGH && estadoBoton2 == LOW) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }

  // Caso 2: SOLO botón2 presionado
  else if (estadoBoton1 == LOW && estadoBoton2 == HIGH) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }

  // Caso 3: AMBOS botones presionados → parpadeo 7 veces
  else if (estadoBoton1 == HIGH && estadoBoton2 == HIGH) {
    for (int i = 0; i < 7; i++) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      delay(200);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      delay(200);
    }
  }

  // Caso 4: NINGÚN botón presionado
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
}