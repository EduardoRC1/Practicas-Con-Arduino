// Definimos Pines
#define Azul 3
#define Verde 5
#define Rojo 6
#define Boton1 2

// Definimos el estado del boton para cambio de color
int estado = 0;

void setup()
{
  // Establecemos entradas
  pinMode(Rojo, OUTPUT);
  pinMode(Verde, OUTPUT);
  pinMode(Azul, OUTPUT);
 
  pinMode(Boton1, INPUT_PULLUP); //Establecemos el boton como salida con resistencia interna
}

void loop()
{
    if (digitalRead(Boton1) == LOW)
    {
      estado = estado + 1;
      delay(400);
    }

    // Apagado
    if (estado == 0)
    {
      analogWrite(Azul, 0);
      analogWrite(Verde, 0);
      analogWrite(Rojo, 0);
    }

    // Blanco
    if (estado == 1)
    {
      analogWrite(Azul, 225);
      analogWrite(Verde, 225);
      analogWrite(Rojo, 225);
    }

    // Rojo
    if (estado == 2)
    {
      analogWrite(Azul, 0);
      analogWrite(Verde, 0);
      analogWrite(Rojo, 225);
    }

    // Verde
    if (estado == 3)
    {
      analogWrite(Azul, 0);
      analogWrite(Verde, 225);
      analogWrite(Rojo, 0);
    }

    // Azul
    if (estado == 4)
    {
      analogWrite(Azul, 225);
      analogWrite(Verde, 0);
      analogWrite(Rojo, 0);
    }
 
    // Reseteamos el estado a la quinta pulsacion
    if (estado == 5)
    {
      estado = 0;
    }
}