//Abstract Base Class
#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include "Coordinate.hpp"

using namespace std;

template <class T>
class Vehicle{
    public:
        Vehicle();
        Vehicle(const Vehicle<T>& c);
        void operator=(const Vehicle<T>& c);
        ~Vehicle();

        virtual void drive(const Coordinate<T>& destination) = 0;
        void get_in(string name, int pos);
        int drop_all();        
};

template <class T>
class Drivable{
    public:
        virtual void drive(const Coordinate<T>& destination) = 0;
};

template <class T>
class Ridable {
    public:
        virtual void get_in(string name, int pos) = 0;
        virtual int drop_all() = 0;
};

template <class T>
void say_and_go(Drivable<T>& o , Coordinate<T> dest){
    cout << "go!" << endl;
    o.drive(dest);
}

#endif