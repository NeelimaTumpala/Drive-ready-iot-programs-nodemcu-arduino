
int ledPin1 = 7; // choose the pin for the LED
int inPin1 = 13;   // choose the input pin (for a pushbutton)
int val1 = 0;     // variable for reading the pin status

int ledPin2 = 6; // choose the pin for the LED
int inPin2 = 12;   // choose the input pin (for a pushbutton)
int val2 = 0;     // variable for reading the pin status

int ledPin3 = 5; // choose the pin for the LED
int inPin3 = 11;   // choose the input pin (for a pushbutton)
int val3 = 0;     // variable for reading the pin status

int ledPin4 = 4; // choose the pin for the LED
int inPin4 = 10;   // choose the input pin (for a pushbutton)
int val4 = 0;     // variable for reading the pin status

int ledPin5 = 3; // choose the pin for the LED
int inPin5 = 9;   // choose the input pin (for a pushbutton)
int val5 = 0;     // variable for reading the pin status

int ledPin6 = 2; // choose the pin for the LED
int inPin6 = 8;   // choose the input pin (for a pushbutton)
int val6 = 0;     // variable for reading the pin status

void setup() {
  pinMode(ledPin1, OUTPUT);  // declare LED as output
  pinMode(inPin1, INPUT);    // declare pushbutton as input

  pinMode(ledPin2, OUTPUT);  // declare LED as output
  pinMode(inPin2, INPUT);    // declare pushbutton as input

  pinMode(ledPin3, OUTPUT);  // declare LED as output
  pinMode(inPin3, INPUT);    // declare pushbutton as input

  pinMode(ledPin4, OUTPUT);  // declare LED as output
  pinMode(inPin4, INPUT);    // declare pushbutton as input

  pinMode(ledPin5, OUTPUT);  // declare LED as output
  pinMode(inPin5, INPUT);    // declare pushbutton as input

  pinMode(ledPin6, OUTPUT);  // declare LED as output
  pinMode(inPin6, INPUT);    // declare pushbutton as input
}

void loop(){
  val1 = digitalRead(inPin1);  // read input value
  if (val1 == HIGH) {         // check if the input is HIGH (button released)
    digitalWrite(ledPin1, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin1, HIGH);  // turn LED ON
  }

  val2 = digitalRead(inPin2);  // read input value
  if (val2 == HIGH) {         // check if the input is HIGH (button released)
    digitalWrite(ledPin2, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin2, HIGH);  // turn LED ON
  }

   val3 = digitalRead(inPin3);  // read input value
  if (val3 == HIGH) {         // check if the input is HIGH (button released)
    digitalWrite(ledPin3, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin3, HIGH);  // turn LED ON
  }

   val4 = digitalRead(inPin4);  // read input value
  if (val4 == HIGH) {         // check if the input is HIGH (button released)
    digitalWrite(ledPin4, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin4, HIGH);  // turn LED ON
  }

   val5 = digitalRead(inPin5);  // read input value
  if (val5 == HIGH) {         // check if the input is HIGH (button released)
    digitalWrite(ledPin5, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin5, HIGH);  // turn LED ON
  }

   val6 = digitalRead(inPin6);  // read input value
  if (val6 == HIGH) {         // check if the input is HIGH (button released)
    digitalWrite(ledPin6, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin6, HIGH);  // turn LED ON
  }
}
 
