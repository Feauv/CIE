//
// Created by Hans J. Johnson on 3/9/18.
//

#ifndef HW4_TRANSACTION_H
#define HW4_TRANSACTION_H

#include <chrono>
#include <string>
#include <iostream>
#include "common.h"
#include "TransactionTime.h"
using namespace std;

/** Class Name: Transaction
 * Class Description: A class does all balance, time,and memo keeping for an account
 * Class Use: Used in AccountLedger */
class Transaction {

public:
  // Default Transaction Constructor
  Transaction(){};

  // Transaction Constructor
  Transaction(MonetaryType ChangeValue, MemoType Memo):change{ChangeValue},memo{Memo},balance{balance}
  {
    // Set Balance for the Transaction
    setBalance(ChangeValue,Memo);
  }

  // Transaction Class Getters
  MonetaryType getChangeValue() const {return change;}
  TimeType getTransactionTime() const {return time;}
  MemoType getMemo() const {return memo;}

  // Balance Setter
  void setBalance(MonetaryType c = 0, MemoType m = "New Account"){
      balance += c;
  }

private:
  // Private Floats
  MonetaryType change, balance;

  // Private String
  MemoType memo;

  // Private Time Variable
  TimeType time;


};

/**
 * A stream override for printing Transaction
 * @param sout The output stream reference
 * @param tx The Transaction object reference
 * @return
 */
extern ostream & operator<< ( ostream & sout, const Transaction & tx);

#endif //HW4_TRANSACTION_H
