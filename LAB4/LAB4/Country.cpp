/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 30,2021
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Country.h"

using namespace std;

namespace sdds {

	Country::Country(){
		m_name = nullptr;
		m_city = nullptr;
		m_noOfCity = 0;
	}

	Country::Country(const char* name, int noOfCity, const City* cities){
		m_name = nullptr;
		m_city = nullptr;
		m_noOfCity = 0;
		int i;
		if (name != nullptr && name[0] != 0 && cities != nullptr &&noOfCity > 0){

			setName(name);
			m_noOfCity = noOfCity;

			if (noOfCity <= MAX_CITY && noOfCity >= 0 ){
				m_city = new City[noOfCity];

				for (i = 0; i < noOfCity; i++){
					m_city[i] = cities[i];
				}
			}
		}
	}

	void Country::setName(const char* name){
		delete[] m_name;
		if (name != nullptr && name[0] != 0){
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		else{
			delete[] m_city;
			setEmpty();
		}
	}

	Country& Country::addCity(const City& c){
		int i;
		if (!(c.isEmpty())){
			
			City* TEMP_POINTER = new City[m_noOfCity + 1];
			
			for (i = 0; i < m_noOfCity; i++){
				TEMP_POINTER[i] = m_city[i];
			}

			delete[] m_city;
			TEMP_POINTER[m_noOfCity] = c;
			m_city = TEMP_POINTER;
			m_noOfCity++;
		}

		return *this;
	}

	Country& Country::migrate(int people){
		int i;

		for (i = 0; i < m_noOfCity; i++){

			if (m_city[i].getPeople() < POPULATION){
				m_city[i].addPopulation(people);
			}

		}

		return *this;
	}

	void Country::setEmpty(){
		m_name = nullptr;
		m_city = nullptr;
		m_noOfCity = 0;
	}

	bool Country::isEmpty()const {
		bool res = false;
		if (m_name == nullptr){
			res = true;
		}
		return res;
	}

	Country::~Country(){
		delete[] m_name;
		delete[] m_city;
	}

	void Country::display()const{
		int i;
		if (isEmpty()){
			cout << "Invalid country object" << endl;
		}
		else{
			cout << "Country Name:";
			cout << m_name << endl;
			cout << "No of city:";
			cout << m_noOfCity << endl;
			cout.width(32);
			cout.setf(ios::left);
			cout << "City Name";
			cout.unsetf(ios::left);
			cout << "Population" << endl;
			for ( i = 0; i < m_noOfCity; i++){
				m_city[i].display();
			}
		}
	}
}