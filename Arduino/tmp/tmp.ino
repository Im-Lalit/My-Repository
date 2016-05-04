#include<stdlib.h>
#include <SoftwareSerial.h>
SoftwareSerial esp(5, 6); // RX, TX
int pin_4 = 4, pin_5 = 2, pin_6 = 3, pin_7 = 7, pin_8 = 8, pin_9 = 9, pin_10 = 10, pin_11 = 11, pin_12 = 12, pin_13 = 13;

void Communicate(){
  Serial.println("comuni");
  for(;;){
    if (esp.available()) {
      Serial.write(esp.read());
    }
    
    if (Serial.available()) {
      esp.write(Serial.read());
      if(Serial.find("Exit")){
        break;
      }
    }
  }
}
void ESP_Setup(){         //Serial brgin 115200 bps 
  esp.begin(115200);
  Serial.begin(115200);
  }
void pin_Setup(){         //Setup pin
  pinMode(pin_4,OUTPUT);
  pinMode(pin_5,OUTPUT);
  pinMode(pin_6,OUTPUT);
  pinMode(pin_7,OUTPUT);
  pinMode(pin_8,OUTPUT);
  pinMode(pin_9,OUTPUT);
  pinMode(pin_10,OUTPUT);
  pinMode(pin_11,OUTPUT);
  pinMode(pin_12,OUTPUT);
  pinMode(pin_13,OUTPUT);
}
void ESP_Check(){         //Checking device is plug or not
  Serial.println("Detecting---ESP8266");
  for(int a=0;a<15;a++){
    esp.println("AT");
    digitalWrite(pin_13, HIGH);
    delay(50);
    digitalWrite(pin_13, LOW);
    delay(50);
    
    if(esp.find("OK")){
      Serial.println("Detected ESP8266...");
      digitalWrite(pin_13, HIGH);
      delay(2000);
      digitalWrite(pin_13, LOW);
      ESP_TCP_Server();
      break;
    }
    if(a==14){
      Serial.println("plug your ESP8266 Module RX to pin-3 and TX to pin-2");
      digitalWrite(pin_13, HIGH);
    }
  }
}
void ESP_TCP_Server(){    //creating a TCP server
  Serial.println("Creating TCP Server Wait...");
  esp.println("AT+CWMODE=2");
  delay(500);
  esp.println("AT+CIPMUX=1");
  delay(500);
  esp.println("AT+CIPSERVER=1,36");
  delay(1000);
  Serial.println("TCP Server Create.");
}
void ESP_Receive(){       //Receiving bytes from client
  if(esp.find("+IPD,0,5:113")){digitalWrite(pin_13,HIGH);}
  else if(esp.find("+IPD,0,5:013")){digitalWrite(pin_13,LOW);}
  else if(esp.find("+IPD,0,5:112")){digitalWrite(pin_12,HIGH);}
  else if(esp.find("+IPD,0,5:012")){digitalWrite(pin_12,LOW);}
  
  else if(esp.find("+IPD,0,5:111")){digitalWrite(pin_11,LOW);}
  else if(esp.find("+IPD,0,5:011")){digitalWrite(pin_11,HIGH);}
  
  else if(esp.find("+IPD,0,5:110")){digitalWrite(pin_10,LOW);}
  else if(esp.find("+IPD,0,5:010")){digitalWrite(pin_10,LOW);}
  
  else if(esp.find("+IPD,0,4:19")){digitalWrite(pin_9,HIGH);}
  else if(esp.find("+IPD,0,4:09")){digitalWrite(pin_9,LOW);}
}


void setup()
{
  pin_Setup();
  ESP_Setup();
  ESP_Check();
}

void loop(){
  if (esp.available()) {
    Serial.write(esp.read());
    //if(esp.find("Com")){Communicate();}
    /*else if(esp.find("lll")){digitalWrite(pin_13,LOW);}
    else if(esp.find("on")){digitalWrite(pin_13,HIGH);}
    else if(esp.find("off")){digitalWrite(pin_13,LOW);}*/
  }
  
  if (Serial.available()) {
    esp.write(Serial.read());
  }
}
