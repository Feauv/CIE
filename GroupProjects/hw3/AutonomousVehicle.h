//
// Created by Hans J. Johnson on 2/22/18.
//

#ifndef HW3_AUTONOMOUSVEHICLE_H
#define HW3_AUTONOMOUSVEHICLE_H
#include <time.h>
#include "PIDControllerLogic.h"

#define MAXMOTORSPEED 254
#define MINMOTORSPEED 1

typedef unsigned int SensorPositionIndicatorType;

class AutonomousVehicle {
public:

  // Functions of the class
  void set_wheel_speed(int Rwheel, int Lwheel);
  SensorPositionIndicatorType UpdateSensors();
  char DetectSensors(char barcount, double RR);
  void print(char character);


private:

  // Attributes of the class
  unsigned int m_sensors[5] = {0};
  bool black;
  bool white;
  int black_counter = 0;

};


#endif //HW3_AUTONOMOUSVEHICLE_H
