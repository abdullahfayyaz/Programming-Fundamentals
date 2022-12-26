#include <iostream>
using namespace std;
main(){
      float vegatablePricePerKg;
      float fruitPricePerKg;
      int quantityOfVegetables;
      int quantityOfFruits;
      float vegatablePrice;
      float fruitPrice;
      float total;
      cout << "Enter price of vegetables per kilogram: ";
      cin >> vegatablePricePerKg;
      cout << "Enter price of fruits per kilogram: ";
      cin >> fruitPricePerKg;
      cout << "Enter total kilogram of vegetables: ";
      cin >> quantityOfVegetables;
      cout << "Enter total kilogram of fruits: ";
      cin >> quantityOfFruits;
      vegatablePrice = vegatablePricePerKg * quantityOfVegetables;
      fruitPrice = fruitPricePerKg * quantityOfFruits;
      cout << "Vegetable cost: " << vegatablePrice << endl;
      cout << "Fruit cost: " << fruitPrice << endl;
      total = vegatablePrice + fruitPrice;
      cout << "Total: " << total << " Rupees ";
}





