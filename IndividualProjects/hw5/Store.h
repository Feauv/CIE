//
// Created by Nick J Grove on 4/4/18.
//

#ifndef HOMEWORK5_STORE_H
#define HOMEWORK5_STORE_H

#include "typedef.h"
#include "Item.h"
#include "StoreInventoryItem.h"

/** Class Name: Store
 * Class Description: This class stores all the stores and their quality multipliers (which are HealthStatus variables)
 * Class Use: Store is used mostly in our helper functions and is used alongside Item in our printing helper function */
class Store : public StoreInventoryItem, public PurchaseComponentBase{

public:
    // Store Map Typedef
    typedef std::map<StoreType,Store*>      StoreMapType;

    // Store Constructor
    Store(StoreType s, HealthStatus qm):m_quality_metric{qm},PurchaseComponentBase(s,qm)
    {
    }

    // Store Destructor
    ~Store();

    // Call of addInventoryItem
    void addInventoryItem(const ItemNameType &i, StoreBarcode bc);

    // Class Getters
    HealthStatus getQualityMultiplier() const {return m_quality_metric;}
    StoreInventoryItemMapType getInventory() const {return m_Inventory;}

private:
    // Private String Variables
    StoreType m_name;

    // Private HealthStatus Variables
    HealthStatus m_quality_metric;

    // Private Map Variable
    StoreInventoryItemMapType m_Inventory;

};




#endif //HOMEWORK5_STORE_H
