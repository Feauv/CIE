
#include <iostream>
#include "MallGame.h"

using namespace std;

int main(int argc, char* argv[])
{
  if (argc!=4) {
    cerr << "ERROR: Wrong command line argument format given" << endl;
    cerr << argv[0] << " <item_info.json> <store_info.json>  <character_info.json>" << endl;
  }
  const std::string item_info_fn = argv[1];
  const std::string store_info_fn = argv[2];
  const std::string character_info_fn = argv[3];

  // Run one game
  MallGame myGame(item_info_fn, store_info_fn, character_info_fn);
  //extra credit:  myGame.setRunWithoutManualInput(true);
  string winner = myGame.Play();

  cout << "\tThe winner is " << winner << "\n";

  return EXIT_SUCCESS;
}
