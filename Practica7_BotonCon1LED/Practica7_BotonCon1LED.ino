void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(3) == HIGH){
      digitalWrite(2, HIGH);
    }else{
      digitalWrite(2, LOW);
    }
}
