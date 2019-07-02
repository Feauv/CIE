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

    //Set card face
    char setFace(char f){
        
        face = f;
        
    }

    //Set card suit
    char setSuit(char s){
        
        suit = s;

    }

    //Set card value
    int setVal(char f){

        //Character switch statement
        switch (f){

            case 'A':
                value = 1;
            case '2':
                value = 2;
            case '3':
                value = 3;
            case '4':
                value = 4;
            case '5':
                value = 5;
            case '6':
                value = 6;
            case '7':
                value = 7;
            case '8':
                value = 8;
            case '9':
                value = 9;
            case 'T':
            case 'J':
            case 'Q':
            case 'K':
                value = 10;
            case 'X':
                value = 20;
            default:
                break;

        }

        return value;

    }

    //Sets the negation by suit
    int Negation(char s){
        
        if (s == 'H' or s == 'D'){

            return value = value*-1;
            
        }

        return value;
        
    }

    //Gets card face
    char getFace(){

        return face;

    }

    //Gets card suit
    char getSuit(){

        return suit;

    }

    //Gets card value
    int getVal(){

        return value;

    }

    //Joker Function
    void Jokers(){
        
        face = 'X';
        suit = 'X';
        value = setVal('X');
        
    }

private:
    char face;   //The face value for the card {A,2,3,4,5,6,7,8,9,T,J,Q,K}
    char suit;   //The card suit {H,D,S,C}
    int value;   //The value of the card for the game: Red suits (H,D) have negative values,
                 //Black suits (S,C) have positive values. A=1, {T,J,Q,K}=10, rest have their face value.
    
    char faces[54];
    char suits[54];
};

#endif // CARD_H
