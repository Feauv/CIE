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

  /* main loop that runs forever */
  while (true) {
    myGame.setDisplayLine1("PressBTN");
    myGame.setDisplayLine2("");
    myGame.UpdateDisplay();

    char button = myGame.waitForButtonPress();
    switch( button )
    {
      case GAME_CONSOLE_BUTTON_LEFT:
        myGame.setDisplayLine2("  A-BTN");
        break;
      case GAME_CONSOLE_BUTTON_MIDDLE:
        myGame.setDisplayLine2("  B-BTN");
        break;
      case GAME_CONSOLE_BUTTON_RIGHT:
        myGame.setDisplayLine2("  C-BTN");
        break;
      default:
        break;
    } /* end switch */
    myGame.setDisplayLine1("YouPress");
    myGame.UpdateDisplay();
    myGame.delayMilliseconds(500);
  }
}
