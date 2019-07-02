#include "TrackNavigatorLogic.h"

/* Function Name: AdjustSteering
 * Programmer: Nick Grove
 * Function Description: Calls computePD to get power difference and uses that to set the wheel speeds
 * Function Call: Called in the main function
 */
void TrackNavigatorLogic::AdjustSteering(unsigned int pos, int maxspeed, char barcount){

    // Calls computePD
    int PD = PID.computePD(pos, barcount);

    // Makes sure PD doesn't exceed the current speed
    if (PD > maxspeed)
        PID.setpowerDifference(maxspeed);
    if (PD < -maxspeed)
        PID.setpowerDifference(-maxspeed);

    // Sets PD to which wheel it needs to be set to
    if(PD < 0)
        m_currentCar->set_wheel_speed(maxspeed+PD, maxspeed);
    else
        m_currentCar->set_wheel_speed(maxspeed, maxspeed-PD);

}



