/*
  4WD robot with sonar and optical position detection.

  2020 by Vivien Richter <vivien-richter@outlook.de>
  https://github.com/vivi90/4wd-robot
*/

#include "config.hpp"
#include "src/Drive/drive.hpp"

Drive drive;

// Initialization
void setup() {
    // Communication
    Serial.begin(9600);
    // Motors
    drive.setup(
        MOTORS_LEFT_DIRECTION,
        MOTORS_LEFT_SPEED,
        MOTORS_RIGHT_DIRECTION,
        MOTORS_RIGHT_SPEED
    );
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
