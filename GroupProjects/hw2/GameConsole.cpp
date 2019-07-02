//
// Created by Hans J. Johnson on 2/7/18.
//

#include "GameConsole.h"
#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#include <avr/pgmspace.h> /* allow use of program space */
#include <stdlib.h>

/*Function Name: setDisplayLine1
 *Programmer: Matthieu Stogsdill
 *Function Description: Stores string for line 1
 *Function Call: Function is called throught out the code */
void GameConsole::setDisplayLine1(const char * newValue) {

  for (int i = 0; i < DISPLAY_SIZE; i++){

    m_displayLine1[i] = *(newValue+i);

  }

}
/*Function Name: setDisplayLine2
 *Programmer: Matthieu Stogsdill
 *Function Description: Stores string for line 2
 *Function Call: Function is called through out the code */
void GameConsole::setDisplayLine2(const char * newValue) {

  for (int i = 0; i < DISPLAY_SIZE; i++){

    m_displayLine2[i] = *(newValue+i);

  }

}

/*Function Name: UpdateDisplay
 *Programmer: Matthieu Stogsdill
 *Function Description: Clears both lines of the robot screen and then prints the display lines
 *Function Call: Function is called through out the code */
void GameConsole::UpdateDisplay() const {

  clear();

  lcd_goto_xy(0,0);
  print(m_displayLine1);

  lcd_goto_xy(0,1);
  print(m_displayLine2);

}
/*Function Name: waitForButtonPress
 *Programmer: Nick Grove
 *Function Description: Waits for button press
 *Function Call: Function is called through out the code */
char GameConsole::waitForButtonPress() const {

  //Initialize button and return button
  unsigned char button = wait_for_button(ANY_BUTTON), retButton;

  //Button switch statement
  switch(button){

    case BUTTON_A:
      retButton = 'L';
      break;
    case BUTTON_B:
      retButton = 'M';
      break;
    case BUTTON_C:
      retButton = 'R';
      break;
    default:
      retButton = '\0';
      break;

  }

  return retButton;
}

//Millisecond delay function
void GameConsole::delayMilliseconds(int milliseconds)
{
  delay_ms(milliseconds);
}

/**
 *  THIS FUNCTION IS COMPLETE AS PROVIDED TO YOU.  YOU DO NOT NEED TO MODIFY THE doBatteryCheck function.
 */
void GameConsole::doBatteryCheck() const {
  int firstLineType = 0;   /* what should be displayed on line 1 */
  /*  0-19: Bat Chk */
  /* 20-39: xxxxmV  */
  /* 40-59: Okay/Replace */
  int bat = 0;             /* last read battery voltage */

  /* wait for user to press button B */
  while( !button_is_pressed(BUTTON_B) )
  {
    /* clear the lcd */
    clear();

    /* FIRST LINE */
    /* set lcd position to beginning of first line */
    lcd_goto_xy(0, 0);

    /* for first line, alternate between displaying:
     Bat Check
     xxxxmV
     Okay/Replace */

    if( firstLineType < 20 )
    {
      print("Bat Chk");
    }
    else if( firstLineType < 40 )
    {
      bat = read_battery_millivolts();
      print_long(bat);
      print("mV");
    }
    else if( firstLineType < 60 )
    {
      if( bat >= 4500 )
      {
        print("Okay");         /* okay */
      }
      else
      {
        print("Replace");         /* replace */
      }
    }
    firstLineType++;
    firstLineType = firstLineType % 60;

    /* SECOND LINE */
    /* set lcd position to beginning of second line */
    lcd_goto_xy(0, 1);
    print("Press B");

    /* small delay */
    delay_ms(50);
  }

  /* once pressed, wait a little bit */
  delay_ms(500);
  /* Intialize the random number generator */
  //srand(time(NULL)); //NOTE the time function does not work as a seed on the 3pi robots
  ::srand( read_battery_millivolts() ); //NOTE: the get_ms function does work as a seed on the 3pi robots
}
