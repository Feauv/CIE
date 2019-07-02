//
// Created by Hans J. Johnson on 3/9/18.
//

#include "Bank.h"


ostream & operator<< ( ostream & sout, const Bank & b)
{
  //Print Bank account information as a single serializable record
  sout << "\"" << b.getRoutingBankID() << "\","
       << "\"" << b.getBankName() << "\","
       << "\"" << b.getRoutingBankID() << "\","
       << b.getBankAddress() << ""
       << endl;
  for( auto cust_pair: b.getCustomerMap())
  {
    sout << cust_pair.second;
  }
  return sout;
}
