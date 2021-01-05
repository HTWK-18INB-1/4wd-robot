#include <Arduino.h>
#include <Servo.h>

class Sonar {
    public:
        void setup(int rotationPin, int triggerPin, int echoPin, int rotationSpeed, int rotationMin, int rotationMax, int soundSpeed);
        void scan();
    private:
        Servo rotation;
        int rotationPin, triggerPin, echoPin, rotationSpeed, rotationMin, rotationMax, soundSpeed;
        int getDistance();
};
