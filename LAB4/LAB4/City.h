/*
	Name   : - Amandeep Singh
	ID     : 145041208
	Email  : asingh984@myseneca.ca
	Section: OOP244 NCC
	Date   : OCT 7,2021
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef CITY_H
#define CITY_H
namespace sdds {

	const int POPULATION = 20000; //max population of a city
	class City {
	private:
		char m_cityName[31];// holds the city name up to 30 chars
		int m_population;//number of people. A city can have zero population.
	public:
		City();
		City(const char* name, int population);
		void setEmpty();
		void setCityName(const char* name);
		void setPopulation(int population);
		void addPopulation(int population);
		bool isEmpty()const;
		int getPeople()const;
		void display()const;
	};
}
#endif // !CITY_H