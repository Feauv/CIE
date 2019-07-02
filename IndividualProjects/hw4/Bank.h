//
// Created by Hans J. Johnson on 3/9/18.
//

#ifndef HW4_BANK_H
#define HW4_BANK_H

#include <vector>
#include <map>
#include <string>
#include <ostream>
#include "CustomerRecord.h"
#include <iterator>

using namespace std;

/** Class Name: Bank
 * Class Description: A class that takes the aspects of a bank such as the Routing Number, Bank Name, and Address
 * Class Use: Used primarily by the teller_simulation.cpp */
class Bank {
    // CustomerMapping Typedef
    typedef map<CustomerSSNType, CustomerRecord> CustomerMapping;

public:
    // Bank Constructer
    Bank(RoutingNumberType r, BankNameType bn, Address a):routing{r}, bankname{bn}, address{a}
    {
        // Adds to Bank Map
        MapofAllBanks.emplace(r,bn);
    }

    /** Function Name: addCustomer
     * Function Description: This adds a customer using the CustomerRecord constructor while also adding the SSN and
     * CustomerRecord to the Customer Map, and adding the SSN and a true boolean to the SSN Boolean Map.
     * Function Call: teller_simulation.cpp */
    void addCustomer(Address a, CustomerNameType n, CustomerSSNType s){
        // Constructs CustomerRecord
        CustomerRecord CustConstructor(s,n,a);
        // Adds CustomerRecord to the CustomerRecord Map along with its SSN
        CM.emplace(s, CustConstructor);
        // Adds SSN to the SSN Boolean Map
        SSNC.emplace(s,true);
    }

    /** Function Name: addCustomerAccount
     * Function Description: This function gets the CustomerRecord with an SSN and calls the AddAccount function to add an
     * account to that CustomerRecord.
     * Function Call: teller_simulation.cpp */
    void addCustomerAccount(CustomerSSNType s, AccountType a) {
        // Retrieves CustomerRecord by SSN
        CustomerRecord &CR = getCustomerBySSN(s);
        // Calls AddAccount to add the account onto to the CustomerRecord
        CR.AddAccount(a);
    }

    /** Function Name: HasCustomer
     * Function Description: This function uses our SSN Boolean Map to check if we have a person as a customer
     * Function Call: teller_simulation.cpp */
    bool HasCustomer(CustomerSSNType s){
        if (SSNC[s]){return true;}
        else{return false;}
    }

    // Bank Class Getters
    RoutingNumberType getRoutingBankID() const {return routing;}
    BankNameType getBankName() const {return bankname;}
    Address getBankAddress() const {return address;}
    CustomerMapping getCustomerMap() const {return CM;}
    CustomerRecord & getCustomerBySSN(CustomerSSNType s){return CM[s];}

private:
    // Private Maps
    CustomerMapping CM;
    SSNBoolMapping SSNC;
    BankMapping MapofAllBanks;

    // Private Strings
    BankNameType bankname;
    RoutingNumberType routing;

    // Private Address
    Address address;

};

/**
 * A stream override for printing Bank
 * @param sout The output stream reference
 * @param b The Bank object reference
 * @return
 */
extern ostream & operator<< ( ostream & , const Bank & b);

#endif //HW4_BANK_H
