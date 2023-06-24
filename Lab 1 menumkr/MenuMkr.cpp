/*
A program used to display a resturants name and the Prix Fixe servings of the day.
Papa Tortalino wanted a program for his resturant website to be able to 
give the Prix Fixe menu for the day to display on his website for the customers.
*/
#include <iostream>
using namespace std;
int main() {
	std::string Name = "Tortalino's Italian Restaurant";
	std::string Appetizer = "Appetizer: Mozzarella sticks.\n";
	// Adds cost value of 2 dollars
	std::string Entree = "Entree: Pasta with Italian Meatballs.\n";
	// Adds cost value of 5 dollars
	std::string Dessert = "Dessert: Cannoli.\n";
	// Adds cost value of 1 dollar
	std::cout << Name << endl;
	std::cout << Appetizer << Entree << Dessert;
	//total cost 8 dollars
	return 0;
}