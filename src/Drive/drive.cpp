#include "drive.hpp"

void Drive::setup(int leftMotorsDirectionPin, int leftMotorsSpeedPin, int rightMotorsDirectionPin, int rightMotorsSpeedPin) {
    // Left motor controls
    this->leftMotorsDirectionPin = leftMotorsDirectionPin;
    pinMode(leftMotorsDirectionPin, OUTPUT);
    this->leftMotorsSpeedPin = leftMotorsSpeedPin;
    pinMode(leftMotorsSpeedPin, OUTPUT);
    // Right motor controls
    this->rightMotorsDirectionPin = rightMotorsDirectionPin;
    pinMode(rightMotorsDirectionPin, OUTPUT);
    this->rightMotorsSpeedPin = rightMotorsSpeedPin;
    pinMode(rightMotorsSpeedPin, OUTPUT);
}

void Drive::forward(int speed) {
    analogWrite(leftMotorsSpeedPin, 255 - speed);
    analogWrite(rightMotorsSpeedPin, 255 - speed);
    digitalWrite(leftMotorsDirectionPin, HIGH);
    digitalWrite(rightMotorsDirectionPin, HIGH);
}

void Drive::backward(int speed) {
    analogWrite(leftMotorsSpeedPin, speed);
    analogWrite(rightMotorsSpeedPin, speed);
    digitalWrite(leftMotorsDirectionPin, LOW);
    digitalWrite(rightMotorsDirectionPin, LOW);
}

void Drive::rotateLeft(int speed) {
    analogWrite(leftMotorsSpeedPin, speed);
    analogWrite(rightMotorsSpeedPin, 255 - speed);
    digitalWrite(leftMotorsDirectionPin, LOW);
    digitalWrite(rightMotorsDirectionPin, HIGH);
}

void Drive::rotateRight(int speed) {
    analogWrite(leftMotorsSpeedPin, 255 - speed);
    analogWrite(rightMotorsSpeedPin, speed);
    digitalWrite(leftMotorsDirectionPin, HIGH);
    digitalWrite(rightMotorsDirectionPin, LOW);
}

void Drive::stop() {
    digitalWrite(leftMotorsSpeedPin, HIGH);
    digitalWrite(rightMotorsSpeedPin, HIGH);
    digitalWrite(leftMotorsDirectionPin, HIGH);
    digitalWrite(rightMotorsDirectionPin, HIGH);
}
