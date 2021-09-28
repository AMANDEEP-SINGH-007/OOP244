/*
    Name   : - Amandeep Singh
    ID     : 145041208
    Email  : asingh984@myseneca.ca
    Section: OOP244 NCC
    Date   : OCT 18,2021

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Guests.h"

using namespace std;

namespace sdds {
    void read(char* str, int len) {
        if (cin.peek() == '\n') cin.ignore(); // checks the incomming character, if it is newline, it will remove it
        cin.getline(str, len);
    }
    
    void read(PhoneNumber& thePhoneNumber){
        cout << "Enter Phone Number [area] [number]: ";
        cin >> thePhoneNumber.m_areacode;
        cin >> thePhoneNumber.m_number;
    
    }
    
    bool read(Guest& theGuest){
        bool res = false;
        cout << "Guest name: ";
        read(theGuest.m_name, 20);
        
        if (theGuest.m_name[0] != 0){
            read(theGuest.m_phno);
            res =  true;
        }
        return res;
    }
    
    void print(const PhoneNumber& thePhoneNumber){
        cout << "(" << thePhoneNumber.m_areacode << ")" << " " << thePhoneNumber.m_number << endl;
    }
    
    void print(const Guest& theGuest){
        cout << theGuest.m_name << ", ";
        print(theGuest.m_phno);
    }
    
    void print(const GuestList& theGuestList){
        int i;
        for (i = 0; i < theGuestList.m_noOfGuests; i++) {
            cout << i + 1 << "- ";
            print(theGuestList.m_gst[i]);
        }
    }
    
    void addGuest(GuestList& theGuestList, const Guest& aGuest){
        int i;
        Guest* G_DATA = nullptr;
        G_DATA = new Guest[theGuestList.m_noOfGuests + 1];
        
        for ( i = 0; i < theGuestList.m_noOfGuests; i++){
            G_DATA[i] = theGuestList.m_gst[i];
        }

        G_DATA[theGuestList.m_noOfGuests] = aGuest; //Professor's help (only this line, not the whole function)
        delete[] theGuestList.m_gst;
        theGuestList.m_gst = G_DATA;
        theGuestList.m_noOfGuests += 1;
    }
}