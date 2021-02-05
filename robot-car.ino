/*
  Car robot with sonar and bluetooth.

  2020 by Vivien Richter <vivien-richter@outlook.de>
  https://github.com/HTWK-18INB-1/asuka.git
*/

#include "config.hpp"
#include "src/Drive/drive.hpp"
#include "src/Sonar/sonar.hpp"

Sonar sonar;

// Initialization
void setup() {
    // Communication
    Serial.begin(9600);
    // Motors
    Drive.setup(
        MOTOR_LEFT_DIRECTION,
        MOTOR_LEFT_SPEED,
        MOTOR_LEFT_SENSOR,
        MOTOR_RIGHT_DIRECTION,
        MOTOR_RIGHT_SPEED,
        MOTOR_RIGHT_SENSOR,
        MOTOR_CYCLE_TICKS,
        WHEEL_DIAMETER
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
    if (Serial.available()) {
        char command = Serial.read();
        int value = Serial.parseInt();
        switch (command) {
            // Logic tests
            case 'x':
                Drive.forward(255);
                while (Drive.getDistance() < value) {
                    Serial.println(DriveClass::dump[0]);
                    Serial.println(DriveClass::dump[1]);
                    Serial.println(DriveClass::dump[2]);
                    Serial.println(DriveClass::dump[3]);
                    Serial.println(DriveClass::dump[4]);
                    Serial.println("-----");
                }
                Drive.stop();
                break;
            // Drive test
            case 'f':
                Drive.forward(value);
                break;
            case 'b':
                Drive.backward(value);
                break;
            case 'l':
                Drive.rotateLeft(value);
                break;
            case 'r':
                Drive.rotateRight(value);
                break;
            case 'h':
                Drive.stop();
                break;
            // Sonar test
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
