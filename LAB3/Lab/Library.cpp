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
#include"Library.h"

using namespace std;

namespace sdds{

	void Library::setEmpty() {
		m_name[0] = 0;
		m_books = nullptr;
		m_sizeOfBooksArray = 0;
		m_addedBooks = 0;
	}

	bool Library::isEmpty()const {
		bool res = false;
		if (m_name[0] == 0) {
			res = true;
		}
		return res;
	}

	void Library::header(const char* title)const {
		int i;

		for (i = 0; i < 78; i++) {
			cout << "-";
		}
		cout << endl;

		cout << "*****  " << m_name << "  *****" << endl;
		cout << title << endl;

		for (i = 0; i < 78; i++) {
			cout << "-";
		}
		cout << endl;

		cout << "Row Book title                                       SKU     loan days penalty" << endl;
		cout << "--- ------------------------------------------------ ------- --------- -------" << endl;
	}


	void Library::footer()const {
		int i;
		for (i = 0; i < 78; i++) {
			cout << "-";
		}
		cout << endl;
	}

	void Library::initialize(const char* name, int noOfBooks){
		if (name != nullptr && name[0] != 0 && noOfBooks > 0){
			strcpy(m_name, name);
			m_books = new Book[noOfBooks];
			m_sizeOfBooksArray = noOfBooks;
			m_addedBooks = 0;
		}
		else{
			setEmpty();
		}
	}

	bool Library::addBook(const char* book_title, int sku, int loadDays) {
		bool res = false;
		if (m_addedBooks < m_sizeOfBooksArray) {
			m_books[m_addedBooks].set(book_title, sku, loadDays);
			if (!m_books[m_addedBooks].isEmpty()) {
				m_addedBooks += 1;
				res = true;
			}
		}
		return res;
	}

	void Library::clear() {
		delete[] m_books;
		m_books = nullptr;
	}

	void Library::display(const char* substr) {

		int ROW_NO = 1, i;
		bool FLAG = false;

		if (isEmpty()) {
			cout << "Invalid Library" << endl;
		}
		else {
			cout << ">>> Searching for: \"";
			cout << substr;
			cout << "\" <<<" << endl;

			header("Substring search");

			for (i = 0; i < m_addedBooks; i++) {
				if (m_books[i].subTitle(substr) == true) {
					cout.width(4);
					cout.setf(ios::left);
					cout << ROW_NO;
					ROW_NO++;
					cout.unsetf(ios::left);
					m_books[i].display();
					FLAG = true;
				}
			}
			if (FLAG == false) {
				cout << "No book title contains \"";
				cout << substr;
				cout << "\"" << endl;
			}

			footer();
		}
	}

	void Library::display(bool overdueOnly)const{

		int ROW_NO = 1, i;

		if (isEmpty()){
			cout << "Invalid Library" << endl;
		}
		else{

			if (overdueOnly) {
				header("Overdue Books");
			}
			else{
				header("Books on Loan");
			}

			for (i = 0; i < m_addedBooks; i++) {
				if (overdueOnly) {
					if (m_books[i].hasPenalty()) {
						cout.width(4);
						cout.precision(2);
						cout.setf(ios::left);
						cout << ROW_NO;
						cout.unsetf(ios::left);
						m_books[i].display();
						ROW_NO++;
					}
				}
				else {
					cout.width(4);
					cout.precision(2);
					cout.setf(ios::left);
					cout << ROW_NO;
					cout.unsetf(ios::left);
					m_books[i].display();
					ROW_NO++;
				}
			}
			footer();
		}
	}


}