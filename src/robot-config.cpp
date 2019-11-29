#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor frontLeftMotor = motor(PORT1, ratio18_1, false);
motor frontRightMotor = motor(PORT2, ratio18_1, false);
motor backLeftMotor = motor(PORT3, ratio18_1, false);
motor backRightMotor = motor(PORT4, ratio18_1, false);
motor leftIntake = motor(PORT5, ratio18_1, false);
motor rightIntake = motor(PORT6, ratio18_1, false);
motor pushMotor = motor(PORT7, ratio36_1, false);

// VEXcode generated functions
// define variables used for controlling motors based on controller inputs

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {}

void move(int32_t side, motor frontWheel, motor backWheel, vex::controller::axis stick) {
  // int32_t direction = stick.value();
  int32_t velocity = stick.position();
  if (side * velocity > 0) {
    frontWheel.spin(forward, abs(velocity), velocityUnits::pct);
    backWheel.spin(forward, abs(velocity), velocityUnits::pct);
  } else if (side * velocity < 0) {
    frontWheel.spin(reverse, abs(velocity), velocityUnits::pct);
    backWheel.spin(reverse, abs(velocity), velocityUnits::pct);
  } else {
    frontWheel.stop();
    backWheel.stop();
  }
}

void intake (vex::controller::button load, vex::controller::button unload) {
    if (load.pressing()) {
      leftIntake.spin(reverse, 100, velocityUnits::pct);
      rightIntake.spin(forward, 100, velocityUnits::pct);
    } else if (unload.pressing()) {
      leftIntake.spin(forward, 100, velocityUnits::pct);
      rightIntake.spin(reverse, 100, velocityUnits::pct);
    } else {
      leftIntake.stop();
      rightIntake.stop();
    }
}

void tower (vex::controller::button forward, vex::controller::button back){
  
}