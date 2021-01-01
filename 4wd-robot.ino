/*
  4WD robot with sonar and optical position detection.

  2020 by Vivien Richter <vivien-richter@outlook.de>
  https://github.com/vivi90/4wd-robot
*/
// Motor configuration
#define MOTORS_RIGHT_FORWARD_PIN 2
#define MOTORS_RIGHT_SPEED_PIN 3
#define MOTORS_RIGHT_BACKWARD_PIN 4
#define MOTORS_LEFT_FORWARD_PIN 5
#define MOTORS_LEFT_SPEED_PIN 6
#define MOTORS_LEFT_BACKWARD_PIN 7

#include "src/Drive/drive.hpp"

Drive drive;

// Initialization
void setup() {
    // Motors
    drive.setup(
        MOTORS_LEFT_FORWARD_PIN,
        MOTORS_LEFT_BACKWARD_PIN,
        MOTORS_LEFT_SPEED_PIN,
        MOTORS_RIGHT_FORWARD_PIN,
        MOTORS_RIGHT_BACKWARD_PIN,
        MOTORS_RIGHT_SPEED_PIN
    );
    Serial.begin(9600);
}

// Main
void loop() {
    driveTest();
}

void driveTest() {
    char command;
    int speed = 0;
    if (Serial.available()) {
        command = Serial.read();
        speed = Serial.parseInt();
        switch (command) {
            case 'f':
                drive.forward(speed);
                break;
            case 'b':
                drive.backward(speed);
                break;
            case 'l':
                drive.rotateLeft(speed);
                break;
            case 'r':
                drive.rotateRight(speed);
                break;
            case 's':
                drive.stop();
                break;
        }
    }
}
