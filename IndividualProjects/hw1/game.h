/*------------------------------------------------------------------------------
 * Programmer: Guadalupe Canahuate
 * Name: game.h
 * Description: This file contains the function prototypes to be
 * implemented in the CIE My total is lower! Card Game
 -------------------------------------------------------------------------------*/
#ifndef CARD_H__
#define CARD_H__

#include "card.h"

/* prototype of the function to shuffle a deck*/
extern void shuffle(SingleCard deck[], int n);

/* prototype of the function to print the cards in an array */
extern void printCardArray(SingleCard a[], int n);

/* prototype of the function to compute the score for an array of cards */
extern int computeTotalAndPrintCardScoreValues(SingleCard a[], int n);

/* prototype of the function to play the CIE My total is lower! Game */
extern void playGame (int nCards, int rounds);

// Changed the whoWins function to better suit my code
/* prototype of the function to decide the winner of the CIE My total is lower! Game */
extern int whoWins (int a[], int n);

/* prototype of the function to initialize the deck for the CIE My total is lower! Game */
extern void initDeck (SingleCard deck[]);

/* prototype of the function to print off a information about a players hand. */
extern int printPlayerHandInfo(std::string playerName, SingleCard playerHand[], int numCards);

#endif // CARD_H__
