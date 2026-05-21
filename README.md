# 💊 DOSEGUARDIAN: INTELLIGENT PILL-TAKING ASSISTANT (LPC2129 / LPC2148)

## 📌 Project Overview

The **Medicine Reminder System** is an embedded application developed on the **ARM7 LPC2129 / LPC2148 microcontroller**.
It helps users remember their medicine schedule by providing **real-time alerts** using an **RTC, LCD, keypad, buzzer, and LED**.

At the scheduled time, the system:

* Displays medicine information on the LCD
* Activates a buzzer for alert
* Waits for user acknowledgment via a switch/keypad
* Indicates whether the medicine was **taken or missed**

This project demonstrates **real-time embedded programming**, **peripheral interfacing**, and **modular firmware design**.

---

## 🎯 Objectives

* Interface **RTC (Real Time Clock)** with ARM7 (LPC2129 / LPC2148)
* Implement **time-based event triggering**
* Use **LCD** for user interaction
* Use **keypad** for time editing
* Handle **buzzer & LED** alerts
* Build a **structured, modular embedded project**
* Follow **industry-standard coding practices**

---

## 🧠 System Features

✔ Real-time clock based reminder 

✔ User-editable medicine time

✔ Audible alert using buzzer

✔ Visual alert using LED

✔ LCD status messages

✔ Timeout detection for missed medicine

✔ Modular and reusable code structure

---

## 🧩 Hardware Components Used

* **Microcontroller**: LPC2129 / LPC2148 (ARM7)
* **RTC**: Internal RTC of LPC2129 / LPC2148
* **Display**: 16x2 Alphanumeric LCD
* **Input**: Matrix Keypad / Push Button
* **Output**: Buzzer & LED
* **Power Supply**: 5V DC

---

## 🧱 Software Architecture

The project follows a **layered and modular architecture**:

* **Hardware Abstraction Layer (HAL)**
  Handles direct GPIO and register access.

* **Driver Layer**
  LCD, Keypad, RTC, Delay drivers.

* **Application Layer**
  Medicine reminder logic and user interaction.

---

## 📂 Project Directory Structure

```
Medicine-Reminder-System/
│
├── Main.c                 # Main application logic
│
├── lcd.c                  # LCD driver implementation
├── lcd.h                  # LCD function declarations
├── lcd_defines.h          # LCD command and pin macros
│
├── keypad.c               # Keypad scanning logic
├── keypad.h               # Keypad function declarations
├── keypad_defines.h       # Keypad pin definitions
│
├── rtc.c                  # RTC configuration & read logic
├── rtc.h                  # RTC function declarations
├── rtc_defines.h          # RTC register macros
│
├── Time_edit.c            # Time editing logic using keypad
├── Time_edit.h            # Time editing declarations
│
├── delay.c                # Software delay routines
├── delay.h                # Delay function declarations
│
├── pin_defines.h          # GPIO pin mapping
├── defines.h              # Common macros
├── types.h                # User-defined data types
│
└── README.md              # Project documentation
```

---

## 📘 File Description (Detailed)

### 🔹 `Main.c`

* Entry point of the application
* Initializes all peripherals
* Continuously reads RTC time
* Compares current time with medicine time
* Controls buzzer, LED, and LCD messages

---

### 🔹 LCD Module (`lcd.c / lcd.h / lcd_defines.h`)

* Initializes LCD in 8-bit mode
* Sends commands and data
* Displays strings and numbers
* Shows reminder messages and status

---

### 🔹 Keypad Module (`keypad.c / keypad.h / keypad_defines.h`)

* Scans matrix keypad rows and columns
* Detects key presses
* Used for:

  * Time editing
  * User acknowledgment

---

### 🔹 RTC Module (`rtc.c / rtc.h / rtc_defines.h`)

* Configures LPC2129 / LPC2148 internal RTC
* Reads current hour, minute, second
* Maintains real-time clock operation

---

### 🔹 Time Edit Module (`Time_edit.c / Time_edit.h`)

* Allows user to modify reminder time
* Uses keypad input
* Displays editable fields on LCD
* Confirms and stores updated time

---

### 🔹 Delay Module (`delay.c / delay.h`)

* Provides millisecond and second delays
* Used for:

  * LCD timing
  * Buzzer timing
  * User message delays

---

### 🔹 Utility Headers

* **`types.h`** – Custom data types (`u8`, `u32`, etc.)
* **`defines.h`** – Bit macros and common utilities
* **`pin_defines.h`** – Centralized GPIO pin mapping

---

## 🔁 Program Flow

1. System Initialization
2. RTC Initialization
3. LCD Welcome Message
4. User sets medicine time
5. Continuous RTC monitoring
6. Time match detected
7. Buzzer & LCD alert activated
8. User acknowledgment check
9. Medicine taken or missed displayed
10. System returns to monitoring state

---

## ⚠️ Error & Timeout Handling

* If user does not respond within a fixed time:

  * LED turns ON
  * "Medicine Missed" message displayed
* Ensures safe and predictable behavior

---

## 🛠️ Tools & Environment

* **IDE**: Keil µVision
* **Language**: Embedded C
* **Controller**: ARM7 LPC2129 / LPC2148
* **Simulation**: Proteus (optional)
* **Compiler**: ARM-GCC / Keil ARMCC

---

## 📚 Learning Outcomes

* ARM7 GPIO programming
* RTC peripheral usage
* LCD & keypad interfacing
* Real-time event handling
* Modular embedded design
* Debugging embedded applications

---

## 🚀 Future Enhancements

* Multiple medicine schedules
* EEPROM storage for time
* GSM module for SMS alerts
* Low-power sleep mode
* Mobile app integration

---

## 👤 Author

**Sunkari Sudheer**
Embedded Systems Engineer (Fresher)

**Core Skills**

* Embedded C
* ARM7 (LPC2129 / LPC2148)
* Peripheral Interfacing
* Real-Time Embedded Systems

> “In embedded systems, software doesn’t just run — it interacts with the real world.”

