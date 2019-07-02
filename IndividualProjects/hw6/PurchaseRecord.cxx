//
// Created by Johnson, Hans J on 4/3/18.
//

#include "PurchaseRecord.h"

PurchaseRecord::PurchaseRecord(const string store, const int barcode)
  :m_store(store), m_barcode(barcode)
{
}

PurchaseRecord::PurchaseRecord(const PurchaseRecord& pr)
  :m_store(pr.getStore()), m_barcode(pr.getBarcode())
{
}

const string& PurchaseRecord::getStore() const
{
  return m_store;
}

int PurchaseRecord::getBarcode() const
{
  return m_barcode;
}
