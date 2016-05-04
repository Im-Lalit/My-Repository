int p13 = 13;
int p12 = 12;
int p11 = 11;
int x = 0;
int currx = 1023;


void setup() {
  pinMode(p13, OUTPUT);
  pinMode(p12, OUTPUT);
  pinMode(p11, OUTPUT);
}

void loop() {
  
  x = analogRead(A0);
  if ((x != 1023) && (x != currx)){
    
    currx = x;
    
    if (currx > 644 && currx < 654){
    
       digitalWrite(p13, HIGH);
       delay(1000);
       digitalWrite(p13,LOW);
              
    
    } else if (currx > 427 && currx < 437){
      digitalWrite(p12, HIGH);
      delay(1000);
      digitalWrite(p12, LOW);
            
    } else if (currx > 214 && currx < 224 ){
    
      digitalWrite(p11, HIGH);
      delay(1000);
      digitalWrite(p11, LOW);
   
    }else if (currx <10){

      digitalWrite(p13, HIGH);
      delay(2000);
      digitalWrite(p13, LOW);
    }
  }
}
