//
// Created by Hans Johnson on 1/23/18.
//
#include "utilityFunctions.h"


#if ROBOTPRINT
#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
void printCharArray(char * value)
    {
       print(value);
    }
#else
#include <iostream>
void printCharArray(const char * const value)
{
  std::cout << value;
}
#endif // ROBOTPRINT
