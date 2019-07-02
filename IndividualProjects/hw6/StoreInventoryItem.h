//
// Created by Johnson, Hans J on 4/3/18.
//

#ifndef HOMEWORK5_STOREINVENTORYITEM_H
#define HOMEWORK5_STOREINVENTORYITEM_H

#include <string>
#include "json/json.h"
#include <map>

using namespace std;

/**
 * @brief A linked list structure for keeping track of items for sale in a store.
 */
class StoreInventoryItem {

public:
  StoreInventoryItem(const string name, const int barcode);
  StoreInventoryItem(const StoreInventoryItem & si);

  const string& getName() const;

  unsigned int getBarcode() const;

private:
  const string m_name;
  unsigned int m_barcode;

};

typedef map<int, StoreInventoryItem * > StoreInventoryItemMapType;

#endif //HOMEWORK5_STOREINVENTORYITEM_H
