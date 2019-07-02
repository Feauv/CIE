//
// Created by Johnson, Hans J on 4/2/18.
//

#include "HealthStatus.h"
#include <iostream>
#include <sstream>

using namespace std;


HealthStatus::HealthStatus(const double food, const double clothes, const double entertainment)
  :m_food(food), m_clothes(clothes), m_entertainment(entertainment)
{
}

HealthStatus::HealthStatus(const HealthStatus& hs)
  :m_food(hs.getFood()), m_clothes(hs.getClothes()), m_entertainment(hs.getEntertainment())
{
}

void HealthStatus::Print() const
{
  cout << "\n";
  cout << "  \"food\" : \"" << m_food << "\",\n";
  cout << "  \"clothes\" : \"" << m_clothes << "\",\n";
  cout << "  \"entertainment\" : \"" << m_entertainment << "\"\n";
  cout << "\n";
}

string HealthStatus::toString() const
{
  stringstream asstring("");
  asstring << " Food: " << m_food << " "
           << " Clothes: " << m_clothes << " "
           << " Entertainment: " << m_entertainment << " ";
  return asstring.str();
}

double HealthStatus::getFood() const
{
  return m_food;
}

void HealthStatus::setFood(double food)
{
  m_food = food;
}

double HealthStatus::getClothes() const
{
  return m_clothes;
}

void HealthStatus::setClothes(double clothes)
{
  m_clothes = clothes;
}

double HealthStatus::getEntertainment() const
{
  return m_entertainment;
}

void HealthStatus::setEntertainment(double entertainment)
{
  m_entertainment = entertainment;
}
