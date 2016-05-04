int p13 = 13;
int p12 = 12;
int p11 = 11;
int p10 = 10;

int AR = 0;
int TV = 1023;

void setup() {
  pinMode(p13, OUTPUT);
  pinMode(p12, OUTPUT);
  pinMode(p11, OUTPUT);
}

void loop() {
  
  AR = analogRead(A5);
  if ((AR != 1023) && (AR != TV)){
    digitalWrite(p13, LOW);
    digitalWrite(p12, LOW);
    digitalWrite(p11, LOW);
    TV = AR;
    
    if (TV > 468 && TV < 478){
       digitalWrite(p13, HIGH);
       digitalWrite(p12, HIGH);
       digitalWrite(p11, HIGH);
       delay(800);
       digitalWrite(p13, LOW);
       digitalWrite(p12, LOW);
       digitalWrite(p11, LOW);      
    
    } else if (TV > 350 && TV < 360){
      digitalWrite(p12, HIGH);
      digitalWrite(p10, HIGH);
      delay(800);
      digitalWrite(p12, LOW);
      digitalWrite(p10, LOW);
            
    } else if (TV > 234 && TV < 244){
      digitalWrite(p13, HIGH);
      digitalWrite(p11, HIGH);
      delay(800);
      digitalWrite(p13, LOW);
      digitalWrite(011, LOW);
      
    } else if (TV > 116 && TV < 121){
      digitalWrite(p11, HIGH);
      digitalWrite(p10, HIGH);
      delay(800);
      digitalWrite(p11, LOW);
            
    } else if (TV < 20){
      digitalWrite(p13,HIGH);
      digitalWrite(p12, HIGH);
      delay(800);
      digitalWrite(p13, LOW);
      digitalWrite(p12, LOW);
      }
    }
}
