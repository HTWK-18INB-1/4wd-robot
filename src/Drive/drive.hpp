#include <Arduino.h>

class Drive {
    public:
        void setup(int leftMotorsDirectionPin, int leftMotorsSpeedPin, int rightMotorsDirectionPin, int rightMotorsSpeedPin);
        void forward(int speed);
        void backward(int speed);
        void rotateLeft(int speed);
        void rotateRight(int speed);
        void stop();
    private:
        int leftMotorsDirectionPin, leftMotorsSpeedPin, rightMotorsDirectionPin, rightMotorsSpeedPin;
};
