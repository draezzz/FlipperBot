<h1 align="center">🤖 Animo Labs Flipper Robot</h1>

## ✨ About the Project
This repository contains the firmware and control logic for a flipper robot developed during the Resident Maker Program at Animo Labs (DLSU Science Foundation). The robot utilizes an **Arduino-based** architecture to manage real-time inputs from a wireless controller and execute mechanical movements for competition. The project integrates wireless communication, dual-motor drive systems, and a servo-actuated "flippy" weapon mechanism.

## 🪄 Installation
**1. Repository Structure**
  a. transmit.ino: Final firmware for the handheld controller
  b. receiver.ino: Final firmware for the robot's onboard system
  c. transmitterMotorOnly.ino / receiverMotorOnly.ino: Debugging scripts for verifying radio link stability
  d. flippyOnly.ino: Standalone test script for weapon calibration

**2. Setup**
  a. Libraries: Ensure you have RF24, Servo, and the TB6612FNG_XCR libraries installed in your Arduino IDE
  b. Wiring: Radio CE/CSN pins are set to 9 and 8
    - Weapon Servo is connected to pin 7 (Controller) or pin 0 (Robot)
    - Motor Standby Pin must be set to A3
  c. Upload: Flash the transmit1.ino to the controller and receiver1.ino to the robot

## 🤓 Contributors
- **Iain Guillermo (iain_draezen_guillermo@dlsu.edu.ph)**

This project was conducted during the Resident Maker Program at Animo Labs.
