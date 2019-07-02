//
// Created by Hans J. Johnson on 2/7/18.
//
// This file contains the most rudimentary of testing programs for
// ensuring that the HandOfCards class object performs as needed.
// You are not required to modify this file, but you are allowed
// to expand and enhance this testing file in what ever way you want.
//
// The contents of this file will not be graded.
//

#include "GameConsole.h"
#include "HandOfCards.h"
#include "DeckOfCards.h"

int main(void) {

  GameConsole myGameConsoleHardware;
  /* perform battery check */
  myGameConsoleHardware.doBatteryCheck();

  DeckOfCards myDeck;
  myDeck.initDeck();

  HandOfCards myHand;

  /* main loop that runs forever */
  while (1) {
    myHand.setCardAtIndex(myDeck.getNextCard(),0);
    myHand.setCardAtIndex(myDeck.getNextCard(),1);
    myHand.setCardAtIndex(myDeck.getNextCard(),2);
    myHand.printPlayerHandInfo(&myGameConsoleHardware);
    myDeck.shuffle();
    myGameConsoleHardware.delayMilliseconds(2000);
  }
}
