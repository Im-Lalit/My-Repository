int pin_13=13;
int incB = 0;
void setup() {
  Serial.begin(9600);
  pinMode(pin_13,OUTPUT);
}

void loop() {
  Serial.read();
  Serial.println("AT");
  if(Serial.available()>0){
      incB = Serial.read();
      Serial.println(incB,DEC);
    }
    delay(10000);
}
