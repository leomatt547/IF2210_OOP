// Class Property
// File: Property.h

#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
using namespace std;
#define CURRENT_YEAR 2021

class Property {
  protected: 
  // Atribut
    string name;
    string type; //hotel; hostels; villas; cottages 
    int openYear;
  public:
    // User-defined constructor: set nilai atribut berdasarkan nilai 
    // parameter masukan
    Property(string _name, string _type, int _openYear);
    // Default constructor: set nilai atribut sbb: 
    // name = "noname"; openYear = 1900; type = "none"
    Property();
    // Copy constructor
    Property(const Property& _Property);
    // Destructor
    ~Property();
    // Operator Assignment 
    Property& operator=(const Property& _Property);
    void set_name(string _name);
    string get_name() const;
    void set_type(string _type);
    string get_type() const;
    //asumsikan tahun saat ini dapat diakses dengan 
    // makro CURRENT_YEAR
    int get_age(); 
    //Mencetak nama, umur, type, dan rate Property
    void displayInfo(); 
    int rate();
    //menghitung biaya property sesuai dengan umur dan 
    // tergantung type property

};

class Hotel : public Property{
    private:
        int star;
    public:
        Hotel();
        Hotel(string _name, int _openYear);
        void set_star(int _star);
        int get_star() const;
        virtual void displayInfo();
};

class Hostel : public Property{
    private:
        int facility;
    public:
        Hostel();
        Hostel(string _name, int _openYear);
        void set_facility(int _facility);
        int get_facility() const;
        int calculateFacility();
        virtual void displayInfo();
};

#endif // PROPERTY_H