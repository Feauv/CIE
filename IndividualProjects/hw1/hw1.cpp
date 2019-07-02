/*------------------------------------------------------------------------------
 * Programmer: Guadalupe Canahuate
 * Date: 8/23/2016
 * Name: hw1.cpp
 * Description:
 -------------------------------------------------------------------------------*/
#include <iostream>
#include "game.h"
#include "utilityFunctions.h"

using namespace std;

static int getNumberFromUser(std::string Prompt, int lowRange, int highRange)
{
  int userEnteredNumber = 0;
  do{
    cout << Prompt << endl;
    cin >> userEnteredNumber;
  } while ( userEnteredNumber < lowRange || userEnteredNumber > highRange);
  return userEnteredNumber;
}

int main( void ) {

    // The user input number of rounds and cards, and a variable to keep the while loop going
    int numR = 0, numC = 0, tooMuch = 0;

    // String for when they want to keep playing or not
    string YorN;

    // This while loop will keep looping if the user enters a certain amount of rounds and cards that will cause the two players to run out of cards
    while (tooMuch != -1){

        cout << "Welcome to My Total is Lower" << endl << endl;

        // User input for rounds
        cout << "How many rounds would you like to play?" << endl;
        cin >> numR;
        cout << endl;

        // User input for cards
        cout << "How many cards do want each player to get?" << endl;
        cin >> numC;
        cout << endl;

        // If statement to check that this combination of rounds and cards is possible
        if ((2 * numC + 2 * numR) < 55) {

            // Initialize rounds and cards to constant variables
            const int numberOfRounds = numR;
            const int numberOfCards = numC;

            // Call the playGame function
            playGame(numC, numR);

            // Yes or No question to play some more
            cout << "Do you want to play again? Type (Y/N):" << endl;
            cin >> YorN;
            cout << endl;

            // If statement that examines your answer
            if (YorN == "Y"){

                tooMuch = 1;

            }
            else{

                tooMuch = -1;

            }

        }


        if (tooMuch == 0){

            // Statement to user that they will need to enter in rounds and cards again
            cout << "Too many rounds and cards dealt for the number of players you have. Please enter again." << endl;
            cout << "**************************************************************************************" << endl << endl;

        }
    }

    /* print exit message */
    printCharArray("Thank you for playing.\n");
    return 0;
}
