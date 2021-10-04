/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 3,2021

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef BANK_H
#define BANK_H
#include "Account.h"
namespace sdds{
	

	class Bank {
	private:
		char m_bank_name[31];
		ACCOUNT* m_account;
		int m_size;
		int m_added;
		void setEmpty();
		bool isEmpty()const;
		void header(const char* title)const;
		void footer()const;

	public:
		void initialize(const char* bank_name, int noOfAccounts);
		bool addAccount(int account_number, double balance, int daysSinceLastPayment);
		void display(bool intrestOnly = false)const;
		void clear();
	};

}

#endif // !BANK_H
