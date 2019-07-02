//
// Created by Johnson, Hans J on 4/21/18.
//

#include "CharacterBase.h"
#include "Character.h"

Character::Character(const string & name, const string & home, const HealthStatus& hs)
 :CharacterBase(std::string{name}, std::string{home}, HealthStatus{hs})
{
}

/* Function Name: UpdateHealthStatus
 * Function Description: This function calculates your new Health Status based on your new purchase list
 * Function Input: all_stores, all_items
 * Function Output: Void function, no ouput
 */
void Character::UpdateHealthStatus(const StoreMapType& all_stores, const ItemMapType& all_items)
{

  // Construct new Health Status
  HealthStatus NewHS(0,0,0);
  for (auto purchase_elem : this->getPurchase_list()){

    // Retrieve store info and get the quality multiplier
    const string store_name = purchase_elem->getStore();
    const int barcode = purchase_elem->getBarcode();
    const StoreBase * curr_store = all_stores.at(store_name);
    HealthStatus curr_store_quality_multiplier = curr_store->getQualityMultiplier();

    // Retrieve item info and get the item Health Status
    const StoreInventoryItemMapType & curr_store_inventory = curr_store->getInventory();
    const StoreInventoryItem * curr_store_item = curr_store_inventory.at(barcode);
    const string & item_name = curr_store_item->getName();
    HealthStatus itemHealthStatus = all_items.at(item_name)->getHealthStatus();

    // Add onto the new Health Status
    NewHS+=(itemHealthStatus*curr_store_quality_multiplier);

  }

  // Set the character's Health Status to the new Health Status
  this->setHealthStatus(NewHS);

}

bool Character::DisplayHealthStatus(const StoreMapType& all_stores, const ItemMapType& all_items)
{

  // Call UpdateHealthStatus
  this->UpdateHealthStatus(all_stores, all_items);

  // Print character's Health Status
  cout << "\t\t-------------------------------------------------------" << endl;
  cout << "\t\t" << this->getName() << "'s Health Status: " << this->getHealthStatus().toString();

  // Check for death
  if(this->getHealthStatus().getFood() <= 0){

    cout << "\t\t\t\t\t .·´¯`(>▂<)´¯`·." << this->getName() << " died of starvation" << endl;
    return true;

  }if(this->getHealthStatus().getClothes() <= 0){

    cout << "\t\t\t\t\t .·´¯`(>▂<)´¯`·." << this->getName() << " died of embarassment" << endl;
    return true;

  }if(this->getHealthStatus().getEntertainment() <= 0){

    cout << "\t\t\t\t\t  .·´¯`(>▂<)´¯`·." << this->getName() << " died of bordom" << endl;
    return true;

  }

  return false;

}
