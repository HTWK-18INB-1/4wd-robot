#include <Arduino.h>

/**
 * Drive class
 *
 * @version 1.0.0
 * @author Vivien Richter <vivien-richter@outlook.de>
 */
class DriveClass {
    public:
        /**
         * Constructor
         *
         * @param leftMotorDirectionPin Used to change the rotational direction of the left motor (HIGH = forward, LOW = backward)
         * @param leftMotorSpeedPin Used to change the speed of the left motor, related to it's direction
         * @param leftMotorSensorPin Used to check the rotations of the left wheel
         * @param rightMotorDirectionPin Used to change the rotational direction of the right motor (HIGH = forward, LOW = backward)
         * @param rightMotorSpeedPin Used to change the speed of the right motor, related to it's direction
         * @param rightMotorSensorPin Used to check the rotations of the right wheel
         * @param motorCycleTicks The number of sensor ticks, that's required for one full motor rotation
         * @param wheelDiameter The wheel diameter
         */
        void setup(int leftMotorDirectionPin, int leftMotorSpeedPin, int leftMotorSensorPin, int rightMotorDirectionPin, int rightMotorSpeedPin, int rightMotorSensorPin, int motorCycleTicks, int wheelDiameter);

        /**
         * Forward for all engines
         *
         * @param speed Desired speed (0 - 255)
         */
        void forward(int speed);

        /**
         * Backward for all engines
         *
         * @param speed Desired speed (0 - 255)
         */
        void backward(int speed);

        /**
         * Left rotation
         *
         * @param speed Desired speed (0 - 255)
         */
        void rotateLeft(int speed);

        /**
         * Right rotation
         *
         * @param speed Desired speed (0 - 255)
         */
        void rotateRight(int speed);

        /**
         * Full stop for all engines
         */
        void stop();

        /**
         * Returns already driven distance
         *
         * @return Distance in mm
         */
        unsigned long getDistance();

        /**
         * Resets the already driven distance counter
         */
        void resetDistance();

    private:
        /**
         * Direction pin of the left motor
         */
        int leftMotorDirectionPin;

        /**
         * Speed pin of the left motor
         */
        int leftMotorSpeedPin;

        /**
         * Sensor pin of the left motor
         */
        int leftMotorSensorPin;

        /**
         * Direction pin of the right motor
         */
        int rightMotorDirectionPin;

        /**
         * Speed pin of the left motor
         */
        int rightMotorSpeedPin;

        /**
         * Sensor pin of the right motor
         */
        int rightMotorSensorPin;

        /**
         * Motor cycle ticks
         */
        int motorCycleTicks;

        /**
         * Wheel circumference per sensor tick
         */
        int wheelCircumferencePerTick;

        /**
         * Left wheel sensor ticks
         */
        volatile static unsigned long leftMotorSensorTicks;

        /**
         * Right wheel sensor ticks
         */
        volatile static unsigned long rightMotorSensorTicks;

        /**
         * Left wheel sensor ISR
         */
        static void leftMotorSensorISR();

        /**
         * Right wheel sensor ISR
         */
        static void rightMotorSensorISR();
};

// Shares it's instance
extern DriveClass Drive;
