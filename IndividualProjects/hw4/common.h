//
// Created by Hans J. Johnson on 3/10/18.
//
#ifndef HW4_COMMON_H
#define HW4_COMMON_H
#include <string>
#include <vector>
#include "TransactionTime.h"
#include <map>
#include <list>

/** String Typedefs */

// Bank Strings
typedef std::string      RoutingNumberType;
typedef std::string      BankNameType;
// CustomerRecord Strings
typedef std::string      CustomerNameType;
typedef std::string      CustomerSSNType;
// Address Strings
typedef std::string      StreetNameType;
typedef std::string      CityNameType;
typedef std::string      StateNameType;
typedef std::string      ZipCodeType;
// AccountLedger/Transaction Strings
typedef std::string      MemoType;

/** Time Typedefs */

typedef TransactionTime  TimeType;

/** Numerical Typedefs */

typedef float            MonetaryType;
typedef int              AccountType;

/** Vector Typedefs */

typedef std::vector<std::string> LineElements;

/** Map Typedefs */

// State Maps
typedef std::map<char,bool>         StateBoolMapping;
typedef std::map<char,StateBoolMapping>         StateMapping;
// CustomerRecord Maps
typedef std::map<CustomerSSNType,bool>         SSNBoolMapping;
typedef std::map<AccountType,bool>         AccBoolMapping;
// Bank Maps
typedef std::map<RoutingNumberType,BankNameType>        BankMapping;


#endif //HW4_COMMON_H
