#include <Arduino.h>
#include <Servo.h>

class Sonar {
    public:
        void setup(int rotationPin, int triggerPin, int echoPin, int rotationSpeed, int soundSpeed);
        void scan();
    private:
        Servo rotation;
        int rotationPin, triggerPin, echoPin, rotationSpeed, soundSpeed;
        int getDistance();
};
