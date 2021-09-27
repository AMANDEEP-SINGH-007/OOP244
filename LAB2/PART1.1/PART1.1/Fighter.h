/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 16,2021

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_FIGHTER_H
#define SDDS_FIGHTER_H
namespace sdds {
	const int MAX_NAME = 50;

	struct Fighter {
		char name[MAX_NAME + 1];
		int power;
	};

	struct Competition {
		Fighter* fighters;
		int numfighters;
	};

	void fighter(char* name);
	void fighter(int& power);

	void display(const Fighter& myFighter);
	void display(const Competition& mycompetition);

	void addFighter(Competition& myCompetition);

	void removeFighter(Competition& mycompetition, const Fighter& loserFighter);

	int findFighter(const Competition& mycompetition, const Fighter& theFighter);

	bool fight(const Fighter& f1, const Fighter& f2);
	void fight(Competition& mycompetition, Fighter& f1, Fighter& f2);

	//TODO: Declare the prototypes for the functions required as per the lab instructions

}
#endif /* FIGHTER_H */



