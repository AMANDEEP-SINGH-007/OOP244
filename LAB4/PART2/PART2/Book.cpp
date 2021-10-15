/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 10,2021
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Book.h"
using namespace std;

namespace sdds {

	Book::Book() {
		m_book_name = nullptr;
		m_chapters = nullptr;
		m_no_of_chapters = 0;
	}

	Book::Book(const char* book_name, int no_of_chapters, Chapter* chapters) {
		m_book_name = nullptr;
		m_chapters = nullptr;
		m_no_of_chapters = 0;
		int i;
		if (book_name != nullptr && chapters != nullptr && no_of_chapters > 0) {
			m_book_name = new char[strlen(book_name) + 1];
			strcpy(m_book_name, book_name);
			m_no_of_chapters = no_of_chapters;

			if (no_of_chapters > 0) {
				m_chapters = new Chapter[no_of_chapters];
				for (i = 0; i < no_of_chapters; i++) {
					m_chapters[i] = chapters[i];
				}
			}
		}
	}

	bool Book::isEmpty()const {
		bool res = true;
		if (m_book_name != nullptr && m_no_of_chapters > 0) {
			res = false;
		}
		return res;
	}

	Book& Book::addChapter(const char* chapter_name, int noOfPages) {
		int i;
		Chapter c = Chapter(chapter_name, noOfPages);

		if (!(c.isEmpty()) && noOfPages <= MAX) {
			Chapter* TEMP_POINTER = new Chapter[m_no_of_chapters + 1];

			for (i = 0; i < m_no_of_chapters; i++) {
				TEMP_POINTER[i] = m_chapters[i];
			}

			delete[] m_chapters;
			TEMP_POINTER[m_no_of_chapters] = c;
			m_chapters = TEMP_POINTER;
			m_no_of_chapters++;
		}
		return *this;
	}

	Book::~Book() {
		delete[] m_book_name;
		delete[] m_chapters;
	}

	void Book::display()const {
		int i = 0, CHECK = 1;

		while (i < m_no_of_chapters) {

			if (m_chapters[i].isEmpty()) {
				CHECK = 0;
			}

			i++;
		}

		if (CHECK == 1 && !(isEmpty())) {

			cout << "Book Name: ";
			cout << m_book_name << endl;
			cout << "No of Chapters: ";
			cout << m_no_of_chapters << endl;
			cout << "Chapter name                                       Pages" << endl;
			for (i = 0; i < m_no_of_chapters; i++) {
				m_chapters[i].display();
			}
		}
		else {
			cout << "Invalid Book object" << endl;
		}
	}
}
