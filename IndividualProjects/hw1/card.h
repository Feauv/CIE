 /*------------------------------------------------------------------------------
 * Programmer: Guadalupe Canahuate (Revised by Hans J. Johnson)
 * Name: card.h
 * Description: This file contains the structure definition for the cards to be
 * used in the CIE My total is lower! Card Game
 -------------------------------------------------------------------------------*/
#ifndef CARD_H
#define CARD_H

class  SingleCard {
  public:
    char face;   //The face value for the card {A,2,3,4,5,6,7,8,9,T,J,Q,K}
    char suit;   //The card suit {H,D,S,C}
    int value;   //The value of the card for the game:  A=1, {T,J,Q,K}=10, rest have their face value.

};

extern void printCard (SingleCard c);
#endif // CARD_H
