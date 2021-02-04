// Motor configuration
#define MOTOR_RIGHT_DIRECTION 8
#define MOTOR_RIGHT_SPEED 9
#define MOTOR_RIGHT_SENSOR 2 // Right wheel sensor pin
#define MOTOR_LEFT_DIRECTION 10
#define MOTOR_LEFT_SPEED 11
#define MOTOR_LEFT_SENSOR 3 // Left wheel sensor pin
#define MOTOR_CYCLE_TICKS 20 // The number of ticks, thats required for one rotation
#define WHEEL_DIAMETER 67 // in mm

// Sonar configuration
#define SONAR_ROTATION_PIN 6
#define SONAR_TRIGGER_PIN 5
#define SONAR_ECHO_PIN 4
#define SONAR_TRIGGER_WIDTH 10 // Minimum trigger pulse width (in microseconds)
#define SONAR_ROTATION_MIN 520 // Pulse width for 0°
#define SONAR_ROTATION_HALF 1400 // Pulse width for 90°
#define SONAR_ROTATION_MAX 2440 // Pulse width for 180°
#define SONAR_ROTATION_DELAY 20 // delay in ms/°
#define SONAR_ROTATION_DELAY_MAX 300 // maximum delay in ms
#define SOUND_SPEED 344 // In dry air at 20°C in m/s
