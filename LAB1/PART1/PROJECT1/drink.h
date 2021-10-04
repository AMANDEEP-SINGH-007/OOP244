/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 16,2021

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

	void loadDrinks();
	void drinkMenu();
	void displayDrink(const Drink* drink);
	int chooseDrink();
	bool updateDrink(int sel);// Your header file content goes here
	//void clearBuffer();
	//bool confirm(); Commented out two prototypes because I didnot noticed them when submitting previously. I am really sorry for this stupid mistake.
}
#endif
