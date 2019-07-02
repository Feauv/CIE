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
#include "DeckOfCards.h"

int main() {

  GameConsole myGameHardware;
  /* perform battery check */
  myGameHardware.doBatteryCheck();

  DeckOfCards myDeck;
  myDeck.initDeck();
  /* main loop that runs forever */
  while (true) {
    myDeck.showDeck(&myGameHardware);
    myGameHardware.setDisplayLine1("Shuffle &");
    myDeck.shuffle();
    myGameHardware.setDisplayLine2("Redisplay");
    myGameHardware.delayMilliseconds(1000);
    myDeck.showDeck(&myGameHardware);
  }
}
