//
// Created by Johnson, Hans J on 4/4/18.
//
#include <iostream>
#include <iomanip>
#include "HW5HelperFunctions.h"
#include "typedef.h"
#include "json/json.h"
#include <map>
using namespace std;

/************************************************
   Did Not Comment Through the Helper Functions
 ************************************************/

Character::CharacterMapType GetAllCharacters(const Json::Value& one_character_type_database)
{
  Character::CharacterMapType all_of_one_character_type;
  const Json::ArrayIndex num_characters = one_character_type_database.size();
  if ( num_characters == 0 )
  {
    cout << "ERROR: No stores found, perhaps the json file was provided for the stores." << endl;
  }
  for (Json::ArrayIndex ii = 0; ii<num_characters; ++ii) {
    Json::Value one_princess = one_character_type_database[ii];
    const string name = one_princess["name"].asString();
    Json::Value one_princess_demographics = one_princess["demographics"];
    const string home = one_princess_demographics["home"].asString();

    const double food = one_princess_demographics["opening_balance"]["food"].asDouble();
    const double clothes = one_princess_demographics["opening_balance"]["clothes"].asDouble();
    const double entertainment = one_princess_demographics["opening_balance"]["entertainment"].asDouble();
    HealthStatus opening_balance(food, clothes, entertainment);

    PurchaseRecord::PurchaseRecordVectorType pr;
    Json::Value prArray = one_princess["purchase"];
    for (Json::ArrayIndex pi = 0; pi<prArray.size(); ++pi) {
      const string store = prArray[pi]["storename"].asString();
      const int barcode = prArray[pi]["barcode"].asInt();
      PurchaseRecord * temp = new PurchaseRecord(store, barcode);
      pr.push_back(temp);
    }

    Character * temp = new Character(name, home, opening_balance, pr);
    all_of_one_character_type[name] = temp;
  }
  return all_of_one_character_type;
}

Store::StoreMapType GetAllStores(const Json::Value& store_info_database)
{
  Store::StoreMapType all_stores;
  const Json::ArrayIndex num_stores = store_info_database["store"].size();
  if ( num_stores == 0 )
  {
    cout << "ERROR: No stores found, perhaps the json file was provided for the stores." << endl;
  }
  for (Json::ArrayIndex ii = 0; ii< num_stores; ++ii) {
    const string name = store_info_database["store"][ii]["name"].asString();
    const double food = store_info_database["store"][ii]["quality_multipliers"]["food"].asDouble();
    const double clothes = store_info_database["store"][ii]["quality_multipliers"]["clothes"].asDouble();
    const double entertainment = store_info_database["store"][ii]["quality_multipliers"]["entertainment"].asDouble();
    HealthStatus quality_metric(food, clothes, entertainment);

    Json::Value inventoryArray = store_info_database["store"][ii]["inventory"];

    Store *temp = new Store(name, quality_metric);
    for (Json::ArrayIndex vi = 0; vi<inventoryArray.size(); ++vi) {
      const string storeItemName = inventoryArray[vi]["name"].asString();
      const double storeItemBarcode = inventoryArray[vi]["barcode"].asInt();
      temp->addInventoryItem(storeItemName, storeItemBarcode);
    }
    all_stores[name] = temp;
  }
  return all_stores;
}

Item::ItemMapType GetAllItems(const Json::Value& item_info_database)
{

  Item::ItemMapType all_items;
  const Json::ArrayIndex num_items = item_info_database["goods"].size();
  if ( num_items == 0 )
  {
    cout << "ERROR: No stores found, perhaps the json file was provided for the stores." << endl;
  }
  for (Json::ArrayIndex ii = 0; ii<num_items; ++ii) {
    const string name = item_info_database["goods"][ii]["name"].asString();
    const string description = item_info_database["goods"][ii]["description"].asString();
    const double price = item_info_database["goods"][ii]["price"].asDouble();
    const double food = item_info_database["goods"][ii]["health_values"]["food"].asDouble();
    const double clothes = item_info_database["goods"][ii]["health_values"]["clothes"].asDouble();
    const double entertainment = item_info_database["goods"][ii]["health_values"]["entertainment"].asDouble();
    HealthStatus hs(food, clothes, entertainment);
    Item * temp = new Item(name, description, price, hs);
    all_items[name]=temp;
  }
  return all_items;
}

void PrintCummulativeHealthScoresAndExpenditures(Character & oneCharacter,
  const Store::StoreMapType & all_stores, const Item::ItemMapType & all_items)
{
  cout << "Character " << oneCharacter.getName() << " purchased: " << endl;

  double monthlyExpenditures = 0.0;
  double F, C, E;
  for(auto purchase_elem : oneCharacter.getPurchase_list() )
  {

    const string store_name = purchase_elem->getStore();
    const int barcode = purchase_elem->getBarcode();
    const Store * curr_store = all_stores.at(store_name);
    const HealthStatus & curr_store_quality_multiplier = curr_store->getQualityMultiplier();
    const Store::StoreInventoryItemMapType & curr_store_inventory = curr_store->getInventory();
    const StoreInventoryItem * curr_store_item = curr_store_inventory.at(barcode);
    const string & item_name = curr_store_item->getName();

    const HealthStatus itemHealthStatus = all_items.at(item_name)->getHealthStatus();
    const double item_cost = all_items.at(item_name)->getPrice();

    monthlyExpenditures += item_cost;

    const double FV = itemHealthStatus.getFoodVal();
    const double CV = itemHealthStatus.getClothesVal();
    const double EV = itemHealthStatus.getEntVal();

    const double FQM = curr_store_quality_multiplier.getFoodVal();
    const double CQM = curr_store_quality_multiplier.getClothesVal();
    const double EQM = curr_store_quality_multiplier.getEntVal();

    F += FV*FQM;
    C += CV*CQM;
    E += EV*EQM;

    oneCharacter.HealthScoreUpdateC(F,C,E);

    cout << "     " << item_name << " at " << store_name <<" for $" << item_cost << endl;

  }

  cout << " Monthy total $" << std::fixed << std::setprecision(2) << std::setfill('0') << monthlyExpenditures
       << " resulting in health metrics of " << endl
       << oneCharacter.getHealthStatus().toString() << endl;
  cout << "------------------------------------------------" << endl;
}

