//
// Created by Johnson, Hans J on 4/2/18.
//

#include "Item.h"
#include <iostream>

using namespace std;

Item::Item(const string & name, const string & description, const HealthStatus& hs)
  : PurchaseComponentBase(name, hs), m_description(description)
{
}

#if 0
Item::Item(const Item& i)
  :m_name(i.getName()), m_description(i.getDescription()), m_HealthStatus(i.getHealthStatus())
{
}
#endif

void Item::Print() const
{
  cout << "{\n";
  cout << "  \"name\" : \"" << this->getName() << "\",\n";
  cout << "  \"description\" : \"" << this->getDescription() << "\",\n";
  this->getHealthStatus().Print();
  cout << "}\n";
}

const string& Item::getDescription() const
{
  return m_description;
}

void Item::setDescription(const string& description)
{
  m_description = description;
}

