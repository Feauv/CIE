//
// Created by Johnson, Hans J on 4/4/18.
//

#ifndef HOMEWORK6_HW6HELPERFUNCTIONS_H
#define HOMEWORK6_HW6HELPERFUNCTIONS_H

#include "Item.h"
#include "Character.h"
#include "SimulatedStore.h"

/**
 * @brief Create a map of characters
 * @param one_character_type_database AJson::Value that contains only 1 character type (ie. princess, or ogre)
 * @return map of characters objects
 */
extern CharacterMapType GetAllCharacters(const Json::Value& one_character_type_database);

/**
 * @brief Create a map of stores
 * @param store_info_database AJson::Value that contains all the stores
 * @return map of stores objects
 */
extern StoreMapType GetAllStores(const Json::Value& store_info_database);

/**
 * @brief Create a map of items
 * @param store_info_database AJson::Value that contains all the items
 * @return map of item objects
 */
extern ItemMapType GetAllItems(const Json::Value& item_info_database);

#endif //HOMEWORK6_HW6HELPERFUNCTIONS_H
