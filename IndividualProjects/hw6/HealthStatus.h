//
// Created by Johnson, Hans J on 4/2/18.
//

#ifndef HOMEWORK5_HEALTHSTATUS_H
#define HOMEWORK5_HEALTHSTATUS_H

#include <string>
#include <iostream>

using namespace std;

class HealthStatus {
public:
  HealthStatus(const double food, const double clothes, const double entertainment);
  HealthStatus(const HealthStatus & hs);

  double getFood() const;

  void setFood(double food);

  double getClothes() const;

  void setClothes(double clothes);

  double getEntertainment() const;

  void setEntertainment(double entertainment);

  void Print() const;

  string toString() const;

  // += Operator for HealthStatus, used to add up the total Health Status
  HealthStatus operator += (const HealthStatus & hs){
      this->m_food += hs.m_food;
      this->m_clothes += hs.m_clothes;
      this->m_entertainment += hs.m_entertainment;
  }

  // * Operator for HealthStatus, used to multiply item Health Statuses and quality multipliers
  HealthStatus operator * (const HealthStatus & hs){
      HealthStatus HS(0,0,0);
      HS.m_food = this->m_food * hs.m_food;
      HS.m_clothes = this->m_clothes * hs.m_clothes;
      HS.m_entertainment = this->m_entertainment * hs.m_entertainment;
      return HS;
  }

private:
  double m_food;
  double m_clothes;
  double m_entertainment;
};

static const HealthStatus ZERO_HS(0, 0, 0);
#endif //HOMEWORK5_HEALTHSTATUS_H
