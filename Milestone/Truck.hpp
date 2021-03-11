#ifndef TRUCK_HPP
#define TRUCK_HPP

#include "Car.hpp"

template <class T>
class Truck : public Car<T> {
    public:
        Truck() : Car<T>(){
            this->total_load_weight = 0;
        }
        Truck(const Truck<T>& c){
            Car<T>::operator=(c);
            total_load_weight = c.total_load_weight;
        }
        void operator=(const Truck<T>& c);

        void drive(const Coordinate<T>& destination){
            Car<T>::drive(destination);
            cout << "with load " << total_load_weight << endl;
        }
        T drop_all(){
            T n = Car<T>::drop_all();
            total_load_weight = 0;
            return n;
        }

        void load(T load_weight){
            total_load_weight = load_weight;
        }
    
    private:
        T total_load_weight;
};

#endif