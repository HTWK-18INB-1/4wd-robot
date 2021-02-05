#include "drive.hpp"

volatile int DriveClass::leftMotorSpeedPin;

volatile int DriveClass::rightMotorSpeedPin;

volatile int DriveClass::drivingDirection = DriveClass::DRIVING_STOP;

volatile int DriveClass::baseSpeed = 0;

volatile int DriveClass::dump[5];

volatile int DriveClass::leftMotorSensorTicks = 0;

volatile int DriveClass::rightMotorSensorTicks = 0;

void DriveClass::setup(int leftMotorDirectionPin, int leftMotorSpeedPin, int leftMotorSensorPin, int rightMotorDirectionPin, int rightMotorSpeedPin, int rightMotorSensorPin, int motorCycleTicks, int wheelDiameter) {
    // General
    this->motorCycleTicks = motorCycleTicks;
    this->wheelCircumferencePerTick = wheelDiameter * PI / this->motorCycleTicks;
    // Left motor
    this->leftMotorDirectionPin = leftMotorDirectionPin;
    pinMode(this->leftMotorDirectionPin, OUTPUT);
    DriveClass::leftMotorSpeedPin = leftMotorSpeedPin;
    pinMode(DriveClass::leftMotorSpeedPin, OUTPUT);
    this->leftMotorSensorPin = leftMotorSensorPin;
    pinMode(this->leftMotorSensorPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(this->leftMotorSensorPin), DriveClass::leftMotorSensorISR, FALLING);
    // Right motor
    this->rightMotorDirectionPin = rightMotorDirectionPin;
    pinMode(this->rightMotorDirectionPin, OUTPUT);
    DriveClass::rightMotorSpeedPin = rightMotorSpeedPin;
    pinMode(DriveClass::rightMotorSpeedPin, OUTPUT);
    this->rightMotorSensorPin = rightMotorSensorPin;
    pinMode(this->rightMotorSensorPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(this->rightMotorSensorPin), DriveClass::rightMotorSensorISR, FALLING);
}

void DriveClass::forward(int speed) {
    analogWrite(DriveClass::leftMotorSpeedPin, 255 - speed);
    analogWrite(DriveClass::rightMotorSpeedPin, 255 - speed);
    digitalWrite(leftMotorDirectionPin, HIGH);
    digitalWrite(rightMotorDirectionPin, HIGH);
    DriveClass::baseSpeed = speed;
    DriveClass::drivingDirection = DriveClass::DRIVING_FORWARD;
}

void DriveClass::backward(int speed) {
    analogWrite(DriveClass::leftMotorSpeedPin, speed);
    analogWrite(DriveClass::rightMotorSpeedPin, speed);
    digitalWrite(leftMotorDirectionPin, LOW);
    digitalWrite(rightMotorDirectionPin, LOW);
    DriveClass::baseSpeed = speed;
    DriveClass::drivingDirection = DriveClass::DRIVING_BACKWARD;
}

void DriveClass::rotateLeft(int speed) {
    analogWrite(DriveClass::leftMotorSpeedPin, speed);
    analogWrite(DriveClass::rightMotorSpeedPin, 255 - speed);
    digitalWrite(leftMotorDirectionPin, LOW);
    digitalWrite(rightMotorDirectionPin, HIGH);
    DriveClass::baseSpeed = speed;
    DriveClass::drivingDirection = DriveClass::DRIVING_ROTATION_LEFT;
;
}

void DriveClass::rotateRight(int speed) {
    analogWrite(DriveClass::leftMotorSpeedPin, 255 - speed);
    analogWrite(DriveClass::rightMotorSpeedPin, speed);
    digitalWrite(leftMotorDirectionPin, HIGH);
    digitalWrite(rightMotorDirectionPin, LOW);
    DriveClass::baseSpeed = speed;
    DriveClass::drivingDirection = DriveClass::DRIVING_ROTATION_RIGHT;
}

void DriveClass::stop() {
    digitalWrite(DriveClass::leftMotorSpeedPin, HIGH);
    digitalWrite(DriveClass::rightMotorSpeedPin, HIGH);
    digitalWrite(leftMotorDirectionPin, HIGH);
    digitalWrite(rightMotorDirectionPin, HIGH);
    DriveClass::baseSpeed = 0;
    DriveClass::drivingDirection = DRIVING_STOP;
    this->resetDistance();
}

unsigned long DriveClass::getDistance() {
    return (DriveClass::leftMotorSensorTicks + DriveClass::rightMotorSensorTicks) / 2 * this->wheelCircumferencePerTick;
}

void DriveClass::resetDistance() {
    DriveClass::leftMotorSensorTicks = 0;
    DriveClass::rightMotorSensorTicks = 0;
}

static void DriveClass::adjustSpeed() {
    // Calculating speed balance
    int balance = (DriveClass::leftMotorSensorTicks - DriveClass::rightMotorSensorTicks) * 20;
    DriveClass::dump[0] = balance;
    //if((balance > -2) && (balance < 2)) return;
    // Speed correction
    if (DriveClass::drivingDirection == DRIVING_FORWARD) {
        /*
        if (balance < 0) {
            analogWrite(DriveClass::leftMotorSpeedPin, 255 - DriveClass::baseSpeed);
            analogWrite(DriveClass::rightMotorSpeedPin, 255 - DriveClass::baseSpeed / 2);
        } else {
            analogWrite(DriveClass::leftMotorSpeedPin, 255 - DriveClass::baseSpeed / 2);
            analogWrite(DriveClass::rightMotorSpeedPin, 255 - DriveClass::baseSpeed);
        }
        */
        DriveClass::dump[1] = constrain(DriveClass::baseSpeed - balance, 0, 255);
        analogWrite(DriveClass::leftMotorSpeedPin, 255 - DriveClass::dump[1]);
        DriveClass::dump[2] = constrain(DriveClass::baseSpeed + balance, 0, 255);
        analogWrite(DriveClass::rightMotorSpeedPin, 255 - DriveClass::dump[2]);
    } else if (DriveClass::drivingDirection == DRIVING_BACKWARD) {
        DriveClass::dump[3] = constrain(DriveClass::baseSpeed + balance, 0, 255);
        analogWrite(DriveClass::leftMotorSpeedPin, DriveClass::dump[3]);
        DriveClass::dump[4] = constrain(DriveClass::baseSpeed - balance, 0, 255);
        analogWrite(DriveClass::rightMotorSpeedPin, DriveClass::dump[4]);
    }
}

static void DriveClass::leftMotorSensorISR() {
    // Disable interrupt support
    noInterrupts();
    // Detecting new ticks
    if (DriveClass::drivingDirection == DRIVING_FORWARD) {
        DriveClass::leftMotorSensorTicks++;
    } else if (DriveClass::drivingDirection == DRIVING_BACKWARD) {
        DriveClass::leftMotorSensorTicks--;
    }
    // Speed adjustment
    DriveClass::adjustSpeed();
    // Enable interrupt support
    interrupts();
}

static void DriveClass::rightMotorSensorISR() {
    // Disable interrupt suppor
    noInterrupts();
    // Detecting new ticks
    if (DriveClass::drivingDirection == DRIVING_FORWARD) {
        DriveClass::rightMotorSensorTicks++;
    } else if (DriveClass::drivingDirection == DRIVING_BACKWARD) {
        DriveClass::rightMotorSensorTicks--;
    }
    // Speed adjustment
    DriveClass::adjustSpeed();
    // Enable interrupt support
    interrupts();
}

// Creates an instance
DriveClass Drive;
