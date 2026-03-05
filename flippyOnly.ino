#include <Servo.h>

// the servo object
Servo flippy;

// pin number
const int servoPin = 7;
const int buttonPin = A3;    // change to where the button is pinned

// position of the flippy (in degrees)
const int restPos = 0;
const int flipPos = 120;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  flippy.attach(servoPin);
  flippy.write(pos);

  pinMode(buttonPin, INPUT_PULLUP);   // reads HIGH when open, LOW when pressed
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // if pressed then flip
  if (digitalRead(buttonPin) == LOW) {
     Serial.print("Sent -> flip: ");
     Serial.print(digitalRead(buttonPin) == LOW);
     Serial.print("\n");
     woohoo();
  }
}

// flip code
void woohoo() {
  flippy.write(flipPos);  // flip
  delay(1000);            // wait for a second before retracting
  flippy.write(restPos);  // retract
  delay(500);
}
