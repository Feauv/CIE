//
// Created by Johnson, Hans J on 4/2/18.
//

#ifndef HOMEWORK5_STORE_H
#define HOMEWORK5_STORE_H
#include "StoreBase.h"

class SimulatedStore
: public StoreBase
{
public:
  SimulatedStore(const string name, const HealthStatus& hs);

  //TODO: EXTRA CREDIT
#define USE_EXTRA_CREDIT_CODE 1
#ifdef USE_EXTRA_CREDIT_CODE
  /**
   * @brief Overrides prompting the user for input, and selects from inventory automatically (randomly).
   * @return barcode of selected item
   */
  int selectFromInventory() const;
#endif
};

typedef map<string, StoreBase *> StoreMapType;
//TODO: EXTRA CREDIT
//typedef map<string, SimulatedStore *> StoreMapType;

#endif //HOMEWORK5_STORE_H
