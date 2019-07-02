/*------------------------------------------------------------------------------
 * Programmer: Guadalupe Canahuate
 * Name: game.h
 * Description: This file contains the function prototypes to be
 * implemented in the CIE My total is lower! Card Game
 -------------------------------------------------------------------------------*/
#ifndef GAME_H__
#define GAME_H__

#include "SingleCard.h"
#include "GameConsole.h"

/* prototype of the function to play the CIE My total is lower! Game */
extern void playGame (int numCardsInHand, int rounds, GameConsole * consoleForPlay);

#endif // GAME_H__
