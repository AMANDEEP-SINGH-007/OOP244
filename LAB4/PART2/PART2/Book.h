/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 10,2021
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef BOOK_H
#define BOOK_H
#include"Chapter.h"

namespace sdds{
	class Book{
	private:
		char* m_book_name;
		int m_no_of_chapters;
		Chapter* m_chapters;

	public:
		Book();
		Book(const char* book_name, int no_of_chapters, Chapter* chapters);
		bool isEmpty()const;
		Book& addChapter(const char* chapter_name, int noOfPages);
		~Book();
		void display()const;
	};
}
#endif // !BOOK_H