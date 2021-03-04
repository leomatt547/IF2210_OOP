#include "Truck.hpp"

using namespace std;

Truck::Truck() : Car(){
    this->total_load_weight = 0;
}

Truck::Truck(const Truck& c){
    Car::operator=(c);
    total_load_weight = c.total_load_weight;
}

void Truck::load(int load_weight){
    total_load_weight = load_weight;
}

void Truck::drive(const Coordinate& destination){
    Car::drive(destination);
    cout << "with load " << total_load_weight << endl;
}

int Truck::drop_all(){
    int n = Car::drop_all();
    total_load_weight = 0;
    return n;
}