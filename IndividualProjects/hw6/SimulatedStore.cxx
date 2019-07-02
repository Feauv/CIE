//
// Created by Johnson, Hans J on 4/21/18.
//

#include "SimulatedStore.h"

SimulatedStore::SimulatedStore(const string name, const HealthStatus& hs)
  : StoreBase(name,hs)
{
}

//TODO: ExtraCredit
#ifdef USE_EXTRA_CREDIT_CODE
int SimulatedStore::selectFromInventory() const
{
  return -12345678;
}
#endif
