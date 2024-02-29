#include "SeedHarvester.h"
#include "BallShooter.h"

// DRV8825 pins
#define dir_pin 17
#define step_pin 16
#define Ldir LOW
#define Rdir HIGH

// Servo pins
#define grbServo 27
#define liftServo 28

SeedHarvester seedHarvester(grbServo, liftServo, 26);

BallShooter ballShooter;

void setup() {

  //VDO Filiming purpose
  //Harvest Button
  seedHarvester.setZero();
  seedHarvester.linearDrive(455, Ldir);
  seedHarvester.grabbing();
  delay(5000);  // comment this line
  //Release Button
  seedHarvester.release();

  // Example usage for joystick
  // seedHarvester.singleHarvest();
  // seedHarvester.singleHarvest();
  // seedHarvester.singleHarvest();

  ballShooter.servo();
  ballShooter.wheel();
  delay(1000);
  while (digitalRead(BallShooter::limit_switch) == 1) {
    ballShooter.stepper_cw();
  }
  ballShooter.wheel_stop();
  if (digitalRead(BallShooter::limit_switch) == 0) {
    ballShooter.stepper_stop();
    ballShooter.stepper_ccw();
  }
}

void loop() {
}