//Practica 14 - Intensidad de Led con Potenciometro
const int potPin = A0;   // Pin analógico donde está conectado el potenciómetro
const int led = 9;       // Pin PWM para el LED
int valorPot = 0;        // Variable para guardar el valor leído del potenciómetro
int brillo = 0;          // Variable para el valor de brillo (0-255)

void setup()
{
  pinMode(led, OUTPUT);      // Configura el pin del LED como salida
  Serial.begin(9600);        // Inicia comunicación serial a 9600 baudios
}

void loop()
{
  valorPot = analogRead(potPin);          // Lee el valor del potenciómetro (0-1023)
  brillo = map(valorPot, 0, 1023, 0, 255); // Convierte el rango de 0-1023 a 0-255
  /*
    ¿Por qué convertir 0–1023 a 0–255?
    El potenciómetro da valores de 0 a 1023 (analogRead), pero analogWrite solo acepta valores de 0 a 255.
    Usamos map() para "traducir" de un rango a otro y que el LED responda correctamente al movimiento del potenciómetro.

    Ejemplo de valores de analogWrite(pin, valor):
     
0 → siempre apagado (0% ciclo de trabajo).
     
127 → encendido la mitad del tiempo (~50% de brillo en un LED).
     
255 → siempre encendido (100%).
  */
  analogWrite(led, brillo);  // Ajusta el brillo del LED según el valor calculado

  // Muestra en el monitor serial los valores
  Serial.print("Valor potenciómetro: ");
  Serial.print(valorPot);
  Serial.print("  --> Brillo LED: ");
  Serial.println(brillo);

  delay(50); // Pausa para estabilidad en la lectura
}