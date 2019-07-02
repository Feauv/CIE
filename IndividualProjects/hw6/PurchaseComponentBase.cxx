//
// Created by Johnson, Hans J on 4/22/18.
//

#include "PurchaseComponentBase.h"

PurchaseComponentBase::PurchaseComponentBase(const string & name, const HealthStatus & hs)
  : m_name{name}
  , m_HealthStatus{hs}
{
}

const string& PurchaseComponentBase::getName() const
{
  return m_name;
}

const HealthStatus& PurchaseComponentBase::getHealthStatus() const
{
  return m_HealthStatus;
}

void PurchaseComponentBase::setHealthStatus(const HealthStatus& HealthStatus)
{
  m_HealthStatus = HealthStatus;
}


