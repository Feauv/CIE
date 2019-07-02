//
// Created by Hans J. Johnson on 2/7/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "DeckOfCards.h"
#include <time.h>

// Face and Suit arrays
static const char faces[NUM_CARDS_IN_SUIT] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
static const char suits[NUM_SUITS] = {'H', 'D', 'S', 'C'};

/*Function Name: shuffle
 *Programmer:Nick Grove
 *Function Description: the shuffle function takes in the deck from initdeck and shuffles the cards
 *Function Call: Function is called in the play game function. */
void DeckOfCards::shuffle()
{
    //Initialization of SingleCard variables
    SingleCard temp, card, randCard;

    //Random seed
    srand(time(0));

    //Shuffle for loop
    for (int i = 0; i < NUM_CARDS_IN_DECK; i++){

        //Random number
        int randNum = rand()%NUM_CARDS_IN_DECK;

        //Deck pointers into cards
        randCard = *(m_Deck+randNum);
        card = *(m_Deck+i);

        //Switching the cards
        temp.setFace(card.getFace());
        temp.setSuit(card.getSuit());
        temp.setVal(card.getFace());
        card.setFace(randCard.getFace());
        card.setSuit(randCard.getSuit());
        card.setVal(randCard.getFace());
        randCard.setFace(temp.getFace());
        randCard.setSuit(temp.getSuit());
        randCard.setVal(temp.getFace());

        //Random Card added back onto deck pointer.
        *(m_Deck+randNum) = randCard;

    }

}

/*Function Name: initDeck
 *Programmer: Matthieu Stogsdill
 *Function Description: this function initializes the deck by calling SingleCard set functions
 *Function Call: Function is called in the play game function. */
void DeckOfCards::initDeck()
{

  // Initializes card and deck counter
  SingleCard card;
  int deckCount = 0;

  // Nested for loops for making the deck
  for (int i = 0; i < NUM_CARDS_IN_SUIT; i++){

    for (int j = 0; j < NUM_SUITS; j++){

        // Use of SingleCard set functions
        card.setFace(faces[i]);
        card.setSuit(suits[j]);
        card.setVal(faces[i]);
        card.Negation(suits[j]);

        // Set card to the deck
        *(m_Deck+deckCount) = card;

        deckCount++;


    }

  }
    // Joker for loop
    for (int i = 0; i < NUM_JOKERS; i++){

        // Call joker function
        card.Jokers();

        // Assign card to deck
        *(m_Deck+deckCount) = card;

        deckCount++;

    }

}

/*Function Name: showDeck
 *Programmer: Nick Grove
 *Function Description: this function shows the deck
 *Function Call: Function is called in the inside the file made for print testing */
void DeckOfCards::showDeck(GameConsole *currentConsole) {

// Initializes card, print array, and array counter
SingleCard card;
char printArray[8];
int arrayCount = 0;

// Index attribute set to zero
m_indexForDeckOfCards = 0;

// 2 and 5 spots of array are set to blank
printArray[2] = ' ';
  printArray[5] = ' ';

  // Nested for loops for printing
  for (int i = 0; i < NUM_CARDS_IN_SUIT; i++){

      for (int j = 0; j < NUM_SUITS; j++){

          // Set card's face and suit equal to the print array
          printArray[arrayCount] = card.getFace();
          arrayCount++;
          printArray[arrayCount] = card.getSuit();
          arrayCount++;

          // get the next card
          card = getNextCard(m_Deck);

          // This if-else either resets the array or adds 1 to the counter
          if (arrayCount > 7){

              // Set display line and print array
              currentConsole->setDisplayLine1(printArray);
              currentConsole->UpdateDisplay();

              currentConsole->delayMilliseconds(1000);

              // Reset array
              arrayCount = arrayCount-8;

          }else{

              arrayCount++;

          }

      }

  }

  m_indexForDeckOfCards = 0;

}

/*Function Name: Eval
 *Programmer: Matthieu Stogsdill
 *Function Description: evaluates the main functions of DeckOfCards (initDeck, shuffle)
 *Function Call: Function is called in the play game function */
void DeckOfCards::Eval(SingleCard * a, DeckOfCards * Game){

    //DeckOfCards functions called
    Game->initDeck();
    Game->shuffle();

    // Array set equal to the deck
    a = m_Deck;

}

/*Function Name: getNextCard
 *Programmer: Nick Grove
 *Function Description: gets the next card in the deck pointer
 *Function Call: Function is called throughout the code*/
SingleCard DeckOfCards::getNextCard(SingleCard * deck)
{
  // Top card is assigned
  SingleCard topCard = *(deck+m_indexForDeckOfCards);
  m_indexForDeckOfCards++;
  return topCard;
}