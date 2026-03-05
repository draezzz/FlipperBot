#include "TB6612FNG_XCR.h"
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <Servo.h>

// the servo object
Servo flippy;

// pin number
const int servoPin = 0;

// position of the flippy (in degrees)
const int restPos = 0;
const int flipPos = 30;

int pos = 0;

struct JS_data {
  int js1;
  int js2;
  int flipBtn;
};
JS_data data;

RF24 radio(9, 8); 
const byte address[6] = "00001";

TB6612FNG_XCR leftMotor;
TB6612FNG_XCR rightMotor;

unsigned long lastRecvTime = 0;
const unsigned long TIMEOUT = 500; // 0.5 seconds failsafe

void setup() {
  Serial.begin(9600);
  
  flippy.attach(servoPin);
  flippy.write(pos);

  // Initialize Radio
  if (!radio.begin()) {
    Serial.println("Radio hardware not found!");
    while (1);
  }
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();

  // Initialize Motors
  pinMode(A3, OUTPUT); // Ensure Standby Pin is Output
  digitalWrite(A3, HIGH); // Take driver out of standby
  
  leftMotor.attach(2, 3, 4, "Left");
  rightMotor.attach(5, 6, 7, "Right");
  leftMotor.setStandbyPin(A3);
  rightMotor.setStandbyPin(A3);
  
  // Using Sumo Mode (Ensure library handles dual control)
  leftMotor.enableSumoMode(&leftMotor, &rightMotor);
  rightMotor.enableSumoMode(&leftMotor, &rightMotor);

  Serial.println("Receiver Initialized.");
}

void loop() {
  if (radio.available()) {
    radio.read(&data, sizeof(JS_data));
    lastRecvTime = millis(); // Update timer whenever data arrives

    int leftSpeed = data.js1 + data.js2;   // Forward + Turn
    int rightSpeed = data.js1 - data.js2;  // Forward - Turn

    // Constrain to valid range (-255 to 255)
    leftSpeed = constrain(leftSpeed, -255, 255);
    rightSpeed = constrain(rightSpeed, -255, 255);
    
    // Pass joystick values directly to the control function
    leftMotor.sumoControl(leftSpeed, rightSpeed);

    if (data.flipBtn == 1) {
      woohoo();
    }
    
    Serial.print("J1: "); Serial.print(data.js1);
    Serial.print(" | J2: "); Serial.println(data.js2);
  }

  // FAILSAFE: If no signal for 500ms, stop the robot
  if (millis() - lastRecvTime > TIMEOUT) {
    leftMotor.sumoControl(0, 0);
    // Serial.println("LOST SIGNAL - STOPPING");
  }
}

// flip code
void woohoo() {
  flippy.write(flipPos);  // flip
  delay(1000);            // wait for a second before retracting
  flippy.write(restPos);  // retract
  delay(500);
}
