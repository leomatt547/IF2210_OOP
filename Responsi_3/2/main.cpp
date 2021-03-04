/*
#include "Vehicle.cpp"
#include "Car.cpp"
#include "Bike.cpp"
*/
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"

int main(int argc, char const *argv[])
{
    Car * c1 = new Car(4);
    Car * c2 = new Car(10);
    Bike * b1 = new Bike;
    Vehicle * b2 = new Vehicle(*b1);
    delete b1;
    c2->Vehicle::drive();
    b2->clean();
    c1->drive();
    b2->park();
    delete c2;
    delete b2;
    delete c1;
    return 0;
}
