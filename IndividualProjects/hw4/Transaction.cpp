//
// Created by Hans J. Johnson on 3/9/18.
//

#include "Transaction.h"


ostream & operator<< ( ostream & sout, const Transaction & tx)
{
  sout << "\"" << tx.getTransactionTime().toString() << "\","
       << "\"" << tx.getChangeValue() << "\","
       << "\"" << tx.getMemo() << "\"" << endl;
  return sout;
}
