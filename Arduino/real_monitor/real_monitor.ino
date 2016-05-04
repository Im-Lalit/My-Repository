/*
  The circuit:
 * RX is digital 1st pin to TX
 * TX is digital 2nd pin to RX
*/
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
int pin13 = 13;

void setup() {
  pinMode(pin13,OUTPUT);
  Serial.begin(115200);
  mySerial.begin(115200);
  
  while (!Serial) {
      Serial.println("Connecting to ESP8266");
  }
  
  Serial.println("ESP8266 connected");
}

void loop() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
