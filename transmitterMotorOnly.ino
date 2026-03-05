#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Create an RF24 object
RF24 radio(9, 8);  // CE, CSN
const byte address[6] = "00001";

// Define the structure clearly
struct JS_data {
  int js1;
  int js2;
};
JS_data data;

const int js1Pin = A0;
const int js2Pin = A2;

void setup() {
  Serial.begin(9600);
  
  if (!radio.begin()) {
    Serial.println("Radio hardware not responding!");
    while (1); // Halt if radio is not connected properly
  }

  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW); // Use LOW if testing on a desk to avoid saturation
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
  
  Serial.println("Transmitter Initialized");
}

void loop() {
  // 1. Read raw values
  int raw1 = analogRead(js1Pin);
  int raw2 = analogRead(js2Pin);

  // 2. Map values to motor speeds
  // Note: Ensure your receiver handles negative values for reverse
  data.js1 = map(raw1, 0, 1023, -100, 100);
  data.js2 = map(raw2, 0, 1023, 100, -100);

  // 3. Send data
  bool success = radio.write(&data, sizeof(JS_data));

  if (success) {
    Serial.print("Sent -> J1: ");
    Serial.print(data.js1);
    Serial.print(" J2: ");
    Serial.println(data.js2);
  } else {
    Serial.println("Transmission failed - Check power/wiring");
  }

  delay(50); // Small delay to stabilize transmission
}
