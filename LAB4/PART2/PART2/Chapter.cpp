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
#include"Chapter.h"
using namespace std;

namespace sdds{

	Chapter::Chapter(){
		m_chapter_name[0] = 0;
		m_noOfPages = -1;
	}

	Chapter::Chapter(const char* chapter_name, int noOfPages){

		if (chapter_name != nullptr && chapter_name[0] != 0 && noOfPages > 0){
			strcpy(m_chapter_name, chapter_name);
			m_noOfPages = noOfPages;
		}
		else{
			m_chapter_name[0] = 0;
			m_noOfPages = -1;
		}
	}


	bool Chapter::isEmpty()const{
		bool res = false;
		if (m_chapter_name[0] == 0 && m_noOfPages < 0) {
			res = true;
		}
		return res;
	}

	void Chapter::display()const{
		if (!isEmpty()){
			cout.fill('.');
			cout.width(50);
			cout.setf(ios::left);
			cout << m_chapter_name;
			cout.unsetf(ios::left);
			cout.fill(' ');
			cout << " ";
			cout.width(3);
			cout << m_noOfPages;
			cout << endl;
		}
		else{
			cout << "invalid Chapter" << endl;
		}
	}

}
