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
        SONAR_ROTATION_PIN,
        SONAR_TRIGGER_PIN,
        SONAR_ECHO_PIN,
        SONAR_TRIGGER_WIDTH,
        SONAR_ROTATION_MIN,
        SONAR_ROTATION_HALF,
        SONAR_ROTATION_MAX,
        SONAR_ROTATION_DELAY,
        SONAR_ROTATION_DELAY_MAX,
        SOUND_SPEED
    );
}

// Main
void loop() {
    test();
}

void test() {
    if (Serial.available()) {
        char command = Serial.read();
        int speed = Serial.parseInt();
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
                int distances[181];
                sonar.scan(distances);
                for (int i = 0; i <= 180; i++) {
                    Serial.println(String(i) + ": " + String(distances[i]));
                }
                break;
        }
    }
}
