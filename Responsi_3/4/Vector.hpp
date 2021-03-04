#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream>

using namespace std;

template<class T, int U>
class Vector {
    private:
    T* elements;

public:
    Vector() {
        this->elements = new T[U];
    }

    Vector(const Vector<T,U>& other) {
        this->elements = new T[U];
        for(int i = 0; i < U; ++i){
        	this->elements[i] = other.elements[i];
        }
    }

    ~Vector() {
        delete[] this->elements;
    }

    T& operator[](int idx) {
        return this->elements[idx];
    }

    Vector<T,U> operator+(const Vector<T,U>& other) {
        Vector<T,U> result;
        for(int i = 0; i < U; ++i){
            result.elements[i] = this->elements[i] + other.elements[i];
        }
        return result;
    }

    Vector<T,U> operator-(const Vector<T,U>& other) {
        Vector<T,U> result;
        for(int i = 0; i < U; ++i){
            result.elements[i] = this->elements[i] - other.elements[i];
        }
        return result;
    }

    bool operator<(const Vector<T, U>& other) {
        for(int i = 0; i < U; ++i){
            if (elements[i] != other.elements[i]) {
                return elements[i] < other.elements[i];
            }
        }
        return false;
    }

    bool operator>(const Vector<T,U>& other) {
        for(int i = 0; i < U; ++i){
            if (elements[i] != other.elements[i]) {
                return elements[i] > other.elements[i];
            }
        }
        return false;
    }

    friend std::ostream& operator<<(ostream& os, Vector<T,U> vector) {
        os << "<";
        for(int i = 0; i< U; ++i){
            os << vector.elements[i];
            if(i != U-1){
                os << ",";
            }
        }
        os << ">";
        return os;
    }

    friend std::istream& operator>>(istream& is, Vector<T,U>& vector) {
        for(int i = 0; i < U; ++i){
            is >> vector.elements[i];
        }
        return is;
    }

};

#endif