/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 30,2021

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include"Book.h"

using namespace std;

namespace sdds{

	void Book::set(const char* title, int SKU, int daysOnLoan){
		if (title[0] != 0 && title != nullptr ){
			if (SKU > 0 && daysOnLoan > 0) {
				strcpy(m_title, title);
				m_SKU = SKU;
				m_daysOnLoan = daysOnLoan;
			}

		}
		else{
			setEmpty();
		}
	}

	bool Book::isEmpty()const{
		bool res = false;
		if (m_title[0] == 0) {
			res = true;
		}
		return res;
	}

	bool Book::hasPenalty()const{
		bool res = false;
		if (m_daysOnLoan > MAXLOAN) {
			res = true;
		}
		return res;
	}
	
	bool Book::subTitle(const char* CHAR_MATCH){
		bool res = false;
		char* CHECK;
		CHECK = strstr(m_title, CHAR_MATCH);
		if (CHECK) {
			res = true;
		}
		return res;
	}

	void Book::display()const{
		int CHECK = 0;
		if (isEmpty()){
			
			cout << "Invalid Library book" << endl;
		}
		else{
			cout.width(49);
			cout.setf(ios::left);
			cout << m_title;
			cout.unsetf(ios::left);
			cout.width(8);
			cout.setf(ios::left);
			cout << m_SKU;
			cout.unsetf(ios::left);
			cout.width(10);
			cout.setf(ios::left);
			cout << m_daysOnLoan;
			CHECK = hasPenalty();
			if (CHECK) {
				cout.unsetf(ios::left);
				cout.width(7);
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << penalty();
				cout.unsetf(ios::fixed);

			}
			cout << endl;
		}
	}

	void Book::setEmpty(){
		m_title[0] = 0;
		m_SKU = 0;
		m_daysOnLoan = 0;
	}

	double Book::penalty()const{
		int OVER_DUE = 0;
		double C_PENALTY = 0;

		OVER_DUE = m_daysOnLoan - MAXLOAN;
		C_PENALTY = OVER_DUE * PENALTY;

		return C_PENALTY;
	}
};
