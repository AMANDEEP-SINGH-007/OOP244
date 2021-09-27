#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"
#include "Guests.h"
using namespace std;

namespace sdds {
    void read(char* str, int len) {
        if (cin.peek() == '\n') cin.ignore(); // checks the incomming character, if it is newline, it will remove it
        cin.getline(str, len);
    }

    void read(PhoneNumber& thePhoneNumber) {
        cout << "Enter Phone Number [area] [number]: ";
        cin >> thePhoneNumber.m_areacode >> thePhoneNumber.m_number;


    }
    bool read(Guest& theGuest) {
        cout << "Guest name: ";
        strcpy(theGuest.m_name, "\0");
        read(theGuest.m_name, 20);
        if (strcmp(theGuest.m_name, "\0") == 0) {
            return false;
        }
        else {
            read(theGuest.m_phno);
            return true;
        }

    }
    void print(const PhoneNumber& thePhoneNumber) {
        cout << "(" << thePhoneNumber.m_areacode << ") " << thePhoneNumber.m_number << endl;


    }
    void print(const Guest& theGuest) {
        cout << theGuest.m_name << ", ";
        print(theGuest.m_phno);


    }
    void print(const GuestList& theGuestList) {

        for (int i = 0; i < theGuestList.m_noOfGuests; i++) {
            cout << i + 1 << "- ";
            print(theGuestList.m_gst[i]);
        }

    }
    void addGuest(GuestList& theGuestList, const Guest& aGuest) {

        int arrlength = theGuestList.m_noOfGuests + 1;
        Guest* temp = nullptr;
        temp = new Guest[arrlength];
        for (int i = 0; i < theGuestList.m_noOfGuests; i++) {
            
            strcpy(temp[i].m_name, theGuestList.m_gst[i].m_name);
            temp[i].m_phno = theGuestList.m_gst[i].m_phno;

        }
        temp[arrlength - 1] = aGuest;
        delete[] theGuestList.m_gst;
        theGuestList.m_gst = temp;
        theGuestList.m_noOfGuests++;
	}
}