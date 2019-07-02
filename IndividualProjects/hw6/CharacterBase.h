//
// Created by Johnson, Hans J on 4/2/18.
//

#ifndef HOMEWORK6_CHARACTERBASE_H
#define HOMEWORK6_CHARACTERBASE_H

#include "HealthStatus.h"
#include "PurchaseRecord.h"

#include <string>
#include <map>
#include "SimulatedStore.h"
#include "Item.h"
#include "PurchaseComponentBase.h"

using namespace std;

class CharacterBase : public PurchaseComponentBase {

public:
  CharacterBase(const string & name, const string & home, const HealthStatus& hs);

  ~CharacterBase();

  const string& getHome() const;

  /**
   * @brief Add an item to the list of items that this character posesses
   * @param pr A pointer to the Purchased item
   */
  void addPurchase(PurchaseRecord* pr);

  void discardPurchase()
  {
    if (m_purchase_list.size()>0) {
      delete m_purchase_list.front(); // Delete the pointer
      m_purchase_list.pop_front();  // Pop from list
    }
  }

protected:
public:

  const PurchaseRecordQueueType& getPurchase_list() const;

  void setPurchase_list(const PurchaseRecordQueueType& purchase_list);

private:
  string m_home;
  PurchaseRecordQueueType m_purchase_list;
};


#endif //HOMEWORK6_CHARACTERBASE_H
