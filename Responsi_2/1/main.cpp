#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    Vehicle v1 = Vehicle(3, 2);
    Vehicle v2 = Vehicle(v1);
    Vehicle v3 = Vehicle (6,50);
    Car car = Car(8);
    Car car2 = Car(car);
    Car car3 = Car(6);
    Bike bike = Bike();
    car3.drive();
    bike.show();
    bike.ride();
    return 0;
}
