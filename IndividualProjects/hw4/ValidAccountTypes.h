//
// Created by Hans J. Johnson on 3/17/18.
//

#ifndef HW4_VALIDACCOUNTTYPE_H
#define HW4_VALIDACCOUNTTYPE_H

#include "common.h"

/**
 * A class with static values used to enforce a limited number of
 * account value types and strings.
 */
class ValidAccountTypes
{
public:
  static const AccountType INVALID=-1;
  static const AccountType CHECKING=0;
  static const AccountType SAVINGS=1;
  static const AccountType LOAN=2;
  static AccountType fromString(std::string accountTypeString )
    {
        if( accountTypeString == "SAVINGS" )
        {
          return ValidAccountTypes::SAVINGS;
        }
        else if( accountTypeString == "CHECKING")
        {
          return ValidAccountTypes::CHECKING;
        }
        else if( accountTypeString == "LOAN")
        {
          return ValidAccountTypes::LOAN;
        }
      return ValidAccountTypes::INVALID;
    }

  static std::string toString(AccountType acctType )
  {
    switch( acctType )
    {
      case ValidAccountTypes::CHECKING:
        return "CHECKING";
      case ValidAccountTypes::SAVINGS:
        return "SAVINGS";
      case ValidAccountTypes::LOAN:
        return "LOAN";
      default:
        break;
    }
    return "INVALID";
    };

private:
  ValidAccountTypes() = delete; //Prevent instantiation of this class, it is purely static
};

#endif //HW4_VALIDACCOUNTTYPE_H
