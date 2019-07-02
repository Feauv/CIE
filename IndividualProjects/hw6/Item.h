//
// Created by Johnson, Hans J on 4/2/18.
//

#ifndef HOMEWORK5_ITEM_H
#define HOMEWORK5_ITEM_H
#
#include "json/json.h"
#include <string>
#include <map>
#include "PurchaseComponentBase.h"

using namespace std;

class Item : public PurchaseComponentBase
{
public:
  Item(const string & name, const string & description, const HealthStatus& hs);
#if 0
  Item(const Item& i);
#endif
  const string& getDescription() const;

  void setDescription(const string& description);

  void Print() const;

private:
  string m_description;
};

typedef map<string, Item *> ItemMapType;

#endif //HOMEWORK5_ITEM_H
