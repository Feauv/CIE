//
// Created by Nick J Grove on 4/4/18.
//

#ifndef HOMEWORK5_ITEM_H
#define HOMEWORK5_ITEM_H

#include "typedef.h"
#include "PurchaseComponentBase.h"
#include "HealthStatus.h"

/** Class Name: Item
 * Class Description: This class stores everything about an Item including its name, price, description, and HealthStatus
 * Class Use: Item is used mostly in our helper functions, and basically half of what is being printed */
class Item : public PurchaseComponentBase{

public:
    // Item Map Typedef
    typedef std::map<ItemNameType,Item*>      ItemMapType;

    // Item Constructor
    Item(ItemNameType n, DescriptionType d, PriceValue p, HealthStatus hs):m_description{d},m_price{p},PurchaseComponentBase(n,hs),m_HealthStatus{hs}
    {
    }

    // Item Destructor
    ~Item(){}

    // Class Getters
    HealthStatus getHealthStatus() {return m_HealthStatus;}
    PriceValue getPrice() {return m_price;}

private:
    // Private String Variable
    DescriptionType m_description;

    // Private Double Variable
    PriceValue m_price;

    // Private HealthStatus Variable
    HealthStatus m_HealthStatus;

};

#endif //HOMEWORK5_ITEM_H
