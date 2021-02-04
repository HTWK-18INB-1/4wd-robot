// Motor configuration
#define MOTORS_RIGHT_DIRECTION 8
#define MOTORS_RIGHT_SPEED 9
#define MOTORS_LEFT_DIRECTION 10
#define MOTORS_LEFT_SPEED 11

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
