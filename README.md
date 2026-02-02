# Wireless Dual Motor Control using NodeMCU & Blynk IoT

This project demonstrates wireless control of two DC motors using the NodeMCU ESP8266 and the Blynk IoT platform. Motor speed and direction can be controlled remotely through a smartphone over Wi-Fi.

---

##  Features
- Wireless motor control via Wi-Fi  
- Independent speed control for two DC motors  
- Direction control using on-screen buttons  
- Real-time control using Blynk mobile app  
- Simple and low-cost IoT implementation  

---

## Components & Tools Used
- NodeMCU ESP8266 Wi-Fi Board  
- L298N Motor Driver Module  
- 2 × DC Motors  
- 9V Battery  
- Jumper Wires (M-M, F-M, F-F)  
- Blynk App (Virtual Pins V1, V2, Buttons)  
- Arduino IDE  

---

##  Working Principle

### 1. NodeMCU ESP8266
**Function:**  
Acts as the central microcontroller with built-in Wi-Fi connectivity.

**Working:**  
- Connects to the local Wi-Fi network using credentials  
- Communicates with the Blynk cloud server  
- Receives motor control commands via virtual pins V1 and V2  
- Sends digital control signals to the L298N motor driver through pins D1–D4  
- Generates PWM signals on pins D5–D6 for motor speed control  

---

### 2. L298N Motor Driver Module
**Function:**  
Controls motor direction and power using an H-bridge circuit.

**Working:**  
- Receives logic signals from NodeMCU (IN1–IN4)  
- Amplifies low-power control signals to drive motors  
- Controls motor direction by switching current polarity  
- Supports up to 2A per motor  
- Motor connections:  
  - Motor 1 → OUT1 & OUT2  
  - Motor 2 → OUT3 & OUT4  

---

### 3. DC Motors
**Function:**  
Convert electrical energy into mechanical motion.

**Working:**  
- Rotate when power is applied  
- Direction depends on input polarity  
- Speed varies based on PWM signal  
- Powered through the L298N motor driver  

---

### 4. 9V Battery
**Function:**  
Supplies power to the motors.

**Working:**  
- Provides required voltage and current  
- Connected to the L298N power input  
- Separate from NodeMCU power to reduce noise  

---

### 5. Blynk App Control Setup
- Slider (V1): Motor 1 speed control (0–255)  
- Slider (V2): Motor 2 speed control (0–255)  
- Buttons: Direction control using digital pins D2, D4, D12, D13  
- Project linked using Blynk Auth Token and Template ID  

---

## Applications
- IoT-based robotic vehicles  
- Wireless motor control systems  
- Smart automation projects  
- Educational IoT demonstrations  

---

## Conclusion
This project provides an efficient and beginner-friendly approach to controlling DC motors wirelessly using IoT. It is suitable for learning embedded systems, Wi-Fi communication, and real-time motor control.

---

## Author
@sousheelt
