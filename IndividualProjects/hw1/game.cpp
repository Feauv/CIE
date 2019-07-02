/*------------------------------------------------------------------------------
 * Programmer: Guadalupe Canahuate
 * Name: game.cpp
 * Description: This file contains the function implementation for the CIE
 * My total is lower! Card Game - see game.h for documentation
 -------------------------------------------------------------------------------*/
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "card.h"
#include "game.h"
#include "utilityFunctions.h"

using namespace std;

/*number of cards in a suit*/
static const int NUM_CARDS_IN_SUIT = 13;
/*symbols to represent the cards of a suit*/
static const char faces[NUM_CARDS_IN_SUIT] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
/*symbols to represent the suits*/
static const char NUM_SUITS = 4;
static const char suits[NUM_SUITS] = {'H', 'D', 'S', 'C'};

static const char NUM_JOKERS = 2;

static const int values[NUM_CARDS_IN_SUIT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

static const int NUMBER_OF_PLAYERS = 2;

/*number of cards in the deck*/
static const int NUM_CARDS_IN_DECK = NUM_CARDS_IN_SUIT * NUM_SUITS + NUM_JOKERS;

/* Function Name: initDeck
 * Function Description: This function initialize the entire deck and returns it to playGame
 * Function Call: Function is called from the playGame function in the game.cpp file. */
void initDeck (SingleCard deck[]) {

    // Initialize the a single because we initialize the deck card by card
    SingleCard initCard;
    int counter = 0;

    // Suits for loop
    for (int i = 0; i < NUM_CARDS_IN_SUIT; i++) {

        // Faces for loop
        for (int j = 0; j < NUM_SUITS; j++) {

            // Set each element of the card equal to our single card
            initCard.face = faces[i];
            initCard.suit = suits[j];
            initCard.value = values[i];

            // Set it equal to its spot in the deck
            deck[counter] = initCard;

            // Add onto the counter for the deck
            counter++;

        }

    }

    char joker = 'X';

    // Jokers for loop
    for (int i = 0; i < NUM_JOKERS; i++){

        // Set jokers' elements equal to the single card
        initCard.face = joker;
        initCard.suit = joker;
        initCard.value = 20;

        // Set to its spot in the deck
        deck[52+i] = initCard;

    }

}

/* Function Name: shuffle
 * Function Description: This function shuffles our newly initialized deck by utilizing a random numbers as spots in the deck array
 * Function Call: Function is called from the playGame function in the game.cpp file. */
void shuffle(SingleCard deck[], int n){

    // Temporary variable
    SingleCard temp;

    // Rand Seed
    srand(time(0));

    // For loop for shuffled spot assignment
    for (int i = 0; i < 54; i++){

        // Random number
        int randNum = rand()%54;

        // Set to new spot
        temp = deck[i];
        deck[i]=deck[randNum];
        deck[randNum] = temp;

    }

}

/* Function Name: printCardArray
 * Function Description: Prints any card array by using the printCard function
 * Function Call: Function is called from the printPlayerHandinfo and playGame function in the game.cpp file. */
void printCardArray(SingleCard a[], int n){

    for (int i = 0; i < n; i++){
        printCard(a[i]);
    }

}

/* Function Name: printPlayerHandInfo
 * Function Description: This function prints the player's name, prints the player's hand by in the printCardArray function, and
 * prints the score and values for each card with the computeTotalAndPrintCardScoresValues function.
 * Function Call: Function is called from the playGame function in the game.cpp file. */
int printPlayerHandInfo(std::string playerName, SingleCard playerHand[], int numCards){

    // Initialize score integer
    int score;

    // Displays the player's hand by using the printCardArray function
    cout << endl << playerName << "'s Hand:" << endl;
    printCardArray(playerHand, numCards);

    // Displays the player's card values and score by using the computeTotalAndPrintCardScoreValues
    cout << endl << endl << playerName << "'s Hand Values:" << endl;
    score = computeTotalAndPrintCardScoreValues(playerHand, numCards);

    // Returns score to playGame function
    return score;

}

/* Function Name: computeTotalAndPrintCardScoreValues
 * Function Description: This function displays the cards' individual values and sums up their values
 * Function Call: Function is called from the printPlayerHandInfo function in the game.cpp file. */
int computeTotalAndPrintCardScoreValues(SingleCard a[], int n){

    // Value array and sum intialized
    int value[n], sum = 0;

    // This for loop just sets numbers to their respective values from the start
    for (int i = 0; i < n; i++){

        value[i] = a[i].value;

    }

    // Nested for loops go through each number in the hand and compares them to each other
    for (int i = 0; i < n; i++){

        for (int j = 0; j < n; j++){

            // If two cards who are not the same card have the same fave then their values can be set to zero
            if ( i != j and a[i].face == a[j].face){

                value[i] = 0;
                value[j] = 0;

            }

        }

    }

    // This for loop prints the values and sums them
    for (int i = 0; i < n; i++){

        // Prints
        cout << value[i] << "  ";

        // Sums
        sum += value[i];

    }

    // Prints and returns sum
    cout << "{--- Score: " << sum << " ---}";
    return sum;

}

/* Function Name: whoWins
 * Function Description: This function decides based on the final scores, who is the winner.
 * Function Call: Function is called from the printPlayerHandInfo function in the game.cpp file. */
int whoWins (int a[], int n){

    // Initialize large min and the return value
    int min = 1000, winner;

    // In the situation of a tie
    if (a[0] == a[1]){

        //Return -1
        return winner = -1;

    }

    // For loop finds player with lowest score
    for (int i =0; i < n; i++){

        // Makes lowest min
        if (a[i] < min){

            min = a[i];
            winner = i;

        }

    }

    // Returns the int that represents the player that way
    return winner;

}

/* Function Name: playGame
 * Function Description: The playGame function acts as kind of an evaluate function for game.cpp while also running the core elements of the
 * game. It is an evaluate function because it calls every function that game.cpp is able to use, inside of it. It also run many big parts
 * of the games in itself, such as keeping track of the player's selections, such as discards and card pick ups.
 * Function Call: Function is called from main in the hw1.cpp file. */
void playGame (int nCards, int rounds) {

    // Initialize deck array and call the function that makes the deck
    SingleCard deck[54];
    initDeck(deck);

    // Call the shuffle function as soon as we have made the deck
    shuffle(deck, nCards);

    // Printing shuffled deck to the screen
    cout << endl;
    printCardArray(deck, 54);
    cout << endl;

    // Initialize our arryas that stor a player's hand and the players' names, also initializing some counters and our score array
    SingleCard playerHand[NUMBER_OF_PLAYERS][nCards];
    string playerName[NUMBER_OF_PLAYERS];
    int dealercount = 0, playercount = 0, score[NUMBER_OF_PLAYERS];
    string enter;

    // Dealer for loop
    for (int i = 0; i < nCards; i++) {

        playerHand[playercount][i] = deck[dealercount];
        dealercount++;
        playercount++;
        playerHand[playercount][i] = deck[dealercount];
        dealercount++;
        playercount--;

    }

    // For loop to show the hand and card values for each player
    for (int i = 0; i < NUMBER_OF_PLAYERS; i++){

        // Player name entry
        cout << endl << "Player " << (i+1) << "'s Name: ";
        cin >> playerName[i];

        // Call of printPlayerHandInfo function
        score[i] = printPlayerHandInfo(playerName[i], playerHand[i], nCards);

        cout << endl << endl;

    }

    // After the last player has been dealt his cards he must hit enter to continue
    cout << "Now that you both have been dealt your hands are your to play? (type 'yes' to continue)" << endl;
    cin >> enter;

    // All initializations for the actual game part of the code
    SingleCard discard[2*rounds+1], cardchoice;
    int discardcount = 0, deckcount = 0, choice, spot, winner;

    // Round for loop
    for (int r = 0; r < rounds; r++){

        // Print round number to the screen
        cout << endl << "-|-|-|-|-|-|-|-|-Round " << r+1 << "-|-|-|-|-|-|-|-|-" << endl;
        cout << "*****************************************" << endl << endl;

        // Putting top card in in discard pile
        if (r == 0){

            discard[0] = deck[2*nCards];

            // Add to the deck and discard counter
            discardcount++;
            deckcount++;

        }

        // Turn for loop
        for (int turn = 0; turn < NUMBER_OF_PLAYERS; turn++){

            // Displays who's turn it is
            cout << playerName[turn] << "'s Turn..." << endl << endl;

            // Displays top discard pile card
            cout << "{--- Discard Pile Card: ";
            printCard(discard[discardcount-1]);
            cout << "---}" << endl << endl;

            // Discard Pile or Deck?
            cout << "Do you want to pick from the discard pile (type the number 1), or the deck (type 2)?:" << endl;

            // Shows hand before choice
            score[turn] = printPlayerHandInfo(playerName[turn], playerHand[turn], nCards);

            // User input for their choice
            cout << endl << endl;
            cin >> choice;
            cout << endl;

            // Discard Choice
            if (choice == 1){

                cardchoice = discard[discardcount-1];

                // Minus the discard counter
                discardcount--;

                // Displays the card that is printed
                cout << "{--- Card Pick ";
                printCard(cardchoice);
                cout << "---}" << endl << endl;

            }

            // Deck Choice
            if (choice == 2){

                cardchoice = deck[2*nCards+deckcount];

                // Add to deck counter
                deckcount++;

                // Displays card pick
                cout << "{--- Card Pick: ";
                printCard(cardchoice);
                cout << "---}" << endl << endl;

            }

            // Choice of what card you want to discard
            cout << "What card do you want to discard from your hand (type the spot of the card, so 1-" << nCards << " or type 0 for the card you picked up):" << endl;
            score[turn] = printPlayerHandInfo(playerName[turn], playerHand[turn], nCards);
            cout << endl << endl;
            cin >> spot;

            // If statement so you can discard the card you picked up
            if(spot == 0){

                // Adding to discard pile
                discard[discardcount] = cardchoice;
                discardcount++;

                //Hand is not changed

            }else{

                // Adding to discard pile
                discard[discardcount] = playerHand[turn][spot-1];
                discardcount++;
                playerHand[turn][spot-1] = cardchoice;

            }

            // Call the printPlayerHandInfo
            score[turn] = printPlayerHandInfo(playerName[turn], playerHand[turn], nCards);

            cout << endl << endl;

        }

    }

    // Calls the whoWins function
    winner = whoWins(score, NUMBER_OF_PLAYERS);

    // If statement for a tie
    if (winner == -1){

        //Displays a tie
        cout << "It is a tie!" << endl << endl;

    }else{

        // Displays winner
        cout << "The winner is " << playerName[winner] << " with a score of " << score[winner] << "!" << endl << endl;

    }

}

