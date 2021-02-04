#include "sonar.hpp"

void Sonar::setup(int rotationPin, int triggerPin, int echoPin, int triggerWidth, int rotationMin, int rotationHalf, int rotationMax, int rotationDelay, int rotationDelayMax, int soundSpeed) {
    // Servo
    this->rotationPin = rotationPin;
    this->rotationMin = rotationMin;
    this->rotationHalf = rotationHalf;
    this->rotationMax = rotationMax;
    this->rotationDelay = rotationDelay;
    this->rotationDelayMax = rotationDelayMax;
    pinMode(this->rotationPin, OUTPUT);
    this->servo = Servo();
    this->servo.attach(this->rotationPin, this->rotationMin, this->rotationMax);
    this->rotate(90);
    // Sonar
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    this->triggerWidth = triggerWidth;
    this->soundSpeed = soundSpeed;
    pinMode(this->triggerPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
}

void Sonar::scan(int *distances) {
    // Scanning
    for (int i = 0; i <= 180; i++) {
        // Rotates sonar
        this->rotate(i);
        // Gets the distance
        distances[i] = this->getDistance();
    }
    // Returns
    return;
}

int Sonar::getDistance() {
    digitalWrite(this->triggerPin, HIGH);
    delayMicroseconds(this->triggerWidth);
    digitalWrite(this->triggerPin, LOW);
    return pulseIn(this->echoPin, HIGH) * this->soundSpeed / 2 / 1000;
}

void Sonar::rotate(int angle) {
    // Sets the new angle
    switch (angle) {
        case 0:
            this->servo.writeMicroseconds(this->rotationMin);
            break;
        case 1 ... 89:
            this->servo.writeMicroseconds((this->rotationHalf - this->rotationMin) / 90 * angle + this->rotationMin);
            break;
        case 90:
            this->servo.writeMicroseconds(this->rotationHalf);
            break;
        case 91 ... 179:
            this->servo.writeMicroseconds((this->rotationMax - this->rotationHalf) / 90 * (angle - 90) + this->rotationHalf);
            break;
        case 180:
            this->servo.writeMicroseconds(this->rotationMax);
            break;
    }
    // Waiting for the servo to be finish
    int servoDelay = abs(this->lastAngle - angle) * this->rotationDelay;
    if (servoDelay > this->rotationDelayMax) {
        servoDelay = this->rotationDelayMax;
    }
    delay(servoDelay);
    // Updates last angle
    this->lastAngle = angle;
    return;
}
