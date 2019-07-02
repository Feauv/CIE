//
// Created by Hans J. Johnson on 2/7/18.
//

#include <stdio.h>
#include "HandOfCards.h"


bool HandOfCards::isUnique(int cardIndexToCheckUniqueness) {

  return true;
}

int HandOfCards::computeTotalAndPrintCardScoreValues(GameConsole * currentConsole) {

  return -1;
}

int HandOfCards::printPlayerHandInfo(GameConsole * currentConsole, int p)
{
  int handTotal = 123;
  return handTotal;
}

// Assigning cards to the hand pointer
void HandOfCards::setCardAtIndex(SingleCard c, int i, int p)
{

  *(m_Hand+p)[i] = c;

}