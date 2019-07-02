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

int main() {

  GameConsole myGame;

  /* perform battery check */
  myGame.doBatteryCheck();
  myGame.setDisplayLine1("Hello");
  /* main loop that runs forever */
  while (true) {
    myGame.setDisplayLine2("CIE is the best course I have ever taken");
    myGame.UpdateDisplay();

    /* short delay */
    myGame.delayMilliseconds(1000);

    myGame.setDisplayLine2("This line is way to long to fit on the 8 character screen");
    myGame.UpdateDisplay();
    /* short delay */
    myGame.delayMilliseconds(1000);
  }
  //TODO: We will not grade this, but you will likely want to add more tests to this file.
}
