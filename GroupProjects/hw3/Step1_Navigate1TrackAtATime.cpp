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
    int maxSpeedForTerrain = 150;
    char barcount = '1';

    // Set Last Proportional and Integeral to zero
    robotPID.setLastProportional(0);
    robotPID.setIntegral(0);

    // Call initializeRobot
    initializeRobot();

    // Navigation While Loop
    while(1) {

        // Get position
        unsigned int position = robotAV.UpdateSensors();

        // Call AdjustSteering
        robotTNL->AdjustSteering(position, maxSpeedForTerrain, barcount);

    }



}

