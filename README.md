# Dynamic Street Lighting System (IoT) 
**Finalist Project - Startup India Punjab Yatra 2019**

## Project Overview
The **Dynamic Street Lighting System** is an Arduino-based smart infrastructure solution designed to optimize energy consumption in semi-urban areas and small towns. In many regions, street lights remain at full brightness throughout the night despite zero traffic, leading to massive electricity waste.

This project solves this by using **Ultrasonic Sensors** to detect vehicle presence and **PWM (Pulse Width Modulation)** to dynamically adjust LED intensity.

### Key Achievement
* **Finalist:** This project was selected as a finalist at the **Startup India Punjab Yatra 2019**, recognized for its potential impact on smart city infrastructure in Punjab.

---

## Official Recognition
To validate the project's success and participation in the finals, the official certificate is included below:

![Startup India Certificate](./assets/certificate.jpg)
*Note: The original physical prototype and video documentation were lost; this repository serves as a technical reconstruction for portfolio purposes.*

---

## Technical Logic & Hardware
The system utilizes a "Detection-Trigger" logic to balance safety and savings.

### Circuit Diagram


### Component List:
* **Microcontroller:** Arduino Uno
* **Sensor:** HC-SR04 Ultrasonic Sensor (Detection range set to 50cm - 2m for prototype)
* **Light Source:** High-Intensity LEDs
* **Control:** PWM-capable Digital Pins

### State Logic:
| Traffic Activity | Light Intensity | PWM Duty Cycle | Purpose |
| :--- | :--- | :--- | :--- |
| **No Activity** | 20% | 51/255 | Minimum visibility & Power saving |
| **Vehicle Detected** | 80% | 204/255 | Full visibility for road safety |

---

## Code Snippet (Reconstructed)
The core logic uses the `pulseIn()` function to calculate distance and `analogWrite()` to handle the dimming effect.

```cpp
// Defining PWM Pin for LED
const int ledPin = 6; 
// Logic: If distance < 50cm, set brightness to 80% (204), else 20% (51)
if (distance > 0 && distance < 50) {
    analogWrite(ledPin, 204); // 80% Brightness
} else {
    analogWrite(ledPin, 51);  // 20% Brightness
}
