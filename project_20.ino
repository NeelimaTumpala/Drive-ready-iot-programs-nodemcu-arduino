void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  
  // put your setup code here, to run once:


}

void loop() {
  char a = Serial.read();
  if(a=='1')

  {
    digitalWrite(9,1);
    digitalWrite(10,0);
    Serial.println(a);
  }
  if(a=='2')

  {
    digitalWrite(9,0);
    digitalWrite(10,1);
    Serial.println(a);
  }
  if(a=='0')

  {
    digitalWrite(9,0);
    digitalWrite(10,0);
    Serial.println(a);
  }
  
  // put your main code here, to run repeatedly:


}
