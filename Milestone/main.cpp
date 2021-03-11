//g++ -o car Car.cpp main.cpp
#include "Car.hpp"
#include <iostream>
using namespace std;

template <class T, class U>
void f(Car<T, U> c){
    Car<T, U>* c1 = new Car<T, U>();
    Car<T, U>* c2 = new Car<T, U>(c);
    Car<T, U> c3 = c;
    delete c1;
    cout << "keluar dari f" << endl;
}
/*
int main(){
    Car mcqueen, redCar;
    f(mcqueen);
    redCar = mcqueen;
}*/

/*
int main(int argc, char const *argv[])
{
    Car<int, string> sally;
    Coordinate<int> tujuan = Coordinate<int>(5,3);
    Coordinate<int> tujuan2 = Coordinate<int>(6,10);
    sally.drive(tujuan);
    cout << "---" << endl;

    sally.get_in("john", 0);
    sally.get_in("jane", 2);
    sally.drive(tujuan2);
    cout << "---" << endl;

    sally.drop_all();
    sally.drive(tujuan);
    cout << "---" << endl;

    cout << Car<int, string>::get_max_passenger() << endl;
    return 0;
}
*/

int main(int argc, char const *argv[])
{
    int pos;
    string name;
    Car<int,string> c;
    Coordinate<int> garage(1,2);
    try
    {
        cin >> name >> pos;
        c.get_in(name, pos);

        cin >> name >> pos;
        c.get_in(name, pos);
    }
    catch(exception& e){
        cout << e.what() << endl;
    }
    
    c.drive(garage);
    return 0;
}
