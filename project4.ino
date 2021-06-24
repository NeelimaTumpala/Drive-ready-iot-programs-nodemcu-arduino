int button=A0;
// include the library code:
#include <LiquidCrystal.h>



// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



void setup() {
// set up the LCD's number of columns and rows:
lcd.begin(16, 2);



lcd.print("hello");
delay(1000);
}



void loop() {



for (int positionCounter = 0; positionCounter < 11; positionCounter++) {
// scroll one position left:
lcd.scrollDisplayRight();
// wait a bit:
delay(50);
}
lcd.setCursor(0,0);
for (int positionCounter = 0; positionCounter < 11; positionCounter++) {
// scroll one position left:
lcd.scrollDisplayLeft();
// wait a bit:
delay(50);
}
lcd.setCursor(0,0);






}
