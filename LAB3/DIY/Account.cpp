/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 3,2021

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include"Account.h"

using namespace std;

namespace sdds {
	void ACCOUNT::set(int acc_no, double balance, int days) {
		if (acc_no != 0) {
			if (balance > 0 && days > 0) {
				m_acc_no = acc_no;
				m_balance = balance;
				m_days = days;
			}
		}
		else {
			setEmpty();
		}
	}

	bool ACCOUNT::isEmpty()const {
		bool res = false;
		if (m_acc_no == 0) {
			res = true;
		}
		return res;
	}

	bool ACCOUNT::hasPenalty()const {
		bool res = false;
		if (m_days > INTEREST_FREE_DAYS) {
			res = true;
		}
		return res;
	}



	double ACCOUNT::display()const {
		int CHECK = 0;
		double INTEREST = 0;
		if (isEmpty()) {

			cout << "Invalid Bank account" << endl;
		}
		else {
			cout.width(10);
			cout.setf(ios::left);
			cout << m_acc_no;
			cout.unsetf(ios::left);

			cout.width(12);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_balance;
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);


			cout << "  ";
			cout.width(4);
			cout.setf(ios::left);
			cout << m_days;
			cout.unsetf(ios::left);

			CHECK = hasPenalty();
			if (CHECK) {
				cout.width(8);
				cout.setf(ios::right);
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << penalty();
				cout.unsetf(ios::fixed);
				cout.unsetf(ios::right);

				INTEREST += penalty();
			}

			cout << endl;
		}
		return INTEREST;
	}

	void ACCOUNT::setEmpty() {
		m_acc_no = 0;
		m_balance = 0;
		m_days = 0;
	}

	double ACCOUNT::penalty()const {
		double OVER_DUE = 0, C_PENALTY = 0;

		OVER_DUE = INTEREST_RATE / 365;
		C_PENALTY = m_days * OVER_DUE * m_balance;

		return C_PENALTY;
	}

}