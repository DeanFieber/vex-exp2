using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor frontLeftMotor;
extern motor frontRightMotor;
extern motor backLeftMotor;
extern motor backRightMotor;
extern motor leftIntake;
extern motor rightIntake;
extern motor pushMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );

#define RIGHT -1
#define LEFT 1

void leftTrack(vex::controller::axis stick);
void rightTrack(vex::controller::axis stick);

void intake (vex::controller::button load, vex::controller::button unload);
void tower (vex::controller::button forward, vex::controller::button back);