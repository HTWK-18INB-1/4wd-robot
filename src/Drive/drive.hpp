#include <Arduino.h>

/**
 * Drive class
 *
 * @version 1.1.0
 * @author Vivien Richter <vivien-richter@outlook.de>
 */
class DriveClass {
    public:
        /**
         * Driving directions
         */
        static const int DRIVING_STOP = 0;
        static const int DRIVING_FORWARD = 1;
        static const int DRIVING_BACKWARD = 2;
        static const int DRIVING_ROTATION_LEFT = 3;
        static const int DRIVING_ROTATION_RIGHT = 4;

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
         * Returns current driving direction
         *
         * @return Returns 0 = stop, 1 = forward, 2 = backward, 3 = left rotation or 4 = right rotation
         */
        int getCurrentDirection();

        /**
         * Returns currently already driven distance
         *
         * Only available while driving
         *
         * @return Distance in mm
         */
        unsigned long getDistance();

        volatile static int dump[5];

    private:
        /**
         * Direction pin of the left motor
         */
        int leftMotorDirectionPin;

        /**
         * Speed pin of the left motor
         */
        volatile static int  leftMotorSpeedPin;

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
        volatile static int rightMotorSpeedPin;

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
         * Current driving direction
         */
        volatile static int drivingDirection;

        /**
         * Current base speed
         */
        volatile static int baseSpeed;

        /**
         * Left wheel sensor ticks
         */
        volatile static int leftMotorSensorTicks;

        /**
         * Right wheel sensor ticks
         */
        volatile static int rightMotorSensorTicks;

        /**
         * Resets the distance counter
         */
        void resetDistance();

        /**
         * Adjusts the engine speeds while driving
         */
        static void adjustSpeed();

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
