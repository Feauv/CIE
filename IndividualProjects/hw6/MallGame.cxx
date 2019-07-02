//
// Created by Johnson, Hans J on 4/20/18.
//

#include "MallGame.h"

#include <random>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "HW6JsonHelper.h"
#include "HW6HelperFunctions.h"
#include "Dice.h"


using namespace std;

MallGame::MallGame(const std::string& item_info_fn, const std::string& store_info_fn, const std::string& character_info_fn)
{
  srand(time(NULL));
  int Range, i;
  std::string start;

  // Read the item json info file
  HW6JsonHelper itemHelper(item_info_fn);
  Json::Value item_info = itemHelper.getJsonDataStructure();
  m_ItemMap = GetAllItems(item_info);

  // Read the store json info file
  HW6JsonHelper storeHelper(store_info_fn);
  Json::Value store_info = storeHelper.getJsonDataStructure();
  m_StoreMap = GetAllStores(store_info);

  // Read the character json info file
  HW6JsonHelper characterHelper(character_info_fn);
  Json::Value character_info = characterHelper.getJsonDataStructure();

  m_CharacterMap = GetAllCharacters(character_info);

  cout << "***** Random Pre-Game Placements and Health Statuses *****\n\n";

  // This loop assigns each character to a random spot in the mall
  for(m_activePlayer = m_CharacterMap.begin(); m_activePlayer != m_CharacterMap.end(); m_activePlayer++){

      m_activePlayer->second->UpdateHealthStatus(m_StoreMap,m_ItemMap);
      cout << m_activePlayer->first << "'s Starting Health Status is:\n" << m_activePlayer->second->getHealthStatus().toString() << endl;

      // Random Number Assignment
      Range = m_StoreMap.size();
      int RandNum = rand()%Range;
      i = 0;

      // Store iterator initialized to set the active store
      StoreMapType::iterator aS;

      // Iterate through all the stores
      for(aS = m_StoreMap.begin(); aS != m_StoreMap.end(); aS++){
          // Until the random number is reaches
          if (i == RandNum){

              //
              m_activePlayer->second->setActStore(aS);
              cout << "and " << m_activePlayer->first << " starts at " << aS->first << "\n\n";
              break;

          }
          i++;
      }

  }

  cout << "Type 'start' to start the game: "; cin >> start; cout << "\n\n";
  while(start != "start"){cout << "Type 'start' to start the game: "; cin >> start; cout << "\n\n";}

}

/* Function Name: Play
 * Function Description: The Play function run everything associated with the game, so it involves a lot a printing and using all the
 * classes
 * Function Input: No Input
 * Function Output: A string that is the name of the winner
 */
std::string MallGame::Play()
{

    // Start of Game Message and Initializations
    cout << "\n***** Game Start *****\n\n";
    std::string winner = "Pending", enter;
    int round = 1, blueVal, redVal, bc;
    Dice B("blue"), R("red");
    vector<std::string>::iterator characterFinder;
    CharacterMapType::iterator tempIterator;

    // Do While Loop for the Game (Do: The Game, While: There is no Winner), This Do While and Iterator Loop takes the place of the suggested
    // "nextPlayer" function. (I asked Thedens too make sure this was ok)
    do{

        // Print Round Number
        cout << "\t***** Round " << round << " *****\n\n";

        // Map Iterator For Loop, for each player's turn
        for (m_activePlayer = m_CharacterMap.begin(); m_activePlayer != m_CharacterMap.end(); m_activePlayer++) {

            // Find if character is dead
            characterFinder = find(m_deadCharacters.begin(), m_deadCharacters.end(), m_activePlayer->first);

            // If statement to check that use of the find command
            if (characterFinder == m_deadCharacters.end()) {

                // Print Player's Turn and Roll Dice
                cout << "\t" << m_activePlayer->first << "'s Turn, type out 'roll' and hit enter when you are ready to roll: "; cin >> enter; cout << "\n";
                while (enter != "roll") {cout << "\t\ttype out 'roll' and hit enter when you are ready to roll: ";cin >> enter; cout << "\n";}
                blueVal = B.roll();redVal = R.roll();
                cout << "\t\t" << m_activePlayer->first << "'s Dice Roll\n\t\tBlue Dice: " << blueVal << "\tRed Dice: " << redVal << "\n\n";

                // Call movePlayerToNextStore Function
                movePlayerToNextStore(m_activePlayer->second->getActStore(), blueVal);

                // If and Else check if the red dice value is odd or even
                if(isOddRoll(redVal)){

                    // For loop discards the number of purchases based on the red dice value
                    for (int i = 0; i != redVal; i++) {
                        // Call the discardPurchase function
                        m_activePlayer->second->discardPurchase();
                    }

                    // Display how many purchases were deleted
                    cout << "\t\t" << redVal << " purchases were deleted from your purchase list.\n\n";

                }else{

                    // Call the selectFromInventory function to retrieve the barcode for the purchase they wanna make
                    bc = m_activePlayer->second->getActStore()->second->selectFromInventory();
                    // Create the purchase they just made and add the purchase
                    auto pr = new PurchaseRecord(m_activePlayer->second->getActStore()->first, bc);
                    m_activePlayer->second->addPurchase(pr);

                }

                // Check to see if the character is died
                if (m_activePlayer->second->DisplayHealthStatus(m_StoreMap, m_ItemMap)) {

                    // Add them to the dead characters vector
                    m_deadCharacters.push_back(m_activePlayer->first);

                    // Check if there is only one alive
                    if (m_deadCharacters.size() == 5) {
                        // Iterate through all characters
                        for (tempIterator = m_CharacterMap.begin(); tempIterator != m_CharacterMap.end(); tempIterator++) {

                            // Use of find command
                            characterFinder = find(m_deadCharacters.begin(), m_deadCharacters.end(), tempIterator->first);

                            // Check find command
                            if (characterFinder == m_deadCharacters.end()) {
                                // Assign winner
                                winner = tempIterator->first;
                                cout << "\n\n\n";
                                break;
                            }

                        }
                        break;
                    }

                }



            }
        }

        // New Round
        round++;

    }while(winner == "Pending");

    return winner;

}

// Class Destructor
MallGame::~MallGame()
{
    for (auto elem : m_CharacterMap) {
        delete elem.second; //delete memory allocated for the character map
    }
    for (auto elem : m_StoreMap) {
        delete elem.second; //delete memory allocated for the store map
    }
    for (auto elem : m_ItemMap) {
        delete elem.second; //delete memory allocated for the item map
    }
}

/* Function Name: movePlayerToNextStore
 * Function Description: Like in a board game this function moves the player to whatever store it must go based on the dice roll
 * Function Input: aS(iterator to set equal to the active store), bV(value of the blue dice roll)
 * Function Output: Void function, no output
 */
void MallGame::movePlayerToNextStore(StoreMapType::iterator aS, int bV){

    // Iterate through the all the stores to get the player's new store
    for(m_activeStore = aS; m_activeStore != m_StoreMap.end(); m_activeStore++){

        // Once it is at the new position
        if(bV == 0){

            // Set New Store to the Position Map and Print New Position
            m_activePlayer->second->setActStore(m_activeStore);
            cout << "\t\t" << m_activePlayer->first << " was at " << aS->first << " and is now at " << m_activeStore->first << endl << endl;
            break;

        }
        bV--;
    }

    // If the end of the stores is reaches and the iteration must start over
    if(m_activeStore == m_StoreMap.end()){
        for(m_activeStore = m_StoreMap.begin(); m_activeStore != m_StoreMap.end(); m_activeStore++){

            // Once it is at the new position
            if(bV == 0){

                // Set New Store to the Position Map and Print New Position
                m_activePlayer->second->setActStore(m_activeStore);
                cout << "\t\t" << m_activePlayer->first << " was at " << aS->first << " and is now at " << m_activeStore->first << endl << endl;
                break;

            }
            bV--;
        }
    }

}

bool MallGame::isOddRoll(const int roll_value) const
{
  return roll_value%2==1; //Use modulo to determine if roll is odd
}

//TODO: EXTRA CREDIT

