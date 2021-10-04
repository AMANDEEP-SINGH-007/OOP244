/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 30,2021

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef BOOK_H
#define BOOK_H
namespace sdds{

	const double PENALTY = 1.5; // Penalty in dollars for each day a book's return is overdue
	const int MAXLOAN = 15; // Maximum number of days to loan a book witout penalty.

	class Book{
	private:
		char m_title[51];
		int m_SKU;
		int m_daysOnLoan;
		void setEmpty();
		double penalty()const;


	public:
		void set(const char* title, int SKU, int daysOnLoan);
		bool isEmpty()const;
		bool hasPenalty()const;
		bool subTitle(const char* CHAR_MATCH);
		void display()const;
	};


};

#endif // !BOOK_H