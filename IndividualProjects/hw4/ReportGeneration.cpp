#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "common.h"
using namespace std;

#include "Bank.h"

/**
 * This program reads in a bank log file from disk (i.e. argv[1])
 * re-creating the in-memory representation of bank, customer, and transaction logs.
 *
 * From the in-memory representation, a simple report is produced that only prints 3 columns:
 * CustomerName,AccountType,CurrentBalance
 */

/**
 * A utility function to remove extra quotes around a string object.
 * @param withQuotes
 * @return string with extra quotes removed.
 */
static string RemoveQuotes(string withQuotes)
{
  const string removeQuotes = withQuotes.substr(1, withQuotes.length()-2); // remove quotes
  return removeQuotes;
}

/**
 * A function to convert a csv quoted string row into a container of strings
 * representing the columns of that row.
 * @param line
 * @return a container of strings
 */
static LineElements ExtractLineElements(const std::string &line)
{
  LineElements csvColumn;
  //https://stackoverflow.com/questions/35639083/c-csv-line-with-commas-and-strings-within-double-quotes
    const char *mystart=line.c_str();    // prepare to parse the line - start is position of begin of field
    bool instring{false};
    for (const char* p=mystart; *p; p++) {  // iterate through the string
      if (*p=='"')                        // toggle flag if we're btw double quote
        instring = !instring;
      else if (*p==',' && !instring) {    // if comma OUTSIDE double quote
        csvColumn.emplace_back(string(mystart,p-mystart));  // keep the field
        mystart=p+1;                    // and start parsing next one
      }
    }
  csvColumn.emplace_back(mystart);
  std::transform(csvColumn.cbegin(), csvColumn.cend(),csvColumn.begin(), RemoveQuotes);
  return csvColumn;
}


int main(int argc, char * argv[])
{

  if(argc < 1)
  {
    cout << "Usage: BankTransaction File" << endl;
  }

  string transactionFN{argv[1]};
  cout << "Reading from : " << transactionFN << endl;

  ifstream transactionStream{transactionFN};
  string currentLine;

  // Must process creating the bank first
  if(! getline(transactionStream,currentLine) || currentLine[1] != 'R' )
  {
    cout << "ERROR: Bank account log must begin with description of the bank as the first line." << endl;
  }

  LineElements lineColumns = ExtractLineElements(currentLine);
  RoutingNumberType routingNumber{ lineColumns[0]};
  BankNameType bankName{ lineColumns[1]};
  StreetNameType bankStreetName{ lineColumns[2] };
  CityNameType bankCityName{ lineColumns[3] };
  StateNameType bankStateName{ lineColumns[4] };
  ZipCodeType bankZipCode{ lineColumns[5] };

  Address myBankAddress(bankStreetName,bankCityName,bankStateName,bankZipCode);
  Bank myBank(routingNumber,bankName, myBankAddress);

  //TODO: Complete parsing of the tranactionFN file  (Perhaps a 150 lines of code)

  //TODO: Write the balance for each account (probably less than 20 lines of code)
  //Tony Stark,CHECKING,1880
  //Robert Downing Jr.,CHECKING,1937

  return 0;
}
