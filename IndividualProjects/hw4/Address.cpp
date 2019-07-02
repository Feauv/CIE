//
// Created by Hans J. Johnson on 3/9/18.
//

#include "Address.h"

ostream & operator<< ( ostream & sout, const Address & addr)
{
  sout << "\"" << addr.getStreet() << "\","
       << "\"" << addr.getCity() << "\","
       << "\"" << addr.getState() << "\","
       << "\"" << addr.getZipCode() << "\"";

 return sout;
}

/** Function Name: initStateMap
 * Function Description: Initializes the map for valid states
 * Function Call: setState function to check for valid states */
void Address::initStateMap(){

    // Valid State Array
    char stateArray[50][2] = {{'A','L'},{'A','K'},{'A','Z'},{'A','R'},{'C','A'},{'C','O'},{'C','T'},{'D','E'},{'F','L'},
                              {'G','A'},{'H','I'},{'I','D'},{'I','L'},{'I','N'},{'I','A'},{'K','S'},{'K','Y'},{'L','A'},
                              {'M','E'},{'M','D'},{'M','A'},{'M','I'},{'M','N'},{'M','S'},{'M','O'},{'M','T'},{'N','E'},
                              {'N','V'},{'N','H'},{'N','J'},{'N','M'},{'N','Y'},{'N','C'},{'N','D'},{'O','H'},{'O','K'},
                              {'O','R'},{'P','A'},{'R','I'},{'S','C'},{'S','D'},{'T','N'},{'T','X'},{'U','T'},{'V','T'},
                              {'V','A'},{'W','A'},{'W','V'},{'W','I'},{'W','Y'}
    };

    // Map Initializing For Loop
    for(int i = 0; i < 50; i++){
        // Map with second letter and true boolean
        BM.emplace(stateArray[i][2], true);
        // Map with first letter and boolean map
        SM.emplace(stateArray[i][1], BM);
    }
}