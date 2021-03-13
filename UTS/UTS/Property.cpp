#include <iostream>
#include <string>
#include "Property.h"

using namespace std;

Property::Property(string _name, string _type, int _openYear){
    name = _name;
    type = _type;
    openYear = _openYear;
}

Property::Property(){
    name = "noname";
    type = "none";
    openYear = 1900;
}

Property::Property(const Property& _Property){
    name = _Property.name;
    type = _Property.type;
    openYear = _Property.openYear;
}

Property::~Property(){
    //
}

Property& Property::operator=(const Property& _Property){
    this->name = _Property.name;
    this->type = _Property.type;
    this->openYear = _Property.openYear;
    return *this;
}

void Property::set_name(string _name){
    this->name = _name;
}

string Property::get_name() const{
    return name;
}

void Property::set_type(string _type){
    this->type = _type;
}

string Property::get_type() const{
    return type;
}

int Property::get_age(){
    return (CURRENT_YEAR-openYear);
}

void Property::displayInfo(){
    cout << "nama: " << name << endl;
    cout << "umur: " << get_age() << endl;
    cout << "type: " << type << endl;
    cout << "rate: " << rate() << endl;
}

int Property::rate(){
    if (type == "hotel"){
        return (2000000-(get_age()*10000));
    }
    else if (type == "hostels"){
        return (1000000-(get_age()*10000));
    }
    else if (type == "villas"){
        return (5000000-(get_age()*15000));
    }
    else if (type == "cottages"){
        return (6000000-(get_age()*20000));
    }
}

Hotel::Hotel() : Property(){
    this->star = 0;
    this->type = "hotel";
}

Hotel::Hotel(string _name, int _openYear) : Property(_name, "hotel", _openYear){
    this->star = 0;
}

void Hotel::set_star(int _star){
    this->star = _star;
}

int Hotel::get_star() const{
    return star;
}

void Hotel::displayInfo(){
    Property::displayInfo();
    cout << "total rate: " << (rate()*star) << endl;
}

Hostel::Hostel() : Property(){
    this->facility = 0;
    this->type = "hostels";
}

Hostel::Hostel(string _name, int _openYear) : Property(_name, "hostels", _openYear){
    this->facility = 0;
}

void Hostel::set_facility(int _facility){
    this->facility = _facility;
}

int Hostel::get_facility() const{
    return facility;
}

int Hostel::calculateFacility(){
    return 80000*facility;
}

void Hostel::displayInfo(){
    Property::displayInfo();
    cout << "expense: " << calculateFacility() << endl;;
}
