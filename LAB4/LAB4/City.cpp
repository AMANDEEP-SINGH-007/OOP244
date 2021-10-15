/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 7,2021
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "City.h"

using namespace std;

namespace sdds {

	City::City() {
		m_cityName[0] = 0;
		m_population = -1;
	}

	City::City(const char* name, int population){
		if (name != nullptr && name[0] != 0 && population >= 0){
			strcpy(m_cityName,name);
			m_population = population;
		}
		else {
			setEmpty();
		}
	}

	void City::setEmpty() {
		m_cityName[0] = 0;
		m_population = -1;
	}

	void City::setCityName(const char* name){
		if (name != nullptr){
			strcpy(m_cityName, name);
		}
		else{
			m_cityName[0] = 0;
		}
	
	}

	void City::setPopulation(int population) {
		if (population < POPULATION){
			m_population = population;
		}
		else{
			m_population = -1;
		}
	}

	void City::addPopulation(int population) {
		if (population < POPULATION){
			m_population += population;

			if (m_population > POPULATION){
				m_population = POPULATION;
			}
		}
	}

	bool City::isEmpty()const {
		bool res = false;
		if (m_cityName[0] == 0 || m_population < 0){
			res = true;
		}
		return res;
	}

	int City::getPeople()const {
		return m_population;
	}

	void City::display()const {
		if (!isEmpty()) {

			cout << "|";
			cout.setf(ios::left);
			cout.width(30);
			cout << m_cityName;
			cout.unsetf(ios::left);
			cout << " | ";
			cout.setf(ios::right);
			cout.width(10);
			cout << m_population;
			cout.unsetf(ios::right);
			cout << " | " << endl;
		}
		else {
			cout << "invalid city" << endl;
		}
	}
}