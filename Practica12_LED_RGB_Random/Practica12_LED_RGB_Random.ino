// Definimos las variables y su pin
#define vBlue 3
#define vGreen 5
#define vRed 6

void setup()
{
  // Declaramos los pines del led como salidas.
  pinMode(vRed, OUTPUT);
  pinMode(vGreen, OUTPUT);
  pinMode(vBlue, OUTPUT);
}

void loop()
{
  

// Almacenamos en variables de forma aleatoria un valor de intensidad para cada pin
  int vBlueValue = random(1, 255); 
  int vRedValue = random(1, 255);
  int vGreenValue = random(1, 255);
 
  // Encendemos el Led con los valores de intensidad almacenados en las vairables semillas.  
  analogWrite(vBlue, vBlueValue);
  analogWrite(vRed, vRedValue);
  analogWrite(vGreen, vGreenValue);
   
  delay(400); // Declaramos un tiempo de reaccion de 400ms
}