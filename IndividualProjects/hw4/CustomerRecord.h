//
// Created by Hans J. Johnson on 3/9/18.
//

#ifndef HW4_CUSTOMER_H
#define HW4_CUSTOMER_H

#include "AccountLedger.h"
#include "Address.h"
#include "common.h"
#include <string>
#include <map>
#include <iterator>
#include <array>
#include <list>
#include <iostream>

/** Class Name: CustomerRecord
 * Class Description: A class that takes all the aspects of a customer. It takes in their SSN, Name, and Address, while also
 * keeping track of their accounts
 * Class Use: Used in the Bank Class and teller_simulation.cpp */
class CustomerRecord {
    // Account Map Typedef
    typedef std::map<AccountType,AccountLedger>        AccountMapping;

public:
    // Default Constructer
    CustomerRecord():ssn{ssn},name{name},address{address}
    {
    }

    // CustomerRecord Constructor
    CustomerRecord(CustomerSSNType s, CustomerNameType n, Address a):ssn{s}, name{n},address{a}
    {
    }

    /** Function Name: AddAccount
     * Function Description: This function adds an Account to the Account Boolean Map, and constructs an AccountLedger
     * to add the Account Map that has an Account and AccountLedger.
     * Function Call: Bank.h */
    void AddAccount(AccountType a){
        ABM.emplace(a,true);
        AccountLedger AL(a);
        AM.emplace(a,AL);
    }

    /** Function Name: HasAccountType
     * Function Description: This function checks if a CustomerRecord has an Account using the Account Boolean Map
     * Function Call: teller_simulation.cpp */
    bool HasAccountType(AccountType a){
        if(ABM[a]){ return true;}
        else{return false;}
    }

    /** Function Name: GetAccountByType
     * Function Description: This function checks returns the AccountLedger for an Account
     * Function Call: teller_simulation.cpp */
    AccountLedger & GetAccountByType(AccountType a){
        return AM[a];
    }

    // CustomerRecord Class Getters
    CustomerSSNType getCustomerSSN() const {return ssn;}
    CustomerNameType getName() const {return name;}
    Address getAddress() const {return address;}
    AccountMapping getAccountMapping() const {return AM;}

private:
    // Private Address
    Address address;

    // Private Strings
    CustomerNameType name;
    CustomerSSNType ssn;

    // Private Maps
    AccountMapping AM;
    AccBoolMapping ABM;

};

/**
 * A stream override for printing CustomerRecord
 * @param sout The output stream reference
 * @param cust The CustomerRecord object reference
 * @return
 */
extern ostream & operator<< ( ostream & sout, const CustomerRecord & cust);

#endif //HW4_CUSTOMER_H
