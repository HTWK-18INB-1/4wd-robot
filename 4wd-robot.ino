/*
  4WD robot with sonar and optical position detection.

  2020 by Vivien Richter <vivien-richter@outlook.de>
  https://github.com/vivi90/4wd-robot
*/
// Configuration
#define MOTORS_RIGHT_DIRECTION 2
#define MOTORS_RIGHT_SPEED 3
#define MOTORS_LEFT_DIRECTION 4
#define MOTORS_LEFT_SPEED 5
#define SENSOR_MOTOR_BACK_RIGHT 6
#define SENSOR_MOTOR_BACK_LEFT 7
#define SENSOR_MOTOR_FRONT_RIGHT 8
#define SENSOR_MOTOR_FRONT_LEFT 9
#define SENSOR_MOTOR_STEPS_FULL_ROTATION 20

#include "src/Drive/drive.hpp"

// Initialization
void setup() {
    Drive.setup(
        MOTORS_LEFT_DIRECTION,
        MOTORS_LEFT_SPEED,
        MOTORS_RIGHT_DIRECTION,
        MOTORS_RIGHT_SPEED,
        SENSOR_MOTOR_FRONT_LEFT,
        SENSOR_MOTOR_FRONT_RIGHT,
        SENSOR_MOTOR_BACK_LEFT,
        SENSOR_MOTOR_BACK_RIGHT,
        SENSOR_MOTOR_STEPS_FULL_ROTATION
    );
    Serial.begin(9600);
}

// Main
void loop() {
    Drive.test();
    delay(1000);
    Serial.println(Drive.getLastRotations());
    delay(1000);
}
