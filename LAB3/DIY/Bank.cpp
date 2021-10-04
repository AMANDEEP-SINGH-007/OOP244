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
#include"Bank.h"

using namespace std;

namespace sdds {

	void Bank::setEmpty() {
		m_bank_name[0] = 0;
		m_account = nullptr;
		m_size = 0;
		m_added = 0;
	}

	bool Bank::isEmpty()const {
		bool res = false;
		if (m_bank_name[0] == 0) {
			res = true;
		}
		return res;
	}

	void Bank::header(const char* title)const {
		int i;

		for (i = 0; i < 40; i++) {
			cout << "-";
		}
		cout << endl;

		cout << ">>> " << title << " <<<" << endl;

		for (i = 0; i < 40; i++) {
			cout << "-";
		}
		cout << endl;

		cout << "Row Accnt No       Balance  Days Interest" << endl;
		cout << "--- ---------- ------------ ---- --------" << endl;
	}


	void Bank::footer()const {
		int i;
		for (i = 0; i < 41; i++) {
			cout << "-";
		}
		cout << endl;
	}

	void Bank::initialize(const char* bank_name, int noOfAccounts){
		if (bank_name != nullptr && bank_name[0] != 0 && noOfAccounts > 0) {
			strcpy(m_bank_name, bank_name);
			m_account = new ACCOUNT[noOfAccounts];
			m_size = noOfAccounts;
			m_added = 0;
		}
		else {
			setEmpty();
		}
	}

	bool Bank::addAccount(int account_number, double balance, int daysSinceLastPayment) {
		bool res = false;
		if (m_added < m_size) {
			m_account[m_added].set(account_number, balance, daysSinceLastPayment);
			if (!m_account[m_added].isEmpty()) {
				m_added += 1;
				res = true;
			}
		}
		return res;
	}


	void Bank::clear() {
		delete[] m_account;
		m_account = nullptr;
	}


	void Bank::display(bool intrestOnly)const {

		int ROW_NO = 1, i;
		double INTEREST = 0;

		if (isEmpty()) {
			cout << "Invalid Bank" << endl;
		}
		else {

			if (intrestOnly == true) {
				cout << "INTEREST ONLY LIST!" << endl;
			}

			header(m_bank_name);

			for (i = 0; i < m_added; i++) {
				if (intrestOnly) {
					if (m_account[i].hasPenalty()) {
						cout.width(5);
						cout.setf(ios::left);
						cout << ROW_NO;
						cout.unsetf(ios::left);
						INTEREST += m_account[i].display();
						ROW_NO++;
					}
				}
				else {
					cout.width(5);
					cout.setf(ios::left);
					cout << ROW_NO;
					cout.unsetf(ios::left);
					INTEREST += m_account[i].display();
					ROW_NO++;
				}
			}
			footer();

			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "              Total interest:";
			cout.width(12);
			cout.setf(ios::right);
			cout << INTEREST << endl;
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);
			cout << endl;

		}
	}


}