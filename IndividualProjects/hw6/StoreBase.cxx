//
// Created by Johnson, Hans J on 4/2/18.
//

#include "StoreBase.h"

using namespace std;

StoreBase::StoreBase(const string name, const HealthStatus& hs)
  : PurchaseComponentBase(name, hs), m_Inventory()
{
}


const HealthStatus& StoreBase::getQualityMultiplier() const
{
  return this->getHealthStatus(); //Note HealthStatus is a quality multiplier
}

const StoreInventoryItemMapType& StoreBase::getInventory() const
{
  return m_Inventory;
}

StoreBase::~StoreBase()
{
  for (auto elem : m_Inventory) {
    delete elem.second; //delete memory allocated for the inventory.
  }
}

int StoreBase::selectFromInventory() const
{
  cout << "===============================" << endl;
  cout << "In store " << this->getName() << endl;
  cout << "Barcode  Description" << endl;
  int selection = -1;
  StoreInventoryItemMapType::const_iterator itemSelected = m_Inventory.end();
  do {

    for (const auto& item: m_Inventory) {
      cout << item.first << "     " << item.second->getName() << endl;
    }
    cout << "Type the barcode number of the item you wish to purchase" << endl;

    cin >> selection;
    itemSelected = m_Inventory.find(selection);
  }
  while (itemSelected==m_Inventory.end());
  return selection;
}

void StoreBase::addInventoryItem(const string& storeItemName, const double& storeItemBarcode)
{
  StoreInventoryItem* si = new StoreInventoryItem(storeItemName, storeItemBarcode);
  m_Inventory[storeItemBarcode] = si;
}
