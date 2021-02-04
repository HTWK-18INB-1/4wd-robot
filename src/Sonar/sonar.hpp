#include <Arduino.h>
#include <Servo.h>

class Sonar {
    public:
        /**
         * Constructor
         *
         * @param rotationPin Servo pin
         * @param triggerPin Sonar trigger pin
         * @param echoPin Sonar echo pin
         * @param triggerWidth Sonar trigger pulse width
         * @param rotationMin Minimum servo pulse width (for 0°)
         * @param rotationHalf Half servo pulse width (for 90°)
         * @param rotationMax Maximum servo pulse width (for 180°)
         * @param rotationDelay Servo rotation delay for each degree
         * @param rotationDelayMax Maximum servo rotation delay
         * @param soundSpeed Sound speed
         */
        void setup(int rotationPin, int triggerPin, int echoPin, int triggerWidth, int rotationMin, int rotationHalf, int rotationMax, int rotationDelay, int rotationDelayMax, int soundSpeed);

        /**
         * Does an complete distance scan from 0 to 180°
         *
         * @param distances Pointer to a field for the 181 distances and it's corresponding degress as indices.
         */
        void scan(int *distances);

    private:
        /**
         * The servo instance
         */
        Servo servo;

        /**
         * Servo pin
         */
        int rotationPin;

        /**
         * Sonar trigger pin
         */
        int triggerPin;

        /**
         * Sonar echo pin
         */
        int echoPin;

        /**
         * Sonar trigger pulse width
         */
        int triggerWidth;

        /**
         * Minimum servo pulse width (for 0°)
         */
        int rotationMin;

        /**
         * Half servo pulse width (for 90°)
         */
        int rotationHalf;

        /**
         * Maximum servo pulse width (for 180°)
         */
        int rotationMax;

        /**
         * Servo rotation delay for each degree
         */
        int rotationDelay;

        /**
         * Maximum servo rotation delay
         */
        int rotationDelayMax;

        /**
         * The sound speed
         */
        int soundSpeed;

        /**
         * Last rotation angle
         */
        int lastAngle = 90;

        /**
         * Get distance
         *
         * @return Distance in mm
         */
        int getDistance();

        /**
         * Rotates sonar.
         *
         * @param angle Desired angle in degree
         */
        void rotate(int angle);
};
