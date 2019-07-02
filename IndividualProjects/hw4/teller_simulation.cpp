#include <iostream>
#include <fstream>

using namespace std;

#include "Bank.h"
#include <map>
#include <iterator>


/**
 * This file simulates creating a bank, customers, accounts, and transactions
 * that need to be logged in a file for further processing.
 *
 * There are no tasks that need to be completed in this file.  You may modify this file
 * in order to test your classes to make sure that they work as intended.
 */

int main(int , char * [])
{
  Address myBankAddress("101 S. Gilbert", "Iowa City", "IA", "52242");
  string state, zip;

  while (myBankAddress.StateError() == false or myBankAddress.ZipError() == false){
      if (myBankAddress.StateError() == false){
          cout << "---!Invalid State Entered!---" << endl;
          cout << "Enter a valid State: ";
          cin >> state;
          myBankAddress.setState(state);
      }else if (myBankAddress.ZipError() == false){
          cout << "---!Invalid Zip Code Entered!---" << endl;
          cout << "Enter a valid Zip Code: ";
          cin >> zip;
          myBankAddress.setZipCode(zip);
      }

      cout << endl << myBankAddress << endl << endl;
  }

  Bank myBank("R001","FirstCIEBank", myBankAddress);

  Address customerAddress("22 S Place", "Coralville", "IA", "52241");

  CustomerSSNType mySSN="SSN_4444";
  myBank.addCustomer(customerAddress, "Hans Johnson", mySSN);

  myBank.addCustomerAccount(mySSN,ValidAccountTypes::CHECKING);
  myBank.addCustomerAccount(mySSN,ValidAccountTypes::SAVINGS);

  if (myBank.HasCustomer(mySSN))
  {

    auto & cust = myBank.getCustomerBySSN(mySSN);
    if (cust.HasAccountType(ValidAccountTypes::SAVINGS))
    {
        //cout << "Flag 2" << endl;

      auto & account = cust.GetAccountByType(ValidAccountTypes::CHECKING);
      account.makeDeposit(1000000, "Won the lottery");
      account.makeWithdrawal(1.01, "Pay the piper");
    }
    else
    {
      std::cerr << "Error: " << "Customer does not have requested account type" << endl;
    }
  }
  else
  {
    std::cerr << "User with SSN " << mySSN << "does not exist" << std::endl;
  }

  cout << myBank << endl;

  ofstream outstream("../test.csv"); //NOTE THIS IS HARDCODED FOR TESTING PURPOSES ONLY
  outstream << myBank;

  return 0;
}
