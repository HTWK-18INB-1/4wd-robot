#include "drive.hpp"

void Drive::setup(int leftMotorsForwardPin, int leftMotorsBackwardPin, int leftMotorsSpeedPin, int rightMotorsForwardPin, int rightMotorsBackwardPin, int rightMotorsSpeedPin) {
    // Left motor controls
    this->leftMotorsForwardPin = leftMotorsForwardPin;
    pinMode(leftMotorsForwardPin, OUTPUT);
    this->leftMotorsBackwardPin = leftMotorsBackwardPin;
    pinMode(leftMotorsBackwardPin, OUTPUT);
    this->leftMotorsSpeedPin = leftMotorsSpeedPin;
    pinMode(leftMotorsSpeedPin, OUTPUT);
    // Right motor controls
    this->rightMotorsForwardPin = rightMotorsForwardPin;
    pinMode(rightMotorsForwardPin, OUTPUT);
    this->rightMotorsBackwardPin = rightMotorsBackwardPin;
    pinMode(rightMotorsBackwardPin, OUTPUT);
    this->rightMotorsSpeedPin = rightMotorsSpeedPin;
    pinMode(rightMotorsSpeedPin, OUTPUT);
}

void Drive::forward(int speed) {
    // Left motors
    digitalWrite(leftMotorsForwardPin, HIGH);
    digitalWrite(leftMotorsBackwardPin, LOW);
    analogWrite(leftMotorsSpeedPin, speed);
    // Right motors
    digitalWrite(rightMotorsForwardPin, HIGH);
    digitalWrite(rightMotorsBackwardPin, LOW);
    analogWrite(rightMotorsSpeedPin, speed);
}

void Drive::backward(int speed) {
    // Left motors
    digitalWrite(leftMotorsForwardPin, LOW);
    digitalWrite(leftMotorsBackwardPin, HIGH);
    analogWrite(leftMotorsSpeedPin, speed);
    // Right motors
    digitalWrite(rightMotorsForwardPin, LOW);
    digitalWrite(rightMotorsBackwardPin, HIGH);
    analogWrite(rightMotorsSpeedPin, speed);
}

void Drive::rotateLeft(int speed) {
    // Left motors
    digitalWrite(leftMotorsForwardPin, LOW);
    digitalWrite(leftMotorsBackwardPin, HIGH);
    analogWrite(leftMotorsSpeedPin, speed);
    // Right motors
    digitalWrite(rightMotorsForwardPin, HIGH);
    digitalWrite(rightMotorsBackwardPin, LOW);
    analogWrite(rightMotorsSpeedPin, speed);
}

void Drive::rotateRight(int speed) {
    // Left motors
    digitalWrite(leftMotorsForwardPin, HIGH);
    digitalWrite(leftMotorsBackwardPin, LOW);
    analogWrite(leftMotorsSpeedPin, speed);
    // Right motors
    digitalWrite(rightMotorsForwardPin, LOW);
    digitalWrite(rightMotorsBackwardPin, HIGH);
    analogWrite(rightMotorsSpeedPin, speed);
}

void Drive::stop() {
    // Left motors
    digitalWrite(leftMotorsForwardPin, LOW);
    digitalWrite(leftMotorsBackwardPin, LOW);
    analogWrite(leftMotorsSpeedPin, 0);
    // Right motors
    digitalWrite(rightMotorsForwardPin, LOW);
    digitalWrite(rightMotorsBackwardPin, LOW);
    analogWrite(rightMotorsSpeedPin, 0);
}
