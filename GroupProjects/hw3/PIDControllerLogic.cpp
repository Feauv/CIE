
#include "PIDControllerLogic.h"
#define ALLOW_ROBOT_HELPERS_TO_BE_INCLUDED
#include "robotHelperFunctions.h"
#undef ALLOW_ROBOT_HELPERS_TO_BE_INCLUDED

static const int CENTER = 2000;

/* Function Name: computePD
 * Programmer: Nick Grove
 * Function Description: Uses PID control function, the PID example code we are given, and getters and setters, to calculate power difference for the vehicles wheels
 * Function Call: Called in TrackNavigatorLogic's AdjustSteering
 */
int pidController::computePD(unsigned int position, char barcount) {

    // Set the proportional equal to the position
    setProportional(((int) position) - CENTER);

    // Set the differential and integral
    setDifferential(getProportional() - getLastProportional());
    setIntegral(getIntegral() + getProportional());

    // Set the last proportional for the next differential calculation
    setLastProportional(getProportional());

    // Set power difference to zero
    setpowerDifference(0);
    
    // Switch Statement for different terrains
    switch (barcount){
        
        // Each terrain needs a different type of PID for sharper turns and different style of terrain
        case '1':
            setpowerDifference(getProportional()/10 + getIntegral()/5000 + ((int)(getDifferential() * 1.5)));
            break;
        case '2':
            setpowerDifference(getProportional()/8 + getIntegral()/3000 + ((int)(getDifferential() * 1.5)));
            break;
        case '3':
            setpowerDifference(getProportional()/5 + getIntegral()/500 + ((int)(getDifferential() * 2)));
            break;
        case '4':
            setpowerDifference(getProportional()/8 + getIntegral()/3000 + ((int)(getDifferential() * 1.5)));
            break;
        
    }

    // Return PD
    int PD = getpowerDifference();
    return PD;

}

/* Function Name: resetPID
 * Programmer: Nick Grove
 * Function Description: Resets all the attributes of the PID class
 * Function Call: Called in the main function
 */
void pidController::resetPID(){
    setLeftMotorSpeed(0);
    setRightMotorSpeed(0);
    setpowerDifference(0);
    setLastProportional(0);
    setIntegral(0);
    setDifferential(0);
    setProportional(0);
}