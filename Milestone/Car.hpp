#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include "Coordinate.hpp"
using namespace std;

class Car {
    public:
        Car();
        Car (const Car& c);
        void operator=(const Car& c);
        virtual ~Car();

        virtual void drive(const Coordinate& destination);
        void get_in(string name, int pos);
        int drop_all();

        static int get_max_passenger();
        friend bool check_seat(Car c, int pos);

    protected:
        int passenger_count;
        string* passengers;
        Coordinate* position;
        void print_sound() const;
};
#endif