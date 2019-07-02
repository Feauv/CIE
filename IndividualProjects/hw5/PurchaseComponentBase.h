//
// Created by njgrove on 4/18/18.
//

#ifndef HOMEWORK5_PURCHASECOMPONENTBASE_H
#define HOMEWORK5_PURCHASECOMPONENTBASE_H

#include "typedef.h"
#include "HealthStatus.h"

/** Class Name: PurchaseComponentBase
 * Class Description: All of the main classes used in the helper functions (Item, Character, Store) can lead to PurchaseComponentBase, because each
 * has a name and HealthStatus
 * Class Use: It is mostly used within the Item, Store, and Charcter classes */
class PurchaseComponentBase : public HealthStatus{

public:
    // Default Constructor
    PurchaseComponentBase(){}

    // PurchaseComponentBase Constructor
    PurchaseComponentBase(GenNameType n, HealthStatus hs):m_name{n},m_HealthStatus{hs},HealthStatus(hs)
    {
    }

    // Class Getters
    HealthStatus getHealthStatus() { return m_HealthStatus;}

    // Declaration of AddToHealthScore
    void HealthScoreUpdatePCB(FoodValue f, ClothesValue c, EntertainmentValue e);

private:
    // Private String Variables
    const ItemNameType m_name;

    // Private HealthStatus Variables
    HealthStatus m_HealthStatus;

};


#endif //HOMEWORK5_PURCHASECOMPONENTBASE_H
