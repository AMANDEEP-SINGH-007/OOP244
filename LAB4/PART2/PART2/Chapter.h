/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 10,2021
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef CHAPTER_H
#define CHAPTER_H

namespace sdds{

	const int MAX = 200;
	
	class Chapter {
	private:
		char m_chapter_name[50];
		int m_noOfPages;

	public:
		Chapter();
		Chapter(const char* chapter_name, int noOfPages);
		bool isEmpty()const;
		void display()const;
	};
}
#endif // !CHAPTER_H
