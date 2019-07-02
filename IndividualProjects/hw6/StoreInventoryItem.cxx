//
// Created by Johnson, Hans J on 4/3/18.
//

#include "StoreInventoryItem.h"

StoreInventoryItem::StoreInventoryItem(const string name, const int barcode)
  :m_name(name), m_barcode(barcode)
{
}

StoreInventoryItem::StoreInventoryItem(const StoreInventoryItem& si)
  :m_name(si.getName()), m_barcode(si.getBarcode())
{
}

const string& StoreInventoryItem::getName() const
{
  return m_name;
}

unsigned int StoreInventoryItem::getBarcode() const
{
  return m_barcode;
}

