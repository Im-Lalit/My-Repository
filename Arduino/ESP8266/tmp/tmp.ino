char ByteReceived[5];
int led_13=13;

void setup()
{
  pinMode(led_13,OUTPUT);
  Serial.begin(9600); 
}

class str{
    public:
    str(){}
    str(char a){
      
      }
  };

void loop() 
{
  //Serial.print("---\n");
  if (Serial.available()>0)
  {
    ByteReceived[5]='0','0','0','0','0';
    ByteReceived[5] = Serial.read();

    /*switch(ByteReceived[5]){
      case 'a':
        digitalWrite(led_13,HIGH);
        break;

      case 'o':
        digitalWrite(led_13,LOW);
        break;
      }*/
      
     if(ByteReceived[5]=='o')
    {
      digitalWrite(led_13,HIGH);
    }
   
    else if(ByteReceived[5] == 'f')
    {
      digitalWrite(led_13,LOW);
    }
  }
}
