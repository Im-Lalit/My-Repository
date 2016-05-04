String ByteReceived;
int led_1 = 12;
int led_2 = 13;
int led_3 = 11;
int dly = 100;

void setup()
{
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
  pinMode(led_3,OUTPUT);
  Serial.begin(115200); 
}

void loop()
{
  if (Serial.available() > 0)
  {
    ByteReceived = Serial.read();
        
    if(strcmp(ByteReceived)=='a')
    {
      for(int i=0;i<2;i++){
        digitalWrite(led_1,HIGH);
        delay(dly);
        digitalWrite(led_1,LOW);
        delay(dly);
        
        digitalWrite(led_2,HIGH);
        delay(dly);
        digitalWrite(led_2,LOW);
        delay(dly);

        digitalWrite(led_3,HIGH);
        delay(dly);
        digitalWrite(led_3,LOW);
        delay(dly);
        
        Serial.print("AT");
        }
    }
    
    if(ByteReceived == '0,CLOSED')
    {
      digitalWrite(led_1,LOW);
      Serial.print(" LED OFF");
    }
    
    Serial.println();    // End the line

  // END Serial Available
  }
}

//--(end main loop )---

/*-----( Declare User-written Functions )-----*/

/*********( THE END )***********/

