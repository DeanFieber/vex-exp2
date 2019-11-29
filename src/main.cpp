/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\deanf                                            */
/*    Created:      Sun Nov 24 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// frontLeftMotor       motor         1
// frontRightMotor      motor         2
// backLeftMotor        motor         3
// backRightMotor       motor         4
// leftIntake           motor         5
// rightIntake          motor         6
// pushMotor            motor         7
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  frontLeftMotor.spin(directionType::fwd, 100, velocityUnits::pct);
  backLeftMotor.spin(directionType::fwd, 100, velocityUnits::pct);
  frontRightMotor.spin(directionType::rev, 100, velocityUnits::pct);
  backRightMotor.spin(directionType::rev, 100, velocityUnits::pct);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  while (true) {

    move(LEFT, frontLeftMotor, backLeftMotor, Controller1.Axis3);
    move(RIGHT, frontRightMotor, backRightMotor, Controller1.Axis2);

    intake(Controller1.ButtonL1, Controller1.ButtonL2);
    // bool leftShoulder = Controller1.ButtonL1.pressing(); // rename intakeLoad?
    // bool leftTrigger = Controller1.ButtonL2.pressing(); // rename intakeUnload?
    // if (leftTrigger) {
    //   leftIntake.spin(reverse, 100, velocityUnits::pct);
    //   rightIntake.spin(forward, 100, velocityUnits::pct);
    // } else if (leftShoulder) {
    //   leftIntake.spin(forward, 100, velocityUnits::pct);
    //   rightIntake.spin(reverse, 100, velocityUnits::pct);
    // } else {
    //   leftIntake.stop();
    //   rightIntake.stop();
    // }

    tower (Controller1.ButtonR1, Controller1.ButtonR2);
    // bool rightShoulder = Controller1.ButtonR1.pressing(); // rename tiltForward?
    // bool rightTrigger = Controller1.ButtonR2.pressing();  // tileBackward?
    // if (rightTrigger) {
    //   pushMotor.spin(reverse, 100, velocityUnits::pct);
    // } else if (rightShoulder) {
    //   pushMotor.spin(forward, 100, velocityUnits::pct);
    // } else {
    //   pushMotor.stop();
    // }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
