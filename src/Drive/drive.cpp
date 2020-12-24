#include "drive.hpp"

DriveClass Drive;

int DriveClass::leftMotorsDirectionPin = 0;
int DriveClass::leftMotorsSpeedPin = 0;
int DriveClass::rightMotorsDirectionPin = 0;
int DriveClass::rightMotorsSpeedPin = 0;

int DriveClass::frontLeftMotorSensorPin = 0;
int DriveClass::frontRightMotorSensorPin = 0;
int DriveClass::backLeftMotorSensorPin = 0;
int DriveClass::backRightMotorSensorPin = 0;

int DriveClass::motorSensorFullRotationSteps = 0;

volatile int DriveClass::currentFrontLeftSensorSteps = 0;
volatile int DriveClass::currentFrontRightSensorSteps = 0;
volatile int DriveClass::currentBackLeftSensorSteps = 0;
volatile int DriveClass::currentBackRightSensorSteps = 0;

volatile unsigned long DriveClass::lastFrontLeftRotations = 0;
volatile unsigned long DriveClass::lastFrontRightRotations = 0;
volatile unsigned long DriveClass::lastBackLeftRotations = 0;
volatile unsigned long DriveClass::lastBackRightRotations = 0;

void DriveClass::setup(int leftMotorsDirectionPin, int leftMotorsSpeedPin, int rightMotorsDirectionPin, int rightMotorsSpeedPin, int frontLeftMotorSensorPin, int frontRightMotorSensorPin, int backLeftMotorSensorPin, int backRightMotorSensorPin, int motorSensorFullRotationSteps) {
    // Motor controls
    DriveClass::leftMotorsDirectionPin = leftMotorsDirectionPin;
    DriveClass::leftMotorsSpeedPin = leftMotorsSpeedPin;
    DriveClass::rightMotorsDirectionPin = rightMotorsDirectionPin;
    DriveClass::rightMotorsSpeedPin = rightMotorsSpeedPin;
    // Motor sensors
    DriveClass::frontLeftMotorSensorPin = frontLeftMotorSensorPin;
    attachInterrupt(digitalPinToInterrupt(frontLeftMotorSensorPin), frontLeftMotorSensorISR, RISING);
    DriveClass::frontRightMotorSensorPin = frontRightMotorSensorPin;
    attachInterrupt(digitalPinToInterrupt(frontRightMotorSensorPin), frontRightMotorSensorISR, RISING);
    DriveClass::backLeftMotorSensorPin = backLeftMotorSensorPin;
    attachInterrupt(digitalPinToInterrupt(backLeftMotorSensorPin), backLeftMotorSensorISR, RISING);
    DriveClass::backRightMotorSensorPin = backRightMotorSensorPin;
    attachInterrupt(digitalPinToInterrupt(backRightMotorSensorPin), backRightMotorSensorISR, RISING);
    DriveClass::motorSensorFullRotationSteps = motorSensorFullRotationSteps;
}

void DriveClass::forward(int speed) {
    analogWrite(leftMotorsSpeedPin, 255 - speed);
    analogWrite(rightMotorsSpeedPin, 255 - speed);
    digitalWrite(leftMotorsDirectionPin, HIGH);
    digitalWrite(rightMotorsDirectionPin, HIGH);
}

void DriveClass::forwardLeft(int speed) {
    analogWrite(leftMotorsSpeedPin, 255 - speed / 2);
    analogWrite(rightMotorsSpeedPin, 255 - speed);
    digitalWrite(leftMotorsDirectionPin, HIGH);
    digitalWrite(rightMotorsDirectionPin, HIGH);
}

void DriveClass::forwardRight(int speed) {
    analogWrite(leftMotorsSpeedPin, 255 - speed);
    analogWrite(rightMotorsSpeedPin, 255 - speed / 2);
    digitalWrite(leftMotorsDirectionPin, HIGH);
    digitalWrite(rightMotorsDirectionPin, HIGH);
}

void DriveClass::backward(int speed) {
    analogWrite(leftMotorsSpeedPin, speed);
    analogWrite(rightMotorsSpeedPin, speed);
    digitalWrite(leftMotorsDirectionPin, LOW);
    digitalWrite(rightMotorsDirectionPin, LOW);
}

void DriveClass::backwardLeft(int speed) {
    analogWrite(leftMotorsSpeedPin, speed / 2);
    analogWrite(rightMotorsSpeedPin, speed);
    digitalWrite(leftMotorsDirectionPin, LOW);
    digitalWrite(rightMotorsDirectionPin, LOW);
}

void DriveClass::backwardRight(int speed) {
    analogWrite(leftMotorsSpeedPin, speed);
    analogWrite(rightMotorsSpeedPin, speed / 2);
    digitalWrite(leftMotorsDirectionPin, LOW);
    digitalWrite(rightMotorsDirectionPin, LOW);
}

void DriveClass::test() {
    forward(255);
    delay(500);
    forwardLeft(255);
    delay(500);
    forwardRight(255);
    delay(500);
    backward(255);
    delay(500);
    backwardLeft(255);
    delay(500);
    backwardRight(255);
    delay(500);
}

unsigned long DriveClass::getLastRotations() {
    return ((lastFrontLeftRotations + lastBackLeftRotations) / 2 + (lastFrontRightRotations + lastBackRightRotations) / 2) / 2;
}

void DriveClass::clearLastRotations() {
    lastFrontLeftRotations = 0;
    lastFrontRightRotations = 0;
    lastBackLeftRotations = 0;
    lastBackRightRotations = 0;
}

void DriveClass::frontLeftMotorSensorISR() {
    if (currentFrontLeftSensorSteps >= motorSensorFullRotationSteps) {
        lastFrontLeftRotations++;
        currentFrontLeftSensorSteps = 0;
    }
    currentFrontLeftSensorSteps++;
}

void DriveClass::frontRightMotorSensorISR() {
    if (currentFrontRightSensorSteps >= motorSensorFullRotationSteps) {
        lastFrontRightRotations++;
        currentFrontRightSensorSteps = 0;
    }
    currentFrontRightSensorSteps++;
}

void DriveClass::backLeftMotorSensorISR() {
    if (currentBackLeftSensorSteps >= motorSensorFullRotationSteps) {
        lastBackLeftRotations++;
        currentBackLeftSensorSteps = 0;
    }
    currentBackLeftSensorSteps++;
}

void DriveClass::backRightMotorSensorISR() {
    if (currentBackRightSensorSteps >= motorSensorFullRotationSteps) {
        lastBackRightRotations++;
        currentBackRightSensorSteps = 0;
    }
    currentBackRightSensorSteps++;
}
