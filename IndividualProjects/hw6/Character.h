//
// Created by Johnson, Hans J on 4/2/18.
//

#ifndef HOMEWORK5_CHARACTER_H
#define HOMEWORK5_CHARACTER_H

#include "CharacterBase.h"

class Character
  : public CharacterBase {

public:
  Character(const string & name, const string & home, const HealthStatus& hs);

  /**
   * @brief Display the current health status of the player from the current mall environment
   * @param all_stores -- All the store in the Mall
   * @param all_items  --- All the items in the Mall
   * @return True if all health aspects are good, false otherwise.
   */
  bool DisplayHealthStatus(const StoreMapType& all_stores, const ItemMapType& all_items);

  /**
   * @brief Compute the current health status for this character
   */
  void UpdateHealthStatus(const StoreMapType& all_stores, const ItemMapType& all_items);

    // Getter for the character's active store
    StoreMapType::iterator getActStore() {return m_activeStore;}

    // Setter for the character's active store
    void setActStore(StoreMapType::iterator aS) {m_activeStore = aS;}

private:
    StoreMapType::iterator m_activeStore;



};

typedef map<string, Character *> CharacterMapType;
#endif //HOMEWORK5_CHARACTER_H
