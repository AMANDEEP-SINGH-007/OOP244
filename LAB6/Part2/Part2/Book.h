/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 27,2021
	I have done most of the code by myself only and only copied the parts my professor provided to complete my workshops and assignments, and also took help from Mitchell Rose ,Email: mjrose1@myseneca.ca, Student ID: 018733147.
*/

#ifndef BOOK_H
#define BOOK_H

namespace sdds{

	const int NoOfBookCases = 132;
	const int NoOfShelves = 7;
	const int MaxAuthorLen = 25;
	const int MaxTitleLen = 40;
	class Book{

		char* m_bookTitle{};
		char* m_authorName{};
		int m_bookCaseNumber;
		int m_shelfNumber;
		void setEmpty();
		void allocateAndCopy(const char* author_name, const char* book_title);
		void extractChar(std::istream& istr, char ch);
		void set(const char* book_title, const char* author_name, int caseNo, int shelfNumber);
	
	public:
		Book();
		Book(const Book& book);
		Book(const char* bookTitle, const char* authorName, int bookCaseNumber, int shelfNumber);
		Book& operator=(const Book& book);
		~Book();
		operator bool()const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr, bool onScreen = true)const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Book& book);
	std::istream& operator>>(std::istream& istr, Book& book);
}
#endif // !BOOK_H
