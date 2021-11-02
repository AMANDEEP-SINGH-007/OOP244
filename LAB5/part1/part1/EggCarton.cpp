/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 15,2021
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "EggCarton.h"
using namespace std;

namespace sdds{

	EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize){
		if (size % 6 == 0 && size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size){
			m_size = size;
			m_noOfEggs = noOfEggs;
			m_jumbo = jumboSize;
		}
		else{
			setBroken();
		}
	}

	void EggCarton::setBroken() {
		m_size = -1;
		m_noOfEggs = -1;
	}

	ostream& EggCarton::display(std::ostream& ostr) const{
		if (*this){
			// displays an Egg Carton
			int cartonWidth = m_size == 6 ? 3 : 6;
			for (int i = 0; i < m_size; i++) {
				cout << ((i < m_noOfEggs) ? (m_jumbo ? 'O' : 'o') : '~');
				if ((i + 1) % cartonWidth == 0) cout << endl;
			}
		}
		else{
			ostr << "Broken Egg Carton!" << endl;
		}
		return ostr;
	}

	istream& EggCarton::read(std::istream& istr){
		m_jumbo = false;

		char CHAR_READ;
		istr >> CHAR_READ;

		if (CHAR_READ == 'j'){
			m_jumbo = true;
		}

		istr.ignore();
		istr >> m_size;

		istr.ignore();
		istr >> m_noOfEggs;

		if (!(m_size % 6 == 0 && m_size >= 6 && m_size <= 36 && m_noOfEggs >= 0 && m_noOfEggs <= m_size)) {
			setBroken();
		}
		return istr;
	}

	EggCarton::operator bool() const{
		bool res = false;
		if (m_size > 0){
			res = true;
		}
		return res;
	}

	EggCarton::operator int() const{
		int res = -1;
		if (*this){
			res = m_noOfEggs;
		}
		return res;
	}

	EggCarton::operator double() const{
		double res = -1.0;
		if (*this){

			if (!(m_jumbo)){
				res = (double(m_noOfEggs) * RegularEggWieght) / 1000.0;
			}
			else{
				res = (double(m_noOfEggs) * JumboEggWieght) / 1000.0;
			}
		}
		return res;
	}


	EggCarton& EggCarton::operator--(){
		if (*this && m_noOfEggs > 0){
			m_noOfEggs--;
		}
		return *this;
	}

	EggCarton& EggCarton::operator++(){
		if (*this){
			m_noOfEggs++;
		}
		else if (m_noOfEggs > m_size){
			setBroken();
		}
		return *this;
	}

	EggCarton EggCarton::operator--(int){
		EggCarton COPY = *this;
		operator--();
		return COPY;
	}

	EggCarton EggCarton::operator++(int){
		EggCarton COPY = *this;
		operator++();
		return COPY;
	}

	EggCarton& EggCarton::operator=(int value){
		m_noOfEggs = value;

		if (m_noOfEggs > m_size){
			setBroken();
		}
		return *this;
	}

	EggCarton& EggCarton::operator+=(int value){
		if (*this){
			m_noOfEggs += value;
			if (m_noOfEggs > m_size) {
				setBroken();
			}
		}
		return *this;
	}
	
	EggCarton& EggCarton::operator+=(EggCarton& right) {
		int RIGHT_EGGS = 0;
		if (*this){
			RIGHT_EGGS = right.m_noOfEggs;
			m_noOfEggs += RIGHT_EGGS;
			if (m_noOfEggs > m_size){
				RIGHT_EGGS = m_noOfEggs - m_size;
				m_noOfEggs = m_size;
				right.m_noOfEggs = RIGHT_EGGS;
			}
			else{
				RIGHT_EGGS = 0;
			}

		}
		return *this;
	}


	bool EggCarton::operator==(const EggCarton& right) const {
		bool res = false;
		double WEIGHT_CURRENT_OBJECT = *this, WEIGHT_RIGHT_CARTON = right;

		double DIFFERENCE = WEIGHT_CURRENT_OBJECT - WEIGHT_RIGHT_CARTON;

		if (DIFFERENCE > -0.001 && DIFFERENCE < 0.001) {
			res = true;
		}

		return res;
	}

	int operator+(int left, const EggCarton& right) {
		int SUM = left;
		if (right) {
			SUM = 0;
			SUM = left + int(right);
		}
		return SUM;
	}

	ostream& operator<<(ostream& ostr, const EggCarton& right) {
		right.display(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, EggCarton& right) {
		right.read(istr);
		return istr;
	}

}