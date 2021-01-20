/*
  Car robot with sonar and bluetooth.

  2020 by Vivien Richter <vivien-richter@outlook.de>
  https://github.com/HTWK-18INB-1/asuka.git
*/

#include "config.hpp"
#include "src/Drive/drive.hpp"
#include "src/Sonar/sonar.hpp"

Drive drive;
Sonar sonar;

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
    // Sonar
    sonar.setup(
        SENSOR_SONAR_ROTATION_PIN,
        SENSOR_SONAR_TRIGGER_PIN,
        SENSOR_SONAR_ECHO_PIN,
        SENSOR_SONAR_ROTATION_SPEED,
        SENSOR_SONAR_ROTATION_MIN,
        SENSOR_SONAR_ROTATION_MAX,
        SOUND_SPEED
    );
}

// Main
void loop() {
    test();
}

void test() {
    char command;
    int speed = 0;
    if (Serial.available()) {
        command = Serial.read();
        speed = Serial.parseInt();
        switch (command) {
            // Drive
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
            case 'h':
                drive.stop();
                break;
            // Sonar
            case 's':
                sonar.scan();
                break;
        }
    }
}
