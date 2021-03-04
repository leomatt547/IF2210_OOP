//Abstract Base Class
#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include "Coordinate.hpp"

using namespace std;

class Vehicle{
    public:
        Vehicle();
        Vehicle(const Vehicle& c);
        void operator=(const Vehicle& c);
        ~Vehicle();

        virtual void drive(const Coordinate& destination) = 0;
        void get_in(string name, int pos);
        int drop_all();        
};

class Drivable{
    public:
        virtual void drive(const Coordinate& destination) = 0;
};

class Ridable {
    public:
        virtual void get_in(string name, int pos) = 0;
        virtual int drop_all() = 0;
};

void say_and_go(Drivable& o , Coordinate dest){
    cout << "go!" << endl;
    o.drive(dest);
}

#endif