const int LBpin = 2;
const int RBpin = 3;
const int BBpin = 4;
const int RNBpin = 5;
const int UBpin = 6;

int BTN = 0;

const int UPR =  12;
const int UPL =  11;
const int FRT =  10;

void setup() {
  pinMode(UPR, OUTPUT);
  pinMode(UPL, OUTPUT);
  pinMode(FRT, OUTPUT);
  
  pinMode(LBpin, OUTPUT);
  pinMode(RBpin, OUTPUT);
  pinMode(BBpin, OUTPUT);
  pinMode(RNBpin, OUTPUT);
  pinMode(UBpin, OUTPUT);
  
  pinMode(BTN, INPUT);
}

void loop() {
  BTN = digitalRead(LBpin);
  BTN = digitalRead(RBpin);
  BTN = digitalRead(BBpin);
  BTN = digitalRead(RNBpin);
  BTN = digitalRead(UBpin);
  
  if (BTN == HIGH) {
    digitalWrite(UPR, HIGH);
    delay(500);
  }
  else {
    digitalWrite(UPR, LOW);
  }
}
