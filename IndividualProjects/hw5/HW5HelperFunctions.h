//
// Created by Johnson, Hans J on 4/4/18.
//

#ifndef HOMEWORK5_HW5HELPERFUNCTIONS_H
#define HOMEWORK5_HW5HELPERFUNCTIONS_H

//#define CHAR_CLASS_CREATED
//#define STORE_CLASS_CREATED
//#define ITEMS_CLASS_CREATED

#ifdef ITEMS_CLASS_CREATED //TODO: Remove these ifdef ITEM_CLASS_CREATED ONCE YOU HAVE AN ITEMS CLASS TO TEST
#include "Item.h"
#endif

#include "Character.h"
#include "Store.h"
#include "typedef.h"
#include "json/json.h"

/**
 * @brief Create a map of characters
 * @param one_character_type_database AJson::Value that contains only 1 character type (ie. princess, or ogre)
 * @return map of characters objects
 */
extern Character::CharacterMapType GetAllCharacters(const Json::Value& one_character_type_database);

/**
 * @brief Create a map of stores
 * @param store_info_database AJson::Value that contains all the stores
 * @return map of stores objects
 */
extern Store::StoreMapType GetAllStores(const Json::Value& store_info_database);


/**
 * @brief Create a map of items
 * @param store_info_database AJson::Value that contains all the items
 * @return map of item objects
 */
extern Item::ItemMapType GetAllItems(const Json::Value& item_info_database);



/**
 * @brief A function to create summary expenditures and health metric for character purchases
 * @param oneCharacter
 * @param all_stores
 * @param all_items
 */
extern void PrintCummulativeHealthScoresAndExpenditures(Character & oneCharacter,
  const Store::StoreMapType & all_stores, const Item::ItemMapType & all_items);

#endif //HOMEWORK5_HW5HELPERFUNCTIONS_H
