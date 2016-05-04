const int p13 = 13;
const int p12 = 12;
const int p11 = 11;
const int p10 = 10;

int a = 0;

void setup() {
  pinMode(p13, OUTPUT);
  pinMode(p12, OUTPUT);
  pinMode(p11, OUTPUT);
  pinMode(p10, OUTPUT);
  
  pinMode(A5, INPUT_PULLUP);
  
}

int readButton(int pin) {
  int b, c = 0;
  c=analogRead(pin);
  if (c>1000) {
    b = 0;
  }
  else if (c>723 && c<750) {
    b = 1;
  }
  else if (c>625 && c<655) {
    b = 2;
  } 
  else if (c>390 && c<420) {
    b = 3;
  }
  else if (c>235 && c<265) {
    b = 4;
  }
  else if (c<20) {
    b = 5;
  }
  return b;
}
// ----         -----
    |             |

    -----------------
            @

    
void loop() {
  a = readButton(5);
  if (a==1) {
    digitalWrite(p13, HIGH);
    delay(900);
    digitalWrite(p13, LOW);
  }
  else if (a==2) {
    digitalWrite(p12, HIGH);
    delay(900);
    digitalWrite(p12, LOW);
  }
  else if (a==3) {
    digitalWrite(p11, HIGH);
    delay(900);
    digitalWrite(p11, LOW);
  }
  else if (a==4) {
    digitalWrite(p10, HIGH);
    delay(900);
    digitalWrite(p10, LOW);
  }
}
