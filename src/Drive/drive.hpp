#include <Arduino.h>

class Drive {
    public:
        void setup(int leftMotorsForwardPin, int leftMotorsBackwardPin, int leftMotorsSpeedPin, int rightMotorsForwardPin, int rightMotorsBackwardPin, int rightMotorsSpeedPin);
        void forward(int speed);
        void backward(int speed);
        void rotateLeft(int speed);
        void rotateRight(int speed);
        void stop();
    private:
        int leftMotorsForwardPin, leftMotorsBackwardPin, leftMotorsSpeedPin, rightMotorsForwardPin, rightMotorsBackwardPin, rightMotorsSpeedPin;
};
