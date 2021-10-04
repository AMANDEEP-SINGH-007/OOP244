/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 3,2021

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef ACCOUNT_H
#define ACCOUNT_H
namespace sdds {

	const int INTEREST_FREE_DAYS = 30;
	const double INTEREST_RATE = 0.285;

	class ACCOUNT {
	private:
		int m_acc_no;
		double m_balance;
		int m_days;
		void setEmpty();
		double penalty()const;


	public:
		void set(int acc_no, double balance, int days);
		bool isEmpty()const;
		bool hasPenalty()const;
		double display()const;

	};


};

#endif // !ACCOUNT_H