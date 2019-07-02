//
// Created by Johnson, Hans J on 4/22/18.
//

#ifndef HOMEWORK5_PURCHASECOMPONENTBASE_H
#define HOMEWORK5_PURCHASECOMPONENTBASE_H

#include "HealthStatus.h"

class PurchaseComponentBase {
public:
  PurchaseComponentBase(const string & name, const HealthStatus & hs);
  const string& getName() const;
  const HealthStatus& getHealthStatus() const;
  void setHealthStatus(const HealthStatus& HealthStatus);

private:
  const string m_name;
  HealthStatus m_HealthStatus;
};

#endif //HOMEWORK5_PURCHASECOMPONENTBASE_H
