//
// Created by njgrove on 4/18/18.
//

#ifndef HOMEWORK5_STOREINVENTORYITEM_H
#define HOMEWORK5_STOREINVENTORYITEM_H

#include <iostream>
#include "typedef.h"
#include "PurchaseComponentBase.h"

/** Class Name: StoreInventoryItem
 * Class Description: This class keeps an inventory of each item in a store. It takes in the items name and the store's barcode for the item.
 * Class Use: The class is used in the Store class member function addInventoryItem to add to the StoreInventoryItemMap and used in print helper
 * function to find items */
class StoreInventoryItem {

public:
    // Store Inventory Item Map
    typedef std::map<StoreBarcode,StoreInventoryItem*>      StoreInventoryItemMapType;

    // Default Constructor
    StoreInventoryItem(){}

    // StoreInventoryItem Constructor
    StoreInventoryItem(const ItemNameType & n, StoreBarcode bc):m_name{n},m_barcode{bc}
    {
    }

    // Class Getters
    ItemNameType getName() const {return m_name;}

private:
    // Private String Variables
    const ItemNameType m_name;

    // Private Int Variables
    StoreBarcode m_barcode;

};


#endif //HOMEWORK5_STOREINVENTORYITEM_H
