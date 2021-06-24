int led =13;
int pir=8;
void setup() {
pinMode(led,OUTPUT);
pinMode(pir,INPUT);
// put your setup code here, to run once:



}



void loop() {
int data=digitalRead(pir);
if(data==1)
{
digitalWrite(led,1);
}



if(data==0)
{
digitalWrite(led,0);

}
// put your main code here, to run repeatedly:



}
