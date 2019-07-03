 #include <Morse.h>

 Morse morse(13);
 
void setup()
{
  Serial.begin(9600);
}


char morse2[][4] = {
    {'*', '-', '?', '?'}, //A
    {'-', '*', '*', '*'}, //B
    {'-', '*', '-', '*'}, //C
    {'-', '*', '*', '?'}, //D
    {'*', '?', '?', '?'}, //E
    {'*', '*', '-', '*'}, //F
    {'-', '-', '*', '?'}, //G
    {'*', '*', '*', '*'}, //H
    {'*', '*', '?', '?'}, //I
    {'*', '-', '-', '-'}, //J
    {'-', '*', '-', '?'}, //K
    {'*', '-', '*', '*'}, //L
    {'-', '-', '?', '?'}, //M
    {'-', '.', '?', '?'}, //N
    {'-', '-', '-', '?'}, //O
    {'*', '-', '-', '*'}, //P
    {'-', '-', '*', '-'}, //Q
    {'*', '-', '*', '?'}, //R
    {'*', '*', '*', '?'}, //S
    {'-', '?', '?', '?'}, //T
    {'*', '*', '-', '?'}, //U
    {'*', '*', '*', '-'}, //V
    {'.', '-', '-', '?'}, //W
    {'-', '*', '*', '-'}, //X
    {'-', '*', '-', '-'}, //Y
    {'-', '-', '*', '*'}  //Z
  };
  
void loop()
{
  int i,n=0,j,t,m;
  String morse="";
  String morse1="";
  while(Serial.available()>0)
  {

    morse+= char(Serial.read());
    n++;
    
  }

for(i=0;i<n;i++)
  {
  for(j=0;j<4;j++)
  {
    if(morse[i]>=97&&morse[i]<=122)
    {
      t=morse[i]-97;
      morse1=morse2[t][j];
    }
  }
  morse1+=' ';
  }

  Serial.println(morse1);
  for(i=0;morse1[i]!='\0';i++)
  {
    if(morse1[i]=='*')
    morse.dot();
    else if(morse1[i]=='-')
    morse.dash();
    else if(morse1[i]==' ')
    morse.w_space();
    else if(morse1[i]!='?')
    morse.c_space();
  }
  
  delay(10);
}
