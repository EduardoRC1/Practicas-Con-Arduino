//Practica 15 - Buzzer Activo/Passivo
// Declaración de pines y variables
int BuzzerPin = 8;        // Pin digital donde está conectado el buzzer
int ButtonPin = 2;        // Pin digital donde está conectado el botón
int ButtonState;          // Variable para guardar el estado del botón (presionado o no)
int delayTime = 500;      // Tiempo de espera entre notas en milisegundos

// ----------------

void setup() {
  pinMode(BuzzerPin, OUTPUT);         // El buzzer se comporta como salida (produce sonido)
  pinMode(ButtonPin, INPUT_PULLUP);   // El botón usa resistencia interna pull-up
  // Esto significa que el pin estará normalmente en estado ALTO (HIGH)
  // y pasará a BAJO (LOW) cuando se presione el botón.
}
// ----------------

void loop() {
  ButtonState = digitalRead(ButtonPin);   // Lee el estado del botón (HIGH o LOW)
  // Si el botón está presionado (LOW por el pull-up)
  if (ButtonState == LOW) {
   
    // Serie de notas que forman una pequeña melodía ascendente
    tone(BuzzerPin, 440);  // A4: 440 Hz
    delay(delayTime);      // Espera 500 ms

    tone(BuzzerPin, 494);  // B4: 494 Hz
    delay(delayTime);

    tone(BuzzerPin, 523);  // C5: 523 Hz
    delay(delayTime);

    tone(BuzzerPin, 587);  // D5: 587 Hz
    delay(delayTime);

    tone(BuzzerPin, 659);  // E5: 659 Hz
    delay(delayTime);

    // Se detiene el sonido por un momento
    noTone(BuzzerPin);
    delay(delayTime);

    // Serie de notas descendente
    tone(BuzzerPin, 659);  // E5
    delay(delayTime);

    tone(BuzzerPin, 587);  // D5
    delay(delayTime);

    tone(BuzzerPin, 523);  // C5
    delay(delayTime);

    tone(BuzzerPin, 494);  // B4
    delay(delayTime);

    tone(BuzzerPin, 440);  // A4
    delay(delayTime);
  }
  else {
    // Si el botón no está presionado, apaga el buzzer
    noTone(BuzzerPin);
  }
}