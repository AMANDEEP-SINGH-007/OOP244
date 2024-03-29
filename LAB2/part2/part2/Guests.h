/*
    Name   : - Amandeep Singh
    ID     : 145041208
    Email  : asingh984@myseneca.ca
    Section: OOP244 NCC
    Date   : OCT 18,2021

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

namespace sdds {

    struct PhoneNumber {
        int m_number;
        int m_areacode;
    };

    struct Guest {
        char m_name[21];
        PhoneNumber m_phno;
    };

    struct GuestList {
        Guest* m_gst;
        int m_noOfGuests;
    };

    void read(char* str, int len);
    void read(PhoneNumber& thePhoneNumber);
    bool read(Guest& theGuest);
    void print(const PhoneNumber& thePhoneNumber);
    void print(const Guest& theGuest);
    void print(const GuestList& theGuestList);
    void addGuest(GuestList& theGuestList, const Guest& aGuest);
}