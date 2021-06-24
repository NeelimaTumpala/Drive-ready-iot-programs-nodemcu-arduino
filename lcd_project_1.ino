const int trig=11;
const int echo=10;


void setup()
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  
}

void loop()
{
  //Mega hertz signal
  //hear the signal
  //calculating the time
  //v=d/t
  //caculate d
  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);
  delayMicroseconds(10);
  //0.5 Mhz into time = 2 micro seconds
  digitalWrite(trig,0);
  float duration = pulseIn(echo,1);
  //v= 325m/s    v*10^(-5)   =0.00325 =.325ss
  //v=d/t;
  float distance = .325*.5;
  distance= distance*(distance*0.1);
  Serial.println(distance);
  Serial.println(" CM");
  delay(1000);  
}
