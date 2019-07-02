//
// Created by Hans Johnson on 4/20/18.
//

#include "Dice.h"
#include <random>

Dice::Dice(const std::string & color)
 : m_Color{color}
{
}

const std::string &Dice::GetColor() const
{
  return m_Color;
}

int Dice::roll() const
{
  //See: http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
  static std::random_device rd;  //Will be used to obtain a seed for the random number engine
  static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  static std::uniform_int_distribution<> intDistribution(1, 6);

  const int dice_value = intDistribution(gen);
  return dice_value;
}
