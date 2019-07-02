/*
 * 3pi-linefollower-pid - demo code for the Pololu 3pi Robot
 * 
 * The TrackNavigatorLogic object will manipulate a AutonomousVehicle
 * object to follow a black line on a white background,
 * using a PID-based algorithm.
 *
 * http://www.pololu.com/docs/0J21
 * http://www.pololu.com
 * http://forum.pololu.com
 *
 */

#define ALLOW_ROBOT_HELPERS_TO_BE_INCLUDED
#include "robotHelperFunctions.h"
#undef ALLOW_ROBOT_HELPERS_TO_BE_INCLUDED
#include "AutonomousVehicle.h"
#include "PIDControllerLogic.h"
#include "TrackNavigatorLogic.h"

volatile bool runForever = true;

// This is the main function, where the code starts.  All C programs
// must have a main() function defined somewhere.
int main()
{
  // Initializations
  AutonomousVehicle robotAV;
  pidController robotPID;
  TrackNavigatorLogic * robotTNL;
  int maxSpeedForTerrain = 220;
  char barcount = '1';
  double rotationalReadings = 1200, RR;

  // Set Last Proportional and Integral to zero
  robotPID.setLastProportional(0);
  robotPID.setIntegral(0);

  // Call initializeRobot
  initializeRobot();

  // Road Sign While Loop

  while (runForever)
  {

    // Get position
    unsigned int position = robotAV.UpdateSensors();

    // Call of the AdjustSteering function
    robotTNL->AdjustSteering(position, maxSpeedForTerrain, barcount);

    // Compute RR so we know the number of readings we get for a certain speed
    RR = rotationalReadings/maxSpeedForTerrain;

    // Call of the DetectSensors to detect if there is a terrain change
    barcount = robotAV.DetectSensors(barcount, RR);

    // Print barcount
    robotAV.print(barcount);

  }
}