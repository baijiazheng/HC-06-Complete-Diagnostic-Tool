# HC-06 Complete Diagnostic Tool

> An embedded diagnostic and testing tool for the HC-06 Bluetooth module.

## 📖 Project Overview

**HC-06 Complete Diagnostic Tool** is an embedded development project created to diagnose and test an HC-06 Bluetooth module.

The project focuses on:

- HC-06 module testing
- Serial communication testing
- Embedded-system debugging
- Hardware/software fault isolation
- PlatformIO project organization

The purpose of this project is to turn HC-06 troubleshooting into a structured and repeatable diagnostic process.

---

## 🎯 Project Goals

The main goals of this project are:

1. Verify the basic communication state of the HC-06.
2. Test serial communication between the MCU and HC-06.
3. Provide a simple diagnostic environment for troubleshooting.
4. Separate hardware, communication, and software problems during debugging.
5. Build an independent embedded debugging project.

---

## 🧰 Development Environment

### Software

- VS Code
- PlatformIO
- C/C++

### Module

- HC-06 Bluetooth module

---

## 🔍 Diagnostic Philosophy

The diagnostic process follows a layered approach:

```text
Power
  ↓
Hardware
  ↓
Serial Interface
  ↓
HC-06
  ↓
Communication
  ↓
Software
```

When a communication problem occurs, the first step is to determine **which layer is actually failing**.

This avoids immediately changing software when the real problem may be located in the hardware or communication path.

---

## 🧪 Main Learning Topics

This project was used to practice:

### Serial Communication

Understanding how embedded devices exchange data through a serial interface.

### Embedded Debugging

Using controlled tests to isolate the source of a problem instead of modifying multiple variables at the same time.

### PlatformIO

Using PlatformIO to organize, build, test, and manage an embedded C/C++ project.

### Hardware / Software Isolation

Learning to distinguish between:

```text
Hardware Fault
Communication Fault
Software Fault
```

before attempting a fix.

---

## 🧠 Engineering Lessons

The most important lesson from this project is:

> **Do not assume that a software problem is caused by software.**

A reliable debugging process should move from the physical layer toward the software layer:

```text
Physical Layer
      ↓
Electrical Signal
      ↓
Communication Interface
      ↓
Module
      ↓
Firmware
```

This methodology later became useful in more complex robotics projects.

---

## 🚀 Possible Future Improvements

Future versions may include:

- Automatic HC-06 detection
- Communication-status detection
- Baud-rate testing
- Automated diagnostic sequences
- More detailed error classification
- Serial-monitor integration
- Test-result logging

---

## 📌 Project Status

**Status: Completed**

This project is maintained as an embedded-system diagnostic experiment and as part of the author's robotics and embedded-development portfolio.

---

## 👤 Author

**JB**

Robotics / Embedded Systems / Control

GitHub: `baijiazheng`
