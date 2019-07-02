/*------------------------------------------------------------------------------
 * Programmer: Guadalupe Canahuate
 * Name: game.cpp
 * Description: This file contains the function implementation for the CIE
 * My total is lower! Card Game - see game.h for documentation
 -------------------------------------------------------------------------------*/
#include <time.h>
#include <stdio.h>
#include "SingleCard.h"
#include "GameLogic.h"
#include "DeckOfCards.h"
#include "HandOfCards.h"

static int whoWins(int total1, int total2) {
}
/*Function Name: playGame
 *Programmers: Matthieu Stogsdill, Nick Grove
 *Function Description: Main function for inner workings of the game
 *Function Call: Function is called in main inside LowestScoreGame.cpp */
void playGame(int numCardsInHand, int rounds, GameConsole *consoleForPlay) {

    //Initializations
    DeckOfCards Deck;
    SingleCard gameDeck, card;
    HandOfCards Hand;
    int p = 0;

    //Eval function call
    Deck.Eval(&gameDeck, &Deck);

    //Dealer for loop
    for (int i = 0; i < NUMBER_OF_CARDS_IN_HAND; i++){

        card = Deck.getNextCard(&gameDeck);

        //Player 1's cards
        Hand.setCardAtIndex(card, i, p);
        p++;

        card = Deck.getNextCard(&gameDeck);

        //Player 2's cards
        Hand.setCardAtIndex(card, i, p);
        p++;

    }

    //Player card info for loop
    for (int i = 0; i < NUMBER_OF_PLAYERS; i++){

        Hand.printPlayerHandInfo(consoleForPlay, i);

    }

}

