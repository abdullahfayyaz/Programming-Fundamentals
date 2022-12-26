#include <iostream>
using namespace std;
main(){
      float bagSize;
      int bagCost;
      float areaCovered;
      float fertilizerCost;
      float areaCost;
      cout << "Enter Bag Size in Pounds: ";
      cin >> bagSize;
      cout << "Enter Cost of the bag: ";
      cin >> bagCost;
      cout << "Enter area covered by each bag in square feet: ";
      cin >> areaCovered;
      fertilizerCost = bagCost / bagSize;
      areaCost = bagCost / areaCovered;
      cout << "___________________________________________________________" << endl;
      cout << "Cost of the fertilizer per pound: " << fertilizerCost << endl;
      cout << "Cost of fertilizing the area per square feet: " << areaCost;
}