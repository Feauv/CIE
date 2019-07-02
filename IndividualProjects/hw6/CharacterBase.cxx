//
// Created by Johnson, Hans J on 4/2/18.
//

#include "CharacterBase.h"

CharacterBase::CharacterBase(const string & name, const string & home, const HealthStatus& hs)
  : PurchaseComponentBase(name, hs), m_home(home), m_purchase_list()
{
}

const string& CharacterBase::getHome() const
{
  return m_home;
}

void CharacterBase::addPurchase(PurchaseRecord* pr)
{
  m_purchase_list.push_back(pr);
}

CharacterBase::~CharacterBase()
{
  for (auto elem : m_purchase_list){
      delete elem;
  }
}

const PurchaseRecordQueueType& CharacterBase::getPurchase_list() const
{
  return m_purchase_list;
}

void CharacterBase::setPurchase_list(const PurchaseRecordQueueType& purchase_list)
{
  m_purchase_list = purchase_list;
}
