//#define ITEMS_CLASS_CREATED
//#define STORE_CLASS_CREATED
//#define CHAR_CLASS_CREATED
#include <iostream>
#include <iomanip>
#include <map>

#include "HW5JsonHelper.h"
#include "HW5HelperFunctions.h"
#include "Item.h"
#include "Store.h"
#include "Character.h"
#include "json/json.h"


using namespace std;

int main(int argc, char* argv[])
{

  if (argc!=4) {
    cerr << "ERROR: Wrong command line argument format given" << endl;
    cerr << argv[0] << " <item_info.json> <store_info.json> <character_info.json>" << endl;
  }

  const std::string item_info_fn = argv[1];
  const std::string store_info_fn = argv[2];
  const std::string character_info_fn = argv[3];

  // Read the item json info file
  HW5JsonHelper itemHelper(item_info_fn);
  Json::Value item_info = itemHelper.getJsonDataStructure();
  Item::ItemMapType all_items = GetAllItems(item_info);

  // Read the store json info file
  HW5JsonHelper storeHelper(store_info_fn);
  Json::Value store_info = storeHelper.getJsonDataStructure();
  Store::StoreMapType all_stores = GetAllStores(store_info);

  // Read the character json info file
  HW5JsonHelper characterHelper(character_info_fn);
  Json::Value character_info = characterHelper.getJsonDataStructure();


  Character::CharacterMapType all_princess = GetAllCharacters(character_info["princess"]);
  for(auto char_elem : all_princess)
  {
    PrintCummulativeHealthScoresAndExpenditures(* char_elem.second,all_stores,all_items);
  }

  Character::CharacterMapType all_ogre = GetAllCharacters(character_info["ogre"]);
  for(auto char_elem : all_ogre)
  {
    PrintCummulativeHealthScoresAndExpenditures(* char_elem.second,all_stores,all_items);
  }

  Character::CharacterMapType all_fairy = GetAllCharacters(character_info["fairy"]);
  for(auto char_elem : all_fairy)
  {
    PrintCummulativeHealthScoresAndExpenditures(* char_elem.second,all_stores,all_items);
  }

  return EXIT_SUCCESS;
}
