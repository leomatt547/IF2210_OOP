//g++ -o car Car.cpp main.cpp
#include "Car.hpp"

void f(Car c){
    Car* c1 = new Car();
    Car* c2 = new Car(c);
    Car c3 = c;
    delete c1;
    cout << "keluar dari f" << endl;
}
/*
int main(){
    Car mcqueen, redCar;
    f(mcqueen);
    redCar = mcqueen;
}*/

int main(int argc, char const *argv[])
{
    Car sally;

    sally.drive();
    cout << "---" << endl;

    sally.get_in("john", 0);
    sally.get_in("jane", 2);
    sally.drive();
    cout << "---" << endl;

    sally.drop_all();
    sally.drive();
    cout << "---" << endl;

    cout << Car::get_max_passenger() << endl;
    return 0;
}
