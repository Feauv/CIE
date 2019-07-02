// Write program to navigate one track at a time.

#define ALLOW_ROBOT_HELPERS_TO_BE_INCLUDED
#include "robotHelperFunctions.h"
#undef ALLOW_ROBOT_HELPERS_TO_BE_INCLUDED
#include "AutonomousVehicle.h"
#include "PIDControllerLogic.h"

int main()
{
  // Initializations
  AutonomousVehicle robotAV;
  pidController robotPID;
  TrackNavigatorLogic * robotTNL;
  int maxSpeedForTerrain = 220;
  char barcount = '1';
  double rotationalReadings = 1200, RR;
  double rpr;

  // Set Last Proportional and Integral to zero
  robotPID.setLastProportional(0);
  robotPID.setIntegral(0);

  // Call initializeRobot
  initializeRobot();

  // Road Sign While Loop
  while(1) {

    // Get position
    unsigned int position = robotAV.UpdateSensors();

    // Call of the AdjustSteering function
    robotTNL->AdjustSteering(position, maxSpeedForTerrain, barcount);

    RR = rotationalReadings/maxSpeedForTerrain;

    //robotAV.DetectSensors(barcount, RR);

    // Call of the DetectSensors to detect if there is a terrain change
    barcount = robotAV.DetectSensors(barcount, RR);

    // Print barcount
    robotAV.print(barcount);

  }

}

