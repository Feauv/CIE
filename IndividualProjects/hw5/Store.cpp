//
// Created by Nick J Grove on 4/4/18.
//

#include "Store.h"
#include <map>

/** Function Name: addInventoryItem
 * Function Description: This function uses dynamically allocated memory with the StoreInventoryItem constructor to add on to the Store Inventory Map
 * Function Use: Used in the printing helper function */
void Store::addInventoryItem(const ItemNameType &i, const StoreBarcode bc) {
    // StoreInventoryItem variable initialization
    StoreInventoryItem * SII = new StoreInventoryItem(i,bc);

    // Add onto the map
    m_Inventory.insert(std::pair<int,StoreInventoryItem*>(bc,SII));
}

// Store Destructor Definition
Store::~Store(){
    // Delete the Dynamically Allocated Memory
    for (auto inventory_elem : m_Inventory){
        delete inventory_elem.second;
    }
}