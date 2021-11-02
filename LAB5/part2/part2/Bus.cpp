#include <iostream>
#include "Bus.h"
using namespace std;
namespace sdds {
	Bus::Bus(int noOfSeats, int noOfPassengers) {
		if (noOfSeats % 2 == 0 && noOfSeats >= 10 && noOfSeats <= 40 && noOfPassengers >= 0 && noOfPassengers <= noOfSeats){
			m_noOfSeats = noOfSeats;
			m_noOfPassengers = noOfPassengers;
		}
		else{
			outOfService();
		}
	}

	void Bus::outOfService() {
		m_noOfSeats = -1;
		m_noOfPassengers = -1;
	}

	ostream& Bus::display(std::ostream& ostr)const {
		Bus TEMP = *this;
		double FARE = 0;
		if (m_noOfSeats < 0 && m_noOfPassengers < 0){
			ostr << "Out of service!" << endl;
		}
		else{
			TEMP.drawBus(ostr,m_noOfSeats,m_noOfPassengers);
			FARE = m_noOfPassengers * TICKET_PRICE;
			ostr << "Total Fare Price: " << FARE << endl;
		}
		return ostr;
	}

	istream& Bus::read(std::istream& istr) {
		int noOfSeats,noOfPassengers;
		istr >> m_noOfSeats;
		istr.ignore();

		istr >> m_noOfPassengers;

		if (!(noOfSeats % 2 == 0 && noOfSeats >= 10 && noOfSeats <= 40 && noOfPassengers >= 0 && noOfPassengers <= noOfSeats)) {
			outOfService();
		}
		return istr;
	}

	void Bus::drawBus(std::ostream& ostr, int seats, int psng){
		int i, p;
		ostr.fill('_');
		ostr.width((seats / 2) * 3 + 4);
		ostr << "_";
		ostr << endl << "| ";
		for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < psng ? '2' : ((p == psng) ? '1' : ' ')) << "]");
		ostr << "|_\\_" << endl;
		ostr << "| ";
		ostr.fill(' ');
		ostr.width(((seats / 2) * 3 - 14) / 2);
		ostr << " " << "Seneca College";
		ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
		ostr << " " << "    )" << endl;
		ostr << "`---OO";
		ostr.fill('-');
		ostr.width((seats / 2) * 3 - 5);
		ostr << "-" << "O---'" << endl;
	}
}
