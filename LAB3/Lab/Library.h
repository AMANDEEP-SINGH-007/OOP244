/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 30,2021

	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef LIBRARY_H
#define LIBRARY_H
#include"Book.h"
namespace sdds{

	class Library{
	private:
		char m_name[31];
		Book* m_books;
		int m_sizeOfBooksArray;
		int m_addedBooks;
		void setEmpty();
		bool isEmpty()const;
		void header(const char* title)const;
		void footer()const;

	public:
		void clear();
		void initialize(const char* name, int noOfBooks);
		bool addBook(const char* book_title, int sku, int loanDays);
		void display(const char* substr);
		void display(bool overdueOnly = false)const;
	};
}
#endif // !LIBRARY_H
