//
// Created by Johnson, Hans J on 4/20/18.
//
// The mall game class provides the state and behaviors necessary
// for implementing a game.  In this game, characters are travel through
// the mall making purchases, and loosing purchases.
//
// The mall game is organized as a loop of stores, and as each
// character moves from store to store during their turn, they
// can make purchases or loose purchases from their purchase list.
//
// The characters continue playing until they are experience one of the
// following situations:
//      1) Die from hunger (cumulative food health status < 0 )
//      2) Die from boredom (cumulative entertainment health status < 0)
//      3) Die from embarrassment (cumulative clothes health status < 0)
//
// The rules for the game are as follows:
//    a) A character rolls a 6 sided dice to start their turn
//               The player moves forward the number of stores shown on the dice
//    b) A character rolls the dice again
//          If it is an odd number
//               must remove that many items from their purchase list
//          If it is an even number
//             The character must make a single purchase from
//    b) The character must update and display their current cummulative health status to the screen.
//         If any of the situations listed above (die, or goto jail), then that player is removed from the game.
//    c) If there is only 1 player left, that player is the winner of the game, and the game terminates.
//
//
//

#ifndef HOMEWORK5_MALLGAME_H
#define HOMEWORK5_MALLGAME_H

#include "SimulatedStore.h"
#include "Character.h"
#include "Item.h"

class MallGame {
public:
  /**
   * @brief
   * @param item_info_fn  Name of json file
   * @param store_info_fn Name of json file
   * @param character_info_fn Name of json file
   */
  MallGame(const string& item_info_fn, const string& store_info_fn, const string& character_info_fn);

  /**
   * @brief Run the simulation to completion
   * @return The name of the character that survives the longest
   */
  string Play();
  void movePlayerToNextStore(StoreMapType::iterator aS, int bV);

  ~MallGame();

  bool isOddRoll(const int roll_value) const;


  CharacterMapType m_CharacterMap;
  StoreMapType m_StoreMap;
  ItemMapType m_ItemMap;

  CharacterMapType::iterator m_activePlayer;
  StoreMapType::iterator m_activeStore;
  vector<std::string> m_deadCharacters;

};

#endif //HOMEWORK5_MALLGAME_H
