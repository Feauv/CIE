//
// Created by Hans J. Johnson on 2/7/18.
//

#ifndef HW2_GAMECONSOLE_H
#define HW2_GAMECONSOLE_H

static const int DISPLAY_SIZE=9;  //NOTE: Need 8+1 spaces

static const char GAME_CONSOLE_BUTTON_LEFT   = 'L';
static const char GAME_CONSOLE_BUTTON_MIDDLE = 'M';
static const char GAME_CONSOLE_BUTTON_RIGHT  = 'R';

class GameConsole {
public:
  // TODO: This is not a correct or complete class, Treat the existing code as a HINT, not as a solution
  // TODO: There may be errors in this class!
  /**
   * Store a value for line 1 of the display.
   * @param newValue
   */
  void setDisplayLine1( const char * newValue);
  /**
   * Store a value for line 2 of the display.
   * @param newValue
   */
  void setDisplayLine2( const char * newValue);
  /**
   * Update the display from the current state of the
   * GameConsole attributes.
   */
  void UpdateDisplay() const;

  /**
   * Have the game console wait specified number of miliseconds before continuing
   * @param milliseconds
   */
  void delayMilliseconds(int milliseconds);

  /**
   * Provide the required battery check
   */
  void doBatteryCheck() const;

  /**
   * Returns either GAME_CONSOLE_BUTTON_LEFT, GAME_CONSOLE_BUTTON_MIDDLE, or GAME_CONSOLE_BUTTON_RIGHT
   * based on which button the user presses.
   * @return
   */
  char waitForButtonPress() const;

  char m_displayLine1[DISPLAY_SIZE];
  char m_displayLine2[DISPLAY_SIZE];
};


#endif //HW2_GAMECONSOLE_H
