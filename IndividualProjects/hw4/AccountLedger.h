//
// Created by Hans J. Johnson on 3/9/18.
//

#ifndef HW4_ACCOUNT_H
#define HW4_ACCOUNT_H

#include <iterator>
#include <list>
#include "Transaction.h"
#include <iostream>
#include "ValidAccountTypes.h"
#include "common.h"

using namespace std;

/** Class Name: AccountLedger
 * Class Description: A class that stores all transactions done through a certain account
 * Class Use: Used primarily in CustomerRecord */
class AccountLedger {
    // Transaction Typedefs
    typedef std::list<Transaction> TransactionList;
    typedef std::list<Transaction>::iterator TranListIterator;

public:
    // Default AccoutLedger Constructor
    AccountLedger():account{account}
    {
    }

    // AccoutLedger Constructor
    AccountLedger(AccountType a):account{a}
    {
        Transaction NewAcc;
        // Compute Balance to make a new account
        ComputeBalance(0,"New Account",NewAcc);
    }

    /** Function Name: makeDeposit
     * Function Description: This function goes inside the Transaction class and makes a deposit and adds the transaction to
     * the TransactionList
     * Function Call: teller_simulation.cpp */
    void makeDeposit(MonetaryType d, MemoType m){
        Transaction Tran(d,m);
        IT = TL.begin();
        TL.insert(IT,Tran);
        IT++;
    }

    /** Function Name: makeWithdrawal
     * Function Description: This function goes inside the Transaction class and makes a withdrawal and adds the transaction to
     * the TransactionList
     * Function Call: teller_simulation.cpp */
    void makeWithdrawal(MonetaryType w, MemoType m){
        Transaction Tran(w,m);
        IT = TL.begin();
        TL.insert(IT,Tran);
        IT++;
    }

    /** Function Name: ComputeBalance
     * Function Description: This function constructs the Transaction for a new accout
     * Function Call: Called when the AccountLedger is constructed */
    Transaction & ComputeBalance(MonetaryType wORd, MemoType m, Transaction T){
        Transaction Tran(wORd,m);
        return Tran;
    }

    // AccountLedger Class Getters
    list<Transaction> getTransactionList(){return TL;}
    string getTypeAsString(){return memo;}

private:
    // Private Account
    AccountType account;

    // Private Transaction Variables
    TransactionList TL;
    TranListIterator IT;

    // Private String
    MemoType memo;

    //TimeType time;

};

#endif //HW4_ACCOUNT_H
