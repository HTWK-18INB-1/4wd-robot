#include "sonar.hpp"

void Sonar::setup(int rotationPin, int triggerPin, int echoPin, int rotationSpeed, int soundSpeed) {
    this->rotationPin = rotationPin;
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    this->rotationSpeed = rotationSpeed;
    this->soundSpeed = soundSpeed;
    pinMode(this->rotationPin, OUTPUT);
    pinMode(this->triggerPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
    this->rotation = Servo();
    this->rotation.attach(this->rotationPin);
}

void Sonar::scan() {
    for (int i = 160; i >= 20; i=i-10) {
        this->rotation.write(i);
        this->getDistance();
        if (i == 160) {
            delay(this->rotationSpeed * 140);
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
