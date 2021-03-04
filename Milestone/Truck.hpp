#ifndef TRUCK_HPP
#define TRUCK_HPP

#include "Car.hpp"

class Truck : public Car {
    public:
        Truck();
        Truck(const Truck& c);
        void operator=(const Truck& c);

        void drive(const Coordinate& destination);
        int drop_all();

        void load(int load_weight);
    
    private:
        int total_load_weight;
};

#endif