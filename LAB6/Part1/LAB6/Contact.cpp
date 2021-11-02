/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 27,2021
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;

namespace sdds {
	bool Book::validBook(const char* bookTitle, const char* authorName, int bookCaseNumber, int shelfNumber)const {
		bool res = false;
		if (bookTitle != nullptr && bookTitle[0] != 0 && authorName != nullptr && authorName[0] != 0 && bookCaseNumber >= 1 && bookCaseNumber <= NoOfBookCases && shelfNumber >= 1 && shelfNumber <= NoOfShelves) {
			res = true;
		}
		return res;
	}

	void Book::setEmpty() {
		m_bookTitle = nullptr;
		m_authorName = nullptr;
	}

	void Book::allocateAndCopy(const char* bookTitle, const char* authorName) {
		delete[] m_bookTitle;
		m_bookTitle = new char[strlen(bookTitle) + 1];
		strcpy(m_bookTitle, bookTitle);

		delete[] m_authorName;
		m_authorName = new char[strlen(authorName) + 1];
		strcpy(m_authorName, authorName);
	}

	void Book::extractChar(std::istream& istr, char ch)const {
		char CHAR = istr.peek();
		if (CHAR == ch) {
			istr.get();
		}
		else {
			istr.setstate(ios::failbit);
		}
	}

	void Book::set(const char* bookTitle, const char* authorName, int bookCaseNumber, int shelfNumber) {
		if (validBook(bookTitle, authorName, bookCaseNumber, shelfNumber)) {
			allocateAndCopy(bookTitle, authorName);
			m_bookCaseNumber = bookCaseNumber;
			m_shelfNumber = shelfNumber;
		}
		else {
			delete[] m_authorName;
			delete[] m_bookTitle;
			setEmpty();
		}
	}

	Book::Book(const Book& cnt) {
		if (cnt) {
			set(cnt.m_bookTitle, cnt.m_authorName, cnt.m_bookCaseNumber, cnt.m_shelfNumber);
		}
	}

	Book::Book(const char* bookTitle, const char* authorName, int bookCaseNumber, int shelfNumber) {
		set(bookTitle, authorName, bookCaseNumber, shelfNumber);
	}

	Book& Book::operator=(const Book& cnt) {
		if (this != &cnt) {
			set(cnt.m_bookTitle, cnt.m_authorName, cnt.m_bookCaseNumber, cnt.m_shelfNumber);
		}
		return *this;
	}

	Book::~Book() {
		delete[] m_authorName;
		delete[] m_bookTitle;
	}

	Book::operator bool() const {
		bool res = false;
		if (m_authorName != nullptr && m_bookTitle != nullptr) {
			res = true;
		}
		return res;
	}

	ostream& Book::write(std::ostream& ostr, bool onScreen = true)const {

		if (onScreen) {
			if (*this) {
				ostr.setf(ios::left);
				ostr.width(40);
				ostr.fill(' ');
				ostr << m_bookTitle;
				ostr << "| ";
				ostr.width(25);
				ostr.fill(' ');
				ostr << m_authorName;
				ostr.unsetf(ios::left);
				ostr << "| ";

				ostr << m_shelfNumber << '/';

				ostr.fill('0');
				ostr.width(3);

				ostr << m_bookCaseNumber << endl;
			}
			else {
				ostr << "Invalid Book Record ................... | ........................ | ....." << endl;
			}
		}
		else {
			if (*this) {
				ostr << m_bookTitle << "," << m_authorName << "," << m_shelfNumber << '/' << m_bookCaseNumber << endl;
			}
			else {
				ostr << "Invalid Book Record" << endl;
			}
		}
		return ostr;
	}

	istream& Book::read(std::istream& istr) {
		int shelfNumber, bookCaseNumber;
		char authorName[MaxAuthorLen];
		char bookTitle[MaxTitleLen];

		istr.get(bookTitle, MaxTitleLen, ',');
		extractChar(istr, ',');

		istr.get(authorName, MaxAuthorLen, ',');
		extractChar(istr, ',');

		istr >> shelfNumber;
		extractChar(istr, '/');

		istr >> bookCaseNumber;
		extractChar(istr, '\n');

		if (!istr.fail()) {
			set(bookTitle, authorName, bookCaseNumber, shelfNumber);
		}

		return istr;
	}

	ostream& operator<<(std::ostream& ostr, const Book& cnt) {
		if (cnt) {
			cnt.write(ostr, false);
		}
		else {
			ostr << "Invalid Phone Record";
		}
		return ostr;
	}

	istream& operator>>(std::istream& istr, Book& cnt) {
		return cnt.read(istr);
	}
}