#include "drive.hpp"

volatile unsigned long DriveClass::leftMotorSensorTicks = 0;

volatile unsigned long DriveClass::rightMotorSensorTicks = 0;

void DriveClass::setup(int leftMotorDirectionPin, int leftMotorSpeedPin, int leftMotorSensorPin, int rightMotorDirectionPin, int rightMotorSpeedPin, int rightMotorSensorPin, int motorCycleTicks, int wheelDiameter) {
    // General
    this->motorCycleTicks = motorCycleTicks;
    this->wheelCircumferencePerTick = wheelDiameter * PI / this->motorCycleTicks;
    // Left motor
    this->leftMotorDirectionPin = leftMotorDirectionPin;
    pinMode(this->leftMotorDirectionPin, OUTPUT);
    this->leftMotorSpeedPin = leftMotorSpeedPin;
    pinMode(this->leftMotorSpeedPin, OUTPUT);
    this->leftMotorSensorPin = leftMotorSensorPin;
    pinMode(this->leftMotorSensorPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(this->leftMotorSensorPin), DriveClass::leftMotorSensorISR, FALLING);
    // Right motor
    this->rightMotorDirectionPin = rightMotorDirectionPin;
    pinMode(this->rightMotorDirectionPin, OUTPUT);
    this->rightMotorSpeedPin = rightMotorSpeedPin;
    pinMode(this->rightMotorSpeedPin, OUTPUT);
    this->rightMotorSensorPin = rightMotorSensorPin;
    pinMode(this->rightMotorSensorPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(this->rightMotorSensorPin), DriveClass::rightMotorSensorISR, FALLING);
}

void DriveClass::forward(int speed) {
    analogWrite(leftMotorSpeedPin, 255 - speed);
    analogWrite(rightMotorSpeedPin, 255 - speed);
    digitalWrite(leftMotorDirectionPin, HIGH);
    digitalWrite(rightMotorDirectionPin, HIGH);
}

void DriveClass::backward(int speed) {
    analogWrite(leftMotorSpeedPin, speed);
    analogWrite(rightMotorSpeedPin, speed);
    digitalWrite(leftMotorDirectionPin, LOW);
    digitalWrite(rightMotorDirectionPin, LOW);
}

void DriveClass::rotateLeft(int speed) {
    analogWrite(leftMotorSpeedPin, speed);
    analogWrite(rightMotorSpeedPin, 255 - speed);
    digitalWrite(leftMotorDirectionPin, LOW);
    digitalWrite(rightMotorDirectionPin, HIGH);
}

void DriveClass::rotateRight(int speed) {
    analogWrite(leftMotorSpeedPin, 255 - speed);
    analogWrite(rightMotorSpeedPin, speed);
    digitalWrite(leftMotorDirectionPin, HIGH);
    digitalWrite(rightMotorDirectionPin, LOW);
}

void DriveClass::stop() {
    digitalWrite(leftMotorSpeedPin, HIGH);
    digitalWrite(rightMotorSpeedPin, HIGH);
    digitalWrite(leftMotorDirectionPin, HIGH);
    digitalWrite(rightMotorDirectionPin, HIGH);
    this->resetDistance();
}

unsigned long DriveClass::getDistance() {
    return (DriveClass::leftMotorSensorTicks + DriveClass::rightMotorSensorTicks) / 2 * this->wheelCircumferencePerTick;
}

void DriveClass::resetDistance() {
    DriveClass::leftMotorSensorTicks = 0;
    DriveClass::rightMotorSensorTicks = 0;
}

static void DriveClass::leftMotorSensorISR() {
    noInterrupts(); // Disable interrupt support
    DriveClass::leftMotorSensorTicks++;
    interrupts(); // Enable interrupt support
}

static void DriveClass::rightMotorSensorISR() {
    noInterrupts(); // Disable interrupt support
    DriveClass::rightMotorSensorTicks++;
    interrupts(); // Enable interrupt support
}

// Creates an instance
DriveClass Drive;
