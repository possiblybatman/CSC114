//I wrote this 
#include <iostream>

int main() {

	double flour, salt, yeast, water;
	int numLoaves;
	
	std::cout << "How many grams of flour, salt, yeast, and water does this bread recipe require for each loaf?";
	std::cout << "\nProvide each amount separated by a space and press Enter: ";
	std::cin >> flour >> salt >> yeast >> water;
	std::cout << "\nHow many loaves of bread do you want to bake? ";
	std::cin >> numLoaves;
	
	double totalFlour = flour * numLoaves;
	double totalSalt = salt * numLoaves;
	double totalYeast = yeast * numLoaves;
	double totalWater = water * numLoaves;
	
	std::cout << "\nIn order to make " << numLoaves << " loaves of bread, you'll need\n";
	std::cout << totalFlour << " grams of flour\n";
	std::cout << totalSalt << " grams of salt\n";
	std::cout << totalYeast << " grams of yeast\n";
	std::cout << totalWater << " grams of water\n:";
	
	return 0;
}
