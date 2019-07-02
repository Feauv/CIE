//
// Created by Hans J. Johnson on 2/22/18.
//

#include "AutonomousVehicle.h"

/**
 * The robotHelperFunctions are not allowed
 * anywhere outside of this file.  The low-level
 * robot manipulation functions can not be accessed by
 * the TrackNavigator or PID controller for full credit.
 */
#define ALLOW_ROBOT_HELPERS_TO_BE_INCLUDED
#include "robotHelperFunctions.h"
#undef ALLOW_ROBOT_HELPERS_TO_BE_INCLUDED
#include "PIDControllerLogic.h""
#include <time.h>
#include <stdio.h>

// Initializes the 3pi, displays a welcome message, calibrates, and
// plays the initial music.

// set_wheel_speed function sets the wheel speeds
void AutonomousVehicle::set_wheel_speed(int Rwheel, int Lwheel){

    // Using set_motors function
    set_motors(Rwheel, Lwheel);

}

// UpdateSensors uses the sensors to get the position
SensorPositionIndicatorType AutonomousVehicle::UpdateSensors(){

    // Uses read_line function
    unsigned int position = read_line(m_sensors, IR_EMITTERS_ON);
    return position;

}

char AutonomousVehicle::DetectSensors(char barcount, double RR) {

    // RR equals the number of black readings for one bar
    double bar1 = RR;

    // White Reading If Statement
    if (m_sensors[0] == 0 && m_sensors[4] == 0) {

        // Make white true
        white = true;

        // If last reading was black it enters this if statement
        if (black == true) {


            // Bar If Statement
            if (black_counter <= bar1 + 4) {

                // Set Bar Number and Beep
                barcount = '1';
                playBeepTrackChange(barcount);

            } else if (black_counter <= (bar1 + 1.5 * RR - 2)) {

                barcount = '2';
                playBeepTrackChange(barcount);

            } else if (black_counter <= (bar1 + 1 * RR + 1.5)) {

                barcount = '3';
                playBeepTrackChange(barcount);

            } else {

                barcount = '4';
                playBeepTrackChange(barcount);

            }

            // Set black_counter to zero and black to false
            black_counter = 0;
            black = false;

        }

    }

    // Black Reading If Statement
    if (m_sensors[0] == 1000 && ((m_sensors[4] == 1000) || (m_sensors[4] == 1000 && m_sensors[3] == 1000))) {

        // Set black to true
        black = true;

        // If last reading was white
        if (white == true) {

            // Set white to false
            white = false;

        }

        // Count up black_counter
        black_counter++;

    }

    // Return the barcount
    return barcount;


}

/* Function Name: print
 * Programmer: Matt Stogsdill
 * Function Description: Prints track number and sensor readings
 * Function Call: Called in the main function
 */
void AutonomousVehicle::print(char character){

    // Print first line with track
    lcd_init_printf();
    printf("Track %c ", character);

    // Print the live readings
    lcd_goto_xy(0,1);
    display_readings(m_sensors);

}

