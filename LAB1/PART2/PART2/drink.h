/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 18,2021

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef DRINK_H // replace with relevant names
#define DRINK_H
namespace sdds {

	struct Drink {
		char name[10];
		int volume;
		double price;
		int quantity;
	};
	
	//commented out this part to read the file and make it operable
	//void loadDrinks();

	void drinkMenu();
	void displayDrink(const Drink* drink);
	int chooseDrink();
	bool updateDrink(int sel);// Your header file content goes here

	//header for part 2
	void loadDrinksFromFile(const char* filename);
}
#endif
