# ITI_PROJECT_ROBOTIC_ARM
We built a robotic arm from scratch and developed the system drive code using an embedded system based on AVR.
DOF Robotic Arm with Gripper

An embedded systems project featuring a 3-degree-of-freedom robotic arm with gripper, built around the ATmega32 microcontroller. The system enables precise control of each joint using a 4×4 keypad interface, with real-time visual feedback provided on a 16×2 LCD display.

Features

Multi-Joint Control: Independent control of 3 arm joints plus gripper operation

Dual Control Modes:

180° precision positioning (MG90S servo)

Continuous rotation control (MG995 servo)

Stepper motor precision movement (28BYJ-48)

Intuitive Interface: 4×4 keypad for controlling each motor with dedicated CW/CCW buttons

Real-Time Feedback: LCD (16×2) displays current motor status and rotation direction

Precise Actuation: ULN2003 motor drivers for reliable stepper motor control

Modular Design: Well-structured firmware architecture for maintainability and expansion

Hardware Components

Microcontroller: ATmega32

Servo Motors:

MG90S Micro Servo (180° rotation)

MG995 Servo Motor (360° continuous rotation)

Stepper Motors: 2× 28BYJ-48 with ULN2003 drivers

User Interface: 16×2 LCD, 4×4 Keypad

Power: Separate regulated power supplies for MCU and motors

Control Scheme

The 4×4 keypad provides dedicated control for each motor:

Two switches per motor for clockwise and counter-clockwise rotation

Real-time LCD display shows which motor is active and its rotation direction

Intuitive layout for precise manipulation of the robotic arm

Software Architecture

The firmware is organized into layered architecture:

LIB: Bit-math operations and standard data types

MCAL (Microcontroller Abstraction Layer): Direct hardware drivers (DIO, Timer, LCD, Keypad)

HAL (Hardware Abstraction Layer): Device drivers (Servo, Stepper)

Application Layer: Main control logic and user interface management

Getting Started
Prerequisites

Compiler: AVR-GCC

Programmer: USBasp, AVRISP, or compatible

Simulation (optional): Proteus, SimulIDE
