void setup()
  pinMode(A5,INPUT_PULLUP);
}

int readButtons(int pin)
{
  int b,c = 0;
  c=analogRead(pin);
  if (c>1000)
  {
    b=0;
  }
  else
  if (c>440 && c<470)
  {
    b=1;
  }
  else
  if (c<400 && c>370)
  {
    b=2;
  }
  else
  if (c>150 && c<180)
  {
    b=4;
  }
  else
  if (c<20)
  {
    b=5;
  }
  return b;
}

