#ifndef BUS_H
#define BUS_H

namespace sdds {
	const double TICKET_PRICE = 125.34;
	class Bus {
	private:
		int m_noOfSeats;
		int m_noOfPassengers;
		void drawBus(std::ostream& ostr, int seats, int psng);
	public:
		Bus(int noOfSeats = 20, int noOfPassengers = 0);
		void outOfService();
		ostream& display(std::ostream& ostr)const;
		istream& read(std::istream& istr);

	};
	ostream& operator<<(ostream& ostr, const Bus& right);
	istream& operator>>(istream& istr, Bus& right);
}
#endif // !BUS_H
