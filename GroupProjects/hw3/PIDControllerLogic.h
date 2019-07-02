#ifndef HW3_PID_H
#define HW3_PID_H


#include "AutonomousVehicle.h"

class pidController {
public:

  // Functions of the class (that we coded)
  int computePD(unsigned int position, char barcount);
  void resetPID();

    // Getters and Setters
    int getProportional() const {
        return m_Proportional;
    }

    void setProportional(int Proportional) {
        m_Proportional = Proportional;
    }

    int getLastProportional() const {
        return m_LastProportional;
    }

    void setLastProportional(int LastProportional) {
        m_LastProportional = LastProportional;
    }

    int getIntegral() const {
        return m_Integral;
    }

    void setIntegral(int Integral) {
        m_Integral = Integral;
    }

    int getDifferential() const {
        return m_Differential;
    }

    void setDifferential(int Differential) {
        m_Differential = Differential;
    }

    int getLeftMotorSpeed() const {
        return m_leftMotorSpeed;
    }

    void setLeftMotorSpeed(int leftMotorSpeed) {
        m_leftMotorSpeed = leftMotorSpeed;
    }

    int getRightMotorSpeed() const {
        return m_rightMotorSpeed;
    }

    void setRightMotorSpeed(int rightMotorSpeed) {
        m_rightMotorSpeed = rightMotorSpeed;
    }

    int getpowerDifference() const {
        return m_powerDifference;
    }

    void setpowerDifference(int powerDifference) {
        m_powerDifference = powerDifference;
    }

private:

    // Attributes of the class
    int m_Proportional{0};
    int m_LastProportional{0};
    int m_Integral{0};
    int m_Differential{0};
    int m_powerDifference{0};
    int m_leftMotorSpeed{0};
    int m_rightMotorSpeed{0};
};


#endif

