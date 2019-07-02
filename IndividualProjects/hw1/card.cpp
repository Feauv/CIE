/*Implementation of the Card functions*/
/*See card.h for documentation */

#include "card.h"
#include "utilityFunctions.h"

void printCard (SingleCard c) {

    char s[4] = {c.face,c.suit,' ','\0'};

    printCharArray(s);

}

