//
// Created by Johnson, Hans J on 4/2/18.
//

#ifndef HOMEWORK6_STOREBASE_H
#define HOMEWORK6_STOREBASE_H

#include "Item.h"
#include "StoreInventoryItem.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "PurchaseComponentBase.h"

using namespace std;

class StoreBase : public PurchaseComponentBase {
public:

  StoreBase(const string name, const HealthStatus& hs);

  const HealthStatus& getQualityMultiplier() const;

  const StoreInventoryItemMapType& getInventory() const;

  void addInventoryItem(const string& storeItemName, const double& storeItemBarcode);

  /**
   * @brief Displays a menu of this store's items and prompts user to select 1
   * @return barcode of selected item
   */
  int selectFromInventory() const;

  ~StoreBase();

private:
  StoreInventoryItemMapType m_Inventory;
};


#endif //HOMEWORK6_STOREBASE_H
