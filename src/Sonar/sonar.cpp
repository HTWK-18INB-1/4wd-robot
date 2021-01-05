#include "sonar.hpp"

void Sonar::setup(int rotationPin, int triggerPin, int echoPin, int rotationSpeed, int rotationMin, int rotationMax, int soundSpeed) {
    this->rotationPin = rotationPin;
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    this->rotationSpeed = rotationSpeed;
    this->rotationMin = rotationMin;
    this->rotationMax = rotationMax;
    this->soundSpeed = soundSpeed;
    pinMode(this->rotationPin, OUTPUT);
    pinMode(this->triggerPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
    this->rotation = Servo();
    this->rotation.attach(this->rotationPin, this->rotationMin, this->rotationMax);
    this->rotation.write(90);
}

void Sonar::scan() {
    for (int i = 180; i >= 0; i=i-10) {
        this->rotation.write(i);
        this->getDistance();
        if (i == 180) {
            delay(this->rotationSpeed * 180);
        } else {
            delay(this->rotationSpeed);
        }
    }
}

int Sonar::getDistance() {
    digitalWrite (this->triggerPin, HIGH);
    delayMicroseconds(10); // Minimum pulse width
    digitalWrite (this->triggerPin, LOW);
    return pulseIn(this->echoPin, HIGH) * this->soundSpeed / 2000;
}
