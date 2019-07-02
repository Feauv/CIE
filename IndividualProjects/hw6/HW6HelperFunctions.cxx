//
// Created by Johnson, Hans J on 4/4/18.
//
#include <iostream>
#include <iomanip>
#include <array>
#include "HW6HelperFunctions.h"

using namespace std;

CharacterMapType GetAllCharacters(const Json::Value& character_info)
{
  CharacterMapType all_characters;
  const array<string, 3> characterTypeNames{"princess", "ogre", "fairy"};
  for (auto characterName : characterTypeNames) {
    const Json::Value& one_character_type_database = character_info[characterName];

    const Json::ArrayIndex num_characters = one_character_type_database.size();
    if (num_characters==0) {
      cout << "ERROR: No characters found, perhaps the wrong json file was provided for the characters." << endl;
    }

    for (Json::ArrayIndex ii = 0; ii<num_characters; ++ii) {
      Json::Value one_princess = one_character_type_database[ii];
      const string name = one_princess["name"].asString();
      Json::Value one_princess_demographics = one_princess["demographics"];
      const string home = one_princess_demographics["home"].asString();

      const double food = one_princess_demographics["opening_balance"]["food"].asDouble();
      const double clothes = one_princess_demographics["opening_balance"]["clothes"].asDouble();
      const double entertainment = one_princess_demographics["opening_balance"]["entertainment"].asDouble();
      HealthStatus opening_health_balance(food, clothes, entertainment);

      Character * oneCharacter = new Character(name, home, opening_health_balance);

      Json::Value prArray = one_princess["purchase"];
      for (Json::ArrayIndex pi = 0; pi<prArray.size(); ++pi) {
        const string store = prArray[pi]["storename"].asString();
        const int barcode = prArray[pi]["barcode"].asInt();
        PurchaseRecord* curr_purchase = new PurchaseRecord(store, barcode);

        oneCharacter->addPurchase(curr_purchase);
      }

      all_characters[name] = oneCharacter;
    }
  }
  return all_characters;
}

StoreMapType GetAllStores(const Json::Value& store_info_database)
{
  StoreMapType all_stores;
  const Json::ArrayIndex num_stores = store_info_database["store"].size();
  if (num_stores==0) {
    cout << "ERROR: No stores found, perhaps the wrong json file was provided for the stores." << endl;
  }
  for (Json::ArrayIndex ii = 0; ii<num_stores; ++ii) {
    const string name = store_info_database["store"][ii]["name"].asString();

    const double food = store_info_database["store"][ii]["quality_multipliers"]["food"].asDouble();
    const double clothes = store_info_database["store"][ii]["quality_multipliers"]["clothes"].asDouble();
    const double entertainment = store_info_database["store"][ii]["quality_multipliers"]["entertainment"].asDouble();
    HealthStatus quality_metric(food, clothes, entertainment);

    Json::Value inventoryArray = store_info_database["store"][ii]["inventory"];

    StoreBase* temp = new StoreBase(name, quality_metric);
    //TODO: Extra credit: SimulatedStore* temp = new SimulatedStore(name, quality_metric);
    for (Json::ArrayIndex vi = 0; vi<inventoryArray.size(); ++vi) {
      const string storeItemName = inventoryArray[vi]["name"].asString();
      const double storeItemBarcode = inventoryArray[vi]["barcode"].asInt();
      temp->addInventoryItem(storeItemName, storeItemBarcode);
    }
    all_stores[name] = temp;
  }
  return all_stores;
}

ItemMapType GetAllItems(const Json::Value& item_info_database)
{

  ItemMapType all_items;
  const Json::ArrayIndex num_items = item_info_database["goods"].size();
  if (num_items==0) {
    cout << "ERROR: No items found, perhaps the wrong json file was provided for the items." << endl;
  }
  for (Json::ArrayIndex ii = 0; ii<num_items; ++ii) {
    const string name = item_info_database["goods"][ii]["name"].asString();
    const string description = item_info_database["goods"][ii]["description"].asString();
    //const double price = item_info_database["goods"][ii]["price"].asDouble();
    const double food = item_info_database["goods"][ii]["health_values"]["food"].asDouble();
    const double clothes = item_info_database["goods"][ii]["health_values"]["clothes"].asDouble();
    const double entertainment = item_info_database["goods"][ii]["health_values"]["entertainment"].asDouble();
    HealthStatus hs(food, clothes, entertainment);
    Item* temp = new Item(name, description, hs);
    all_items[name] = temp;
  }
  return all_items;
}


