#include <LiquidCrystal.h>
 LiquidCrystal lcd(13, 12, 11, 10,9, 8);

float sensorValue1 = 0;
float sensorValue2 = 0;
float voltageValue = 0;
float currentValue = 0;
float Power_now = 0, Power_anc=0, Current_anc =0,Voltage_anc=0, deltaI=0, deltaV=0 ; 
float delta = 1.4;                 
float pwm = 128;                        
void setup() 
{
  pinMode(6, OUTPUT);
  lcd.begin(16, 2);
}

void loop() 
{
  sensorValue1 = analogRead(A0);
  sensorValue2 = analogRead(A1);
  voltageValue= (sensorValue1 * 5.0 /1023.0) *5;
  currentValue= (sensorValue2 * 5.0 /1023.0);
  lcd.setCursor(0, 0);
  Power_now = voltageValue * currentValue;
  
  lcd.print("Ppv=");
  lcd.print(Power_now);
  lcd.print("W");  
  lcd.setCursor(0, 1);
  lcd.print("V=");
  lcd.print(voltageValue);
  lcd.print("V I=");
  lcd.print(currentValue);
  lcd.print("A");
  deltaI= currentValue-Current_anc;
  deltaV= voltageValue-Voltage_anc;
 if(deltaV==0)
  { if(deltaI==0)
     {// nothing to do
     }
   else 
    { if(deltaI>0)
       pwm=pwm-delta;
     else
       pwm=pwm+delta;
    }
  }
 else
  { if((voltageValue*deltaI)+(currentValue*deltaV)==0)
     {// nothing to do
     }
  
    else
     { if((deltaI/deltaV)+(currentValue/voltageValue)>0)
        
         pwm=pwm-delta;  
    
      else
        pwm=pwm+delta;
     
     }
  }
      
Voltage_anc= voltageValue;
Current_anc= currentValue;
Power_anc=Power_now;
if(pwm > 240)
   pwm=240;
if (pwm < 15)
   pwm=15;
 analogWrite(6, pwm);
}
