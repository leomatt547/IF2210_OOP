#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
using namespace std;

class Car {
    public:
        Car();
        Car (const Car& c);
        void operator=(const Car& c);
        ~Car();

        void drive() const;
        void get_in(string name, int pos);
        int drop_all();

        static int get_max_passenger();
        friend bool check_seat(Car c, int pos);

    private:
        int passenger_count;
        string* passengers;

        void print_sound() const;
};
#endif