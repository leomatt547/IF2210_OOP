#include "Car.hpp"

Car::Car(){
    this->passenger_count = 0;
    this->passengers = new string[4];
    cout << "construct" << endl;
}

Car::Car(const Car& c){
    passenger_count = c.passenger_count;
    passengers = new string[4];
    for (int i = 0; i < 4; i++){
        passengers[i] = c.passengers[i];
    }
    cout << "copy construct" << endl;
}

void Car::operator=(const Car& c){
    passenger_count = c.passenger_count;
    for (int i = 0; i < 4; i++){
        passengers[i] = c.passengers[i];
    }
    cout << "assignment" << endl;
}

Car::~Car(){
    delete[] passengers;
    cout << "destruct" << endl;
}

void Car::drive() const{
    print_sound();
    cout << "driving with " << passenger_count << endl;
    for( int i = 0; i < 4; i++){
        if (passengers[i] != ""){
            cout << "- " << passengers[i] << endl;
        }
    }
}

void Car::get_in(string name, int pos){
    passengers[pos] = name;
    passenger_count += 1;
}

int Car::drop_all(){
    int dropped = passenger_count;
    passenger_count = 0;
    for(int i = 0; i < 4; i++){
        passengers[i] = "";
    }
    return dropped;
}

int Car::get_max_passenger(){
    return 4;
}

void Car::print_sound() const{
    cout << "vroom" << endl;
}

bool check_seat(Car c, int pos){
    //mengembalikan true jika kursi nomor{pos} tidak kosong
    return c.passengers[pos] != "";
}