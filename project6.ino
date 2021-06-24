const int trig=11;
const int echo=10;
void setup() {
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
}

void loop() {
// Mega hertz singal
//hear the signal
// calclutaing the time
//v = d/t
//calculate d
digitalWrite(trig,0);
delayMicroseconds(2);// |--------|
digitalWrite(trig,1); // | |
delayMicroseconds(10); // 0.5 Mhz into time = 2 micro senconds See------------------- -------------------------ob
digitalWrite(trig,0);
float duration= pulseIn(echo,1);
// v= 325 m/s v * 10 ^-5 = 0.00325 =0.325 /2;
//v=d/t; v= d/2 / t
float distance = 0.325*0.5 ;
distance =distance*(duration*0.1);
Serial.println(distance);
Serial.println(" CM");
delay(1000);

}
