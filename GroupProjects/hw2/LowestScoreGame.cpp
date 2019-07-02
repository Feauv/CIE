/*------------------------------------------------------------------------------
 * Programmer: Guadalupe Canahuate
 * Date: 8/23/2016
 * Name: hw1.cpp
 * Description: .
 -------------------------------------------------------------------------------*/

#include "GameLogic.h"
#include "utilityFunctions.h"

/*Function Name: getNumberOfRoundsFromUser
 *Programmers: Matthieu Stogsdill, Nick Grove
 *Function Description: Function gets and returns the rounds from the user, through the robot
 *Function Call: Function called inside main */
static int getNumberOfRoundsFromUser(GameConsole * consolePointer)
{

    // Initialize rounds int and buttons
    int rounds = 0;
    char button1, button2;

    // Infinite while loop for user loop
    while(1) {

        // Initial question displayed asking how many rounds
        consolePointer->setDisplayLine1("How Many ");
        consolePointer->setDisplayLine2("3? 4? 5?");
        consolePointer->UpdateDisplay();

        consolePointer->delayMilliseconds(1000);

        consolePointer->setDisplayLine1(" Rounds ");
        consolePointer->setDisplayLine2("3? 4? 5?");
        consolePointer->UpdateDisplay();

        // Wait for button
        button1 = consolePointer->waitForButtonPress();

        // Button 1 Switch Statement
        switch( button1 )
        {
            case GAME_CONSOLE_BUTTON_LEFT:
                consolePointer->setDisplayLine1("3 Rounds");
                rounds = 3;
                break;
            case GAME_CONSOLE_BUTTON_MIDDLE:
                consolePointer->setDisplayLine1("4 Rounds");
                rounds = 4;
                break;
            case GAME_CONSOLE_BUTTON_RIGHT:
                consolePointer->setDisplayLine1("5 Rounds");
                rounds = 5;
                break;
            default:
                break;
        }

        // Display is updated with line 1 having the number of rounds you picked
        consolePointer->setDisplayLine2("");
        consolePointer->UpdateDisplay();

        consolePointer->delayMilliseconds(1000);

        // While loop asking the user if they want to confirm their round choice
        while (rounds != 0){

            //Tells user that C is to continues...
            consolePointer->setDisplayLine1("Hit C to");
            consolePointer->setDisplayLine2("Continue");
            consolePointer->UpdateDisplay();

            consolePointer->delayMilliseconds(2000);

            //...and A is to go back
            consolePointer->setDisplayLine1("Hit A to");
            consolePointer->setDisplayLine2(" Change ");
            consolePointer->UpdateDisplay();

            consolePointer->delayMilliseconds(2000);

            // Waits for button press with this question
            button2 = consolePointer->waitForButtonPress();

            // Button 2 Switch Statement
            switch( button2 )
            {
                case GAME_CONSOLE_BUTTON_LEFT:
                    rounds = 0;
                    break;
                case GAME_CONSOLE_BUTTON_RIGHT:
                    return rounds;
                default:
                    break;
            }
            

        }

        consolePointer->delayMilliseconds(1000);
        
    }
    
}

static int playAgain() {


  return 1236;
}

static void showShutdownMessage() {


}

/*Function Name: main
 *Programmers: Matthieu Stogsdill, Nick Grove
 *Function Description: The main function calls everything
 *Function Call: Its Gucci...Main*/
int main( void )
{
  GameConsole robotHardwareModel;
  robotHardwareModel.doBatteryCheck();
  robotHardwareModel.waitForButtonPress();

  /* define variables used in program */
  /*number of rounds in the game*/
  const int numberOfRounds = getNumberOfRoundsFromUser(&robotHardwareModel);

  robotHardwareModel.setDisplayLine1("Welcome!");
  robotHardwareModel.setDisplayLine2("");
  robotHardwareModel.UpdateDisplay();

  robotHardwareModel.delayMilliseconds(1000);

  playGame(NUMBER_OF_CARDS_IN_HAND, numberOfRounds, &robotHardwareModel); 

  /*TODO*/ playAgain();

  return 0;
}
