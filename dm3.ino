void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}
int income=0;
void loop()
{
  if(Serial.available()>0)
  {
    income=Serial.read();
    switch(income)
    {
      case 'f':
      forward();
      break;
      case 'b':
      backward();
      break;
      case 'l':
      left();
      break;
      case 'r':
      right();
      break;
      default:
      break;
    }
  }
       
}
void forward()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
while(1)
  {
  digitalWrite(4,HIGH);
  delay(100);
  digitalWrite(4,LOW);
  delay(100);
  if(Serial.available()>0)
    break;
  }
  
}
void backward()
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  while(1)
  {
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);
    delay(100);
  if(Serial.available()>0)
    break;
  }
}
void left()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
while(1)
  {
  digitalWrite(2,HIGH);
  delay(100);
  digitalWrite(2,LOW);
  delay(100);
  if(Serial.available()>0)
    break;
  }
}
void right()
{
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
while(1)
  {
  digitalWrite(11,HIGH);
  delay(100);
  digitalWrite(11,LOW);
  delay(100);
  if(Serial.available()>0)
    break;
  }
}