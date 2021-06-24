#include<Keypad.h>
//13,12,11,10 as row pins
//9,8,7,6 as col pins
//rs-5, e-4, d4,d5,d6,d7- 3,2,1,0
#include<LiquidCrystal.h>
char action;
const byte rows=4;
const byte cols=4;



char keys[rows][cols]={{'7','8','9','/'},
{'4','5','6','x'},
{'1','2','3','-'},
{'c','0','=','+'}};



byte rp[rows]={13,12,11,10};
byte cp[cols]={9,8,7,6};
Keypad prasad=Keypad(makeKeymap(keys),rp,cp,rows,cols);
LiquidCrystal screen(5,4,3,2,1,0);



long Num1,Num2,Num;
char key;
char op;
bool calc=false;
void setup()
{
screen.begin(16,2);
screen.print("Calculator");
delay(2000);
screen.clear();
}



void loop()
{
key=prasad.getKey();



if(key!=NO_KEY)
{
screen.setCursor(0,0);
screen.print(key);
CHECK_BUTTONS();


}
if(calc==true)
{
result();
}
disp();
}



void disp()
{

screen.setCursor(0,1);
screen.print(Num1);
screen.print(action);
screen.print(Num2);
if(calc==true)
{
screen.setCursor(9,1);
screen.print(Num);
}
}



void result()
{
if(action=='+')
Num=Num1+Num2;
if(action=='-')
Num=Num1-Num2;
if(action=='*')
Num=Num1*Num2;
if(action=='/')
Num=Num1+Num2;




}



void CHECK_BUTTONS()
{
screen.clear();

if(key=='1')
{

if(Num==0)
Num=1;
else
Num=(Num*10)+1;

}
if(key=='2')
{

if(Num==0)
Num=2;
else
Num=(Num*10)+2;

}

if(key=='3')
{

if(Num==0)
Num=3;
else
Num=(Num*10)+3;

}
if(key=='4')
{

if(Num==0)
Num=4;
else
Num=(Num*10)+4;

}
if(key=='5')
{

if(Num==0)
Num=5;
else
Num=(Num*10)+5;

}
if(key=='6')
{

if(Num==0)
Num=6;
else
Num=(Num*10)+6;

}
if(key=='7')
{

if(Num==0)
Num=7;
else
Num=(Num*10)+7;

}
if(key=='8')
{

if(Num==0)
Num=8;
else
Num=(Num*10)+8;

}
if(key=='9')
{

if(Num==0)
Num=9;
else
Num=(Num*10)+9;

}
if(key=='0')
{

if(Num==0)
Num=0;
else
Num=(Num*10)+0;

}



if(key=='c')
{
Num=Num1=Num2=0;
calc=false;
}
if(key=='=')
{

Num2=Num;

calc=true;
}



if(key=='+')
{
Num1=Num;
Num=0;
action='+';
}



if(key=='-')
{
Num1=Num;
Num=0;
action='-';
}



if(key=='x')
{
Num1=Num;
Num=0;
action='*';
}



if(key=='/')
{
Num1=Num;
Num=0;
action='/';
}



}
