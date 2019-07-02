//
// Created by Hans J. Johnson on 2/7/18.
//

#ifndef HW2_HANDOFCARDS_H
#define HW2_HANDOFCARDS_H


#include "SingleCard.h"
#include "utilityFunctions.h"
#include "GameConsole.h"

// Edited some of the classes inputs to show what player it is
class HandOfCards {
public:
  SingleCard * getCardAtIndex(int index) ;
  void setCardAtIndex(SingleCard card, int index, int player);
  int printPlayerHandInfo(GameConsole * currentConsole, int p) ;
  int computeTotalAndPrintCardScoreValues(GameConsole * currentConsole) ;
  bool isUnique(int cardIndexToCheckUniqueness);
  SingleCard * m_Hand[NUMBER_OF_CARDS_IN_HAND];
};


#endif //HW2_HANDOFCARDS_H
