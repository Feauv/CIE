//
// Created by Hans Johnson on 4/20/18.
//

#ifndef HOMEWORK5_DICE_H
#define HOMEWORK5_DICE_H

#include <string>

class Dice
{
public:
  Dice(const std::string & color);
  const std::string & GetColor() const;

  /**
 * @brief Return the random result of rolling 6 sided dice
 * @return The result of rolling a dice.
 */
  int roll() const;

private:
  const std::string m_Color;
};


#endif //HOMEWORK5_DICE_H
