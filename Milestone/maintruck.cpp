//g++ -o truck Coordinate.hpp Car.cpp Truck.cpp maintruck.cpp
#include <iostream>
using namespace std;

#include "Truck.hpp"
/*
int main(){
    Truck mack;
    Coordinate highway(10, 4);
    mack.get_in("mcqueen", 2);
    mack.load(7);
    mack.drive(highway);

    return 0;
}*/

int main(int argc, char const *argv[])
{
    Truck* mack = new Truck();
    Car* c = mack;
    delete c;

    return 0;
}
