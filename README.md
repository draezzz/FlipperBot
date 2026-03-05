<div align="center">
  <h1>🤖 Animo Labs Flipper Robot</h1>
  <p><i>Resident Maker Project | DLSU Science Foundation</i></p>
  <p>
    <img src="https://img.shields.io/badge/Platform-Arduino-00979D?style=flat&logo=arduino&logoColor=white" alt="Arduino">
    <img src="https://img.shields.io/badge/Hardware-nRF24L01-blue" alt="nRF24L01">
    <img src="https://img.shields.io/badge/Language-C++-00599C?style=flat&logo=c%2B%2B&logoColor=white" alt="C++">
  </p>
</div>

<hr />

<h2>✨ Project Overview</h2>
<p>
  This repository contains the firmware and control logic for a flipper robot developed during the Resident Maker Program at Animo Labs (DLSU Science Foundation). The robot utilizes an Arduino-based architecture to manage real-time inputs from a wireless controller and execute mechanical movements for competition. The project integrates wireless communication, dual-motor drive systems, and a servo-actuated "flippy" weapon mechanism.
</p>

<h3>🧠 Technical Highlights</h3>
<ul>
  <li><b>Wireless Communication:</b> Implemented 2.4GHz RF communication using <code>nRF24L01</code> modules. Developed a custom data structure (<code>JS_data</code>) to synchronize joystick axes and weapon triggers.</li>
  <li><b>Locomotion & Control:</b> Integrated the <code>TB6612FNG</code> motor driver with differential steering logic. Features a "Sumo Mode" for enhanced dual-motor synchronization.</li>
  <li><b>Weapon Mechanism:</b> Programmed a servo-actuated "flippy" weapon with mapped positions from 0° (rest) to 120° (flip) for offensive maneuvers.</li>
  <li><b>Failsafe Systems:</b> Built a software-level watchdog that halts all motor activity (<code>sumoControl(0, 0)</code>) if the radio signal is lost for more than 500ms.</li>
</ul>

<h2>🛠 Hardware Configuration</h2>
<table>
  <tr>
    <th>Component</th>
    <th>Specification</th>
  </tr>
  <tr>
    <td><b>Microcontroller</b></td>
    <td>Arduino (Uno/Nano Compatible)</td>
  </tr>
  <tr>
    <td><b>Radio Module</b></td>
    <td>nRF24L01 (SPI Interface)</td>
  </tr>
  <tr>
    <td><b>Motor Driver</b></td>
    <td>TB6612FNG_XCR</td>
  </tr>
  <tr>
    <td><b>Actuators</b></td>
    <td>Dual DC Motors + High-Torque Servo</td>
  </tr>
</table>

<h2>🚀 Firmware Structure</h2>
<ul>
  <li><code>transmit.ino</code>: Handheld controller logic with joystick mapping and RF transmission.</li>
  <li><code>receiver.ino</code>: Robot-side logic handling motor control and weapon actuation.</li>
  <li><code>flippyOnly.ino</code>: Standalone weapon calibration and servo testing script.</li>
</ul>

<h2>⚙️ Setup & Installation</h2>

<h3>1. Required Libraries</h3>
<p>Ensure you have the following libraries installed in your <b>Arduino IDE</b> before compiling:</p>
<ul>
  <li><code>RF24</code> (by TMRh20)</li>
  <li><code>Servo</code> (Built-in)</li>
  <li><code>TB6612FNG_XCR</code></li>
</ul>

<h3>2. Hardware Wiring</h3>
<p>The system is split into two units: the <b>Transmitter (Controller)</b> and the <b>Receiver (Robot)</b>.</p>
<ul>
  <li><b>Radio Pins:</b> CE and CSN pins are set to <b>9</b> and <b>8</b> respectively.</li>
  <li><b>Weapon Servo:</b> Connected to pin <b>7</b> on the Controller or pin <b>0</b> on the Robot.</li>
  <li><b>Motor Driver:</b> Standby Pin must be set to <b>A3</b>.</li>
</ul>

<h3>3. Deployment</h3>
<ul>
  <li>Flash <code>transmit1.ino</code> to the handheld controller.</li>
  <li>Flash <code>receiver1.ino</code> to the robot chassis.</li>
</ul>

<h2>👥 Contributors</h2>
<ul>
  <li><b>Iain Draezen Sy Guillermo</b>
    <br /><i>BS/MS Computer Science, De La Salle University</i>
  </li>
</ul>

<hr />
<div align="center">
  <p><small>Developed during the Resident Maker Program at Animo Labs.</small></p>
</div>
