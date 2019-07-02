//
// Created by Jacob, Mathews on 2/17/17.
//

#ifndef HW2_GEAR_H
#define HW2_GEAR_H

#include <pololu/3pi.h>

#include "PIDControllerLogic.h"
#include "AutonomousVehicle.h"


class TrackNavigatorLogic {
public:

    // AV and PID initializations
    AutonomousVehicle * const m_currentCar;
    pidController PID;

    // Functions for the class
    void AdjustSteering(unsigned int pd, int maxspeed, char barcount);


};

#endif //HW2_GEAR_H
