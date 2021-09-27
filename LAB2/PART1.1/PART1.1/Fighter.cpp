/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 16,2021

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _ CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Fighter.h"

using namespace std;
namespace sdds {

	void fighter(char* name) {
		cout << "Enter Fighter Name: ";
		cin >> name;
	}

	void fighter(int& power) {
		cout << "Enter Fighter Power: ";
		cin >> power;
	}

	void display(const Fighter& myFighter) {
		cout << "Name: " << myFighter.name << ", Power: " << myFighter.power << endl;
	}

	void display(const Competition& mycompetition) {
		int i;
		for (i = 0; i < mycompetition.numfighters; i++) {
			display(mycompetition.fighters[i]);
		}
	}

	void addFighter(Competition& myCompetition) {

		Fighter* P_DATA = nullptr;
		P_DATA = new Fighter[myCompetition.numfighters + 1];

		int i;
		for (i = 0; i < myCompetition.numfighters; i++) {
			P_DATA[i] = myCompetition.fighters[i];
		}

		cout << "Information of the new fighter:" << endl;

		fighter(P_DATA[myCompetition.numfighters].name);
		fighter(P_DATA[myCompetition.numfighters].power);

		delete[] myCompetition.fighters;
		myCompetition.fighters = P_DATA;

		myCompetition.numfighters += 1;
	}


	void removeFighter(Competition& myCompetition, const Fighter& loserFighter) {

		int LOSER_INDEX = 0, i, j = 0;

		Fighter* P_DATA = nullptr;
		P_DATA = new Fighter[myCompetition.numfighters - 1];

		LOSER_INDEX = findFighter(myCompetition, loserFighter);

		for (i = 0; i < myCompetition.numfighters; i++) {
			if (LOSER_INDEX != i) {
				P_DATA[j] = myCompetition.fighters[i];
				j++;
			}
		}

		myCompetition.numfighters -= 1;
		delete[] myCompetition.fighters;
		myCompetition.fighters = P_DATA;
	}

	int findFighter(const Competition& mycompetition, const Fighter& theFighter) {
		int F_INDEX = 0;
		int COMPARE = 0, FLAG = 1, i;

		for (i = 0; i < mycompetition.numfighters && FLAG; i++) {

			COMPARE = strcmp(mycompetition.fighters[i].name, theFighter.name);
			if (COMPARE==0){
				F_INDEX = i;
			}
			else{
				F_INDEX = -1;
			}

			if (F_INDEX == i){
				FLAG = 0;
			}
			else{
				FLAG = 1;
			}

		}
		return F_INDEX;
	}

	bool fight(const Fighter& f1, const Fighter& f2) {
		if (f1.power > f2.power) {
			return true;
		}
		else {
			return false;
		}
	}

	void fight(Competition& mycompetition, Fighter& f1, Fighter& f2) {
		cout << "    " << f1.name << " will fight " << f2.name << "..." << endl;
		bool RESULT = fight(f1, f2);
		if (RESULT == false) {
			cout << "    The winner => ";
			display(f2);
			removeFighter(mycompetition, f1);
		}
		else {
			cout << "    The winner => ";
			display(f1);
			removeFighter(mycompetition, f2);
		}

	}
}