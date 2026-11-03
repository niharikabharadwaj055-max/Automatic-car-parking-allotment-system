
# 🚗 Automatic Car Parking Allotment System Using Arduino Uno

## 📌 Project Overview

The **Automatic Car Parking Allotment System** is an Arduino-based smart parking solution designed to automate vehicle entry, parking slot allotment, and exit management.

The system uses IR sensors to detect vehicles at the entrance and exit, a servo motor to control the parking gate, and an I2C LCD display to show parking availability.

The system manages four parking slots and automatically updates the number of available spaces. If all parking slots are occupied, the system displays a parking-full message and prevents additional vehicles from entering.

This project demonstrates the practical implementation of embedded systems, automation, sensor interfacing, and microcontroller-based control systems.

## 🎯 Objectives

- To automate the vehicle parking allotment process.
- To detect vehicle entry and exit using IR sensors.
- To control the parking gate using a servo motor.
- To display available parking slots using an LCD.
- To prevent vehicle entry when all parking slots are occupied.
- To reduce manual intervention in parking management.

## 🛠️ Components Required

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| IR Sensors | 2 |
| I2C LCD Display (16×2) | 1 |
| Servo Motor (SG90) | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |
| Power Supply | 1 |

## 🔌 Hardware Connections

### 1. IR Sensor Connections

| IR Sensor | Arduino Uno |
|---|---|
| Entry Sensor OUT | Digital Pin 2 |
| Exit Sensor OUT | Digital Pin 3 |
| VCC | 5V |
| GND | GND |

### 2. Servo Motor Connections

| Servo Wire | Arduino Uno |
|---|---|
| Signal (Orange/Yellow) | Digital Pin 9 |
| VCC (Red) | 5V |
| GND (Brown/Black) | GND |

### 3. I2C LCD Connections

| LCD Pin | Arduino Uno |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

## ⚙️ Working Principle

The system operates using two IR sensors, a servo motor, and an LCD display.

### 1. Vehicle Entry Detection
- The entry IR sensor detects an incoming vehicle.
- Arduino checks the availability of parking slots.
- If a slot is available, the servo motor opens the parking gate.
- The vehicle is allowed to enter.
- The available parking count is updated.

### 2. Parking Slot Management
- The system maintains a total capacity of four parking slots.
- The LCD continuously displays the available parking spaces.
- The number of available slots decreases when a vehicle enters.

### 3. Parking Full Detection
- When all four parking slots are occupied, the available count becomes zero.
- The LCD displays **"PARKING FULL"**.
- The entry gate remains closed to prevent additional vehicles from entering.

### 4. Vehicle Exit Detection
- The exit IR sensor detects an outgoing vehicle.
- The Arduino updates the parking availability.
- The servo motor controls the exit gate.
- The available parking count increases after the vehicle leaves.

## 🔄 System Workflow

1. Initialize Arduino Uno, IR sensors, LCD, and servo motor.
2. Display the total available parking slots.
3. Monitor the entry and exit sensors.
4. Detect an incoming vehicle.
5. Check whether parking space is available.
6. Open the gate if a parking slot is available.
7. Update the parking count.
8. Display the updated availability.
9. Detect outgoing vehicles and restore available slots.
10. Repeat the process continuously.

## 🚦 System Logic

| Condition | System Action |
|---|---|
| Vehicle detected at entry and slots available | Open entry gate |
| Vehicle detected at entry and no slots available | Display PARKING FULL |
| Vehicle exits | Update available slots |
| Parking slots available | Display available count |
| All four slots occupied | Display 0 available slots |

## 💻 Technologies Used

- **Programming Language:** Embedded C / Arduino C++
- **Microcontroller:** Arduino Uno
- **IDE:** Arduino IDE
- **Sensors:** Infrared (IR) Sensors
- **Display:** 16×2 I2C LCD
- **Actuator:** Servo Motor
- **Communication:** I2C Protocol

## 🏗️ System Architecture

```text
       ENTRY IR SENSOR
              |
              v
       +--------------+
       |              |
       |  ARDUINO UNO |
       |              |
       +--------------+
          |        |
          |        |
          v        v
      SERVO       I2C LCD
      MOTOR       DISPLAY
     (Gate)      (Slots)

          ^
          |
     EXIT IR SENSOR
```

## 📚 Applications

- Shopping mall parking facilities.
- College and university parking areas.
- Office parking management.
- Residential parking systems.
- Small-scale automated parking facilities.

## 🚀 Future Enhancements

- Add individual sensors for each parking slot.
- Integrate RFID-based vehicle identification.
- Develop a mobile application for parking availability.
- Implement IoT-based remote monitoring.
- Add automatic parking fee calculation.
- Implement vehicle counting and real-time monitoring.

## 🎓 Learning Outcomes

Through this project, we gained practical knowledge of:

- Arduino Uno programming.
- IR sensor interfacing and vehicle detection.
- Servo motor control.
- I2C LCD interfacing.
- Embedded system design.
- Automation and parking management logic.
- Hardware integration and troubleshooting.

## 👩‍💻 Project Information

**Project Name:** Automatic Car Parking Allotment System

**Domain:** Robotics and Embedded Systems

**Platform:** Arduino Uno

**Project Type:** Hardware-Based Mini Project

**Parking Capacity:** 4
