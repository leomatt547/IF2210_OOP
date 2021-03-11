#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include NDEBUG
#include <cassert>
#include "Coordinate.hpp"
using namespace std;

template<class T, class U>
class Car {
    public:
        Car(){
            this->passenger_count = 0;
            this->passengers = new U[4];
            this->position = new Coordinate<T>();
            cout << "construct" << endl;
        }
        Car (const Car<T,U>& c){
            passenger_count = c.passenger_count;
            passengers = new U[4];
            for (int i = 0; i < 4; i++){
                passengers[i] = c.passengers[i];
            }
            delete position;
            position = new Coordinate<T>(*c.position);
            cout << "copy construct" << endl;
        }
        void operator=(const Car<T,U>& c){
            passenger_count = c.passenger_count;
            for (int i = 0; i < 4; i++){
                passengers[i] = c.passengers[i];
            }
            delete position;
            position = new Coordinate<T>(*c.position);
            cout << "assignment" << endl;
        }
        virtual ~Car(){
            delete[] passengers;
            delete position;
            cout << "destruct" << endl;
        }

        virtual void drive(const Coordinate<T>& destination){
            print_sound();
            cout << "driving with " << passenger_count << endl;
            for( int i = 0; i < 4; i++){
                if (passengers[i] != ""){
                    cout << "- " << passengers[i] << endl;
                }
            }
            delete position;
            position = new Coordinate<T>(destination);
            cout << "arrived at ";
            cout << position->get_x() << "," << position->get_y() << endl;
        }
        void get_in(U name, int pos){
            if (pos < 0 || pos >= 4){
                throw CarSeatOutOfRangeException();
            }
            if (passengers[pos] != ""){
                throw CarSeatAlreadyFilledException();
            }
            passengers[pos] = name;
            passenger_count += 1;

            int tmp_cnt = 0;
            for (int i = 0; i < 4; i++){
                if (passengers[i] != ""){
                    tmp_cnt++;
                }
            }
            assert(tmp_cnt == passenger_count);
        }
        int drop_all(){
            if (passenger_count==0){
                throw "mobil kosong";
            }
            int dropped = passenger_count;
            passenger_count = 0;
            for(int i = 0; i < 4; i++){
                passengers[i] = "";
            }
            return dropped;
        }

        static int get_max_passenger(){
            return 4;
        }
        friend bool check_seat(Car<T,U> c, int pos){
            //mengembalikan true jika kursi nomor{pos} tidak kosong
            return c.passengers[pos] != "";
        }

    protected:
        int passenger_count;
        U* passengers;
        Coordinate<T>* position;
        void print_sound() const{
            cout << "vroom" << endl;
        }
};

class CarSeatAlreadyFilledException : public exception{
    public:
        const char * what() const throw(){
            return "kursi tidak kosong";
        }
};

class CarSeatOutOfRangeException : public exception{
    public:
        const char * what() const throw(){
            return "pos tidak valid";
        }
};
#endif