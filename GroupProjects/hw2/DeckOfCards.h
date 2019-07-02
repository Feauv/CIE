//
// Created by Hans J. Johnson on 2/7/18.
//

#ifndef HW2_DECKOFCARDS_H
#define HW2_DECKOFCARDS_H

#include "SingleCard.h"
#include "GameConsole.h"

/*number of cards in a suit*/
static const int NUM_CARDS_IN_SUIT = 13;
/*symbols to represent the cards of a suit*/

/*symbols to represent the suits*/
static const char NUM_SUITS = 4;

static const char NUM_JOKERS = 2;


/*number of cards in the m_Deck*/
static const int NUM_CARDS_IN_DECK = NUM_CARDS_IN_SUIT * NUM_SUITS + NUM_JOKERS;

static const int NUMBER_OF_PLAYERS = 2;


class DeckOfCards {
public:

    void shuffle();
    void initDeck();
    void showDeck(GameConsole *currentConsole);
    SingleCard getNextCard(SingleCard * deck);

    //Evaluate function
    void Eval(SingleCard * a, DeckOfCards * Game);

private:
    SingleCard * m_Deck;
    int m_indexForDeckOfCards;

};


#endif //HW2_DECKOFCARDS_H
