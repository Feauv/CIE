//
// Created by Johnson, Hans J on 4/3/18.
//

#ifndef HOMEWORK5_PURCHASERECORD_H
#define HOMEWORK5_PURCHASERECORD_H

#include <string>
#include <sstream>
#include <map>
#include <list>

using namespace std;

class PurchaseRecord {
public:
  PurchaseRecord(const string store, const int barcode);

  PurchaseRecord(const PurchaseRecord& pr);

  const string& getStore() const;

  int getBarcode() const;

  string toString() const
  {
    stringstream ss("");
    ss << m_store << " " << m_barcode;
    return ss.str();
  }

private:
  const string m_store;
  const int m_barcode;
};

typedef list<PurchaseRecord *> PurchaseRecordQueueType;
#endif //HOMEWORK5_PURCHASERECORD_H
