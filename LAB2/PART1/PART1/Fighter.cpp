#define _ CRT_SECURE_NO_WARNINGS
#include <iostream>
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

		Fighter* INFO = nullptr;
		INFO = new Fighter[myCompetition.numfighters + 1];

		int i;
		for (i = 0; i < myCompetition.numfighters; i++) {

			INFO[i] = myCompetition.fighters[i];

		}

		cout << "Information of the new fighter:" << endl;

		fighter(INFO[myCompetition.numfighters].name);
		fighter(INFO[myCompetition.numfighters].power);

		delete[] myCompetition.fighters;
		myCompetition.fighters = nullptr;
		myCompetition.fighters = INFO;

		myCompetition.numfighters++;
	}


	void removeFighter(Competition& mycompetition, const Fighter& loserFighter) {
		int numfighters, loserFighterIndex;
		numfighters = mycompetition.numfighters;
		Fighter* fighters = nullptr;
		fighters = new Fighter[numfighters - 1];
		loserFighterIndex = findFighter(mycompetition, loserFighter);
		for (int i = 0, j = 0; i < numfighters; i++) {
			if (loserFighterIndex != i) {
				fighters[j] = mycompetition.fighters[i];
				j++;
			}
		}
		mycompetition.numfighters--;
		delete[] mycompetition.fighters;
		mycompetition.fighters = fighters;
	}

	int findFighter(const Competition& mycompetition, const Fighter& theFighter) {
		int fighterIndex = -1;
		int temp, keepGoing = 1;

		for (int i = 0; i < mycompetition.numfighters && keepGoing; i++) {
			temp = strcmp(mycompetition.fighters[i].name, theFighter.name);
			fighterIndex = temp == 0 ? i : -1;
			keepGoing = !(fighterIndex == i);

		}
		return fighterIndex;
	}

	bool fight(const Fighter& f1, const Fighter& f2) {
		bool value;
		value = f1.power > f2.power;
		return value;
	}

	void fight(Competition& mycompetition, Fighter& f1, Fighter& f2) {
		cout << "    " << f1.name << " will fight " << f2.name << "..." << endl;
		bool value = fight(f1, f2);
		if (value) {
			cout << "    " << "The winner => ";
			display(f1);
			removeFighter(mycompetition, f2);

			cout << endl;
		}
		else {
			cout << "    " << "The winner => ";
			display(f2);
			removeFighter(mycompetition, f1);

			cout << endl;
		}

	}
}