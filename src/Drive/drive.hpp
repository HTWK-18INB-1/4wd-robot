#include <Arduino.h>

class DriveClass {
    public:
        static void setup(int leftMotorsDirectionPin, int leftMotorsSpeedPin, int rightMotorsDirectionPin, int rightMotorsSpeedPin, int frontLeftMotorSensorPin, int frontRightMotorSensorPin, int backLeftMotorSensorPin, int backRightMotorSensorPin, int motorSensorFullRotationSteps);
        static void forward(int speed);
        static void forwardLeft(int speed);
        static void forwardRight(int speed);
        static void backward(int speed);
        static void backwardLeft(int speed);
        static void backwardRight(int speed);
        static void test();
        static void frontLeftMotorSensorISR();
        static void frontRightMotorSensorISR();
        static void backLeftMotorSensorISR();
        static void backRightMotorSensorISR();
        static unsigned long getLastRotations();
        static void clearLastRotations();
    private:
        static int leftMotorsDirectionPin, leftMotorsSpeedPin, rightMotorsDirectionPin, rightMotorsSpeedPin;
        static int frontLeftMotorSensorPin, frontRightMotorSensorPin, backLeftMotorSensorPin, backRightMotorSensorPin;
        static int motorSensorFullRotationSteps;
        static volatile int currentFrontLeftSensorSteps, currentFrontRightSensorSteps, currentBackLeftSensorSteps, currentBackRightSensorSteps;
        static volatile unsigned long lastFrontLeftRotations, lastFrontRightRotations, lastBackLeftRotations, lastBackRightRotations;
};

extern DriveClass Drive;
