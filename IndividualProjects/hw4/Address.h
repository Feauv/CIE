//
// Created by Hans J. Johnson on 3/9/18.
//

#ifndef HW4_ADDRESS_H
#define HW4_ADDRESS_H

#include <string>
#include <iostream>
#include <map>
#include "common.h"
using namespace std;

/** Class Name: Address
 * Class Description: A class that takes all the aspects of home or bank address. It takes in Street, City, State, and Zip
 * Code.
 * Class Use: Used in the Bank and CustomerRecord classes to store bank addresses and home addresses, and also used in
 * teller_simulation.cpp */
class Address {

public:
    // Address Constructor
    Address(StreetNameType s, CityNameType c, StateNameType st, ZipCodeType z):street{s},city{c}
    {
        // Must Call a Setter for State and Zip because I have to make sure they are valid
        setState(st);
        setZipCode(z);
    }

    /** Function Name: setState
     * Function Description: Sets the state for the address while also checking if the state is valid by the ammount of
     * letters it has and by using the state map I made for valid states.
     * Function Call: Address Constructor, and teller_simulation.cpp when there is an invalid state */
    void setState(StateNameType st){
        // Call of the Valid State Map Function
        initStateMap();

        // Length and Valid State If Statement
        if (st.length() > 2 or st.length() < 2){
            // Invalid State
            stateError = false;
        }else if (SM[st[0]][st[1]]){
            // Set the state
            state = st;
            // Valid State
            stateError = true;
        }else{
            // Invalid State
            stateError = false;
        }
    }

    /** Function Name: setZipCode
     * Function Description: Sets the zip code for the address while also checking if the zip code is valid by the ammount
     * of numbers it has.
     * Function Call: Address Constructor, and teller_simulation.cpp when there is an invalid zip code */
    void setZipCode(ZipCodeType z){

        // Length If Statement
        if (z.length() > 5 or z.length() < 5){
            // Invalid Zip Code
            zipError = false;
        }else{
            // Set the zip
            zip = z;
            // Valid Zip Code
            zipError = true;
        }
    }

    // Address Class Getters
    StreetNameType getStreet() const {return street;}
    CityNameType getCity() const {return city;}
    StateNameType getState() const {return state;}
    ZipCodeType getZipCode() const {return zip;}

    // Address Class Error Functions
    bool StateError() {return stateError;}
    bool ZipError() {return zipError;}

private:
    // Class Strings
    StreetNameType street;
    CityNameType city;
    StateNameType state;
    ZipCodeType zip;

    // Class Maps
    StateMapping SM;
    StateBoolMapping BM;

    // Class Booleans
    bool stateError = true;
    bool zipError = true;

    // Prototype of the Valid State Map Function
    void initStateMap();

};

/**
 * A stream override for printing addresses
 * @param sout The output stream reference
 * @param addr The address object reference
 * @return
 */
extern ostream & operator<< ( ostream & sout, const Address & addr);


#endif //HW4_ADDRESS_H
