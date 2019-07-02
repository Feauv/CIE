//
// Created by Hans J. Johnson on 3/9/18.
//

#include "CustomerRecord.h"
#include <iostream>

ostream & operator<< ( ostream & sout, const CustomerRecord & cust)
{
  sout << "\"" << "CUST" << "\","
       << "\"" << cust.getCustomerSSN() << "\","
       << "\"" << cust.getName() << "\","
       << cust.getAddress()
      << endl;
  for( auto accnt : cust.getAccountMapping())
  {
    for (auto tnx : accnt.second.getTransactionList())
    {
      sout << "\"" << cust.getCustomerSSN() << "\","
           << "\"" << accnt.second.getTypeAsString() << "\","
           << tnx;
    }
  }
  return sout;
}
