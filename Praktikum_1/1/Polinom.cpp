//Nama : Leonard Matheus
//NIM : 13519215
//Topik : Praktikum 1

#include <iostream>
#include "Polinom.hpp"

using namespace std;

Polinom::Polinom() : Polinom(0){}

Polinom::Polinom(int n){
    this->derajat = n;
    koef = new int[n+1];
    for(int i = 0; i<=derajat;i++){
        this->koef[i] = 0;
    }
}

Polinom::Polinom(const Polinom& P){
    this->derajat = P.derajat;
    koef = new int[P.derajat+1];
    for(int i = 0; i<=P.derajat;i++){
        this->koef[i] = P.koef[i];
    }
}

Polinom::~Polinom(){
    delete [] this->koef;
}

Polinom& Polinom::operator=(const Polinom& P){
    this->derajat = P.derajat;
    koef = new int[P.derajat+1];
    for(int i = 0; i<=P.derajat;i++){
        this->koef[i] = P.koef[i];
    }
    return *this;
}

int Polinom::getKoefAt(int idx) const{
    return this->koef[idx];
}

int Polinom::getDerajat() const{
    return this->derajat;
}

void Polinom::setKoefAt(int idx, int val){
    this->koef[idx] = val;
}

void Polinom::setDerajat(int derajat2){
    this->derajat = derajat2;
}

void Polinom::input(){
    for(int i = 0; i<=this->derajat; i++){
        cin >> this->koef[i];
    }
}

void Polinom::printKoef(){
    for(int i = 0; i<=this->derajat; i++){
        cout << this->koef[i] << endl;
    }
}

int Polinom::substitute(int x){
   int faktor = 1;
   int total = this->getKoefAt(0);
   for (int i=1; i <=this->derajat; i++){
       faktor *= x;
       total += faktor*this->getKoefAt(i);
   }
   return total;
}

void Polinom::print() {
    bool cetak = 0;
    for (int i = 0; i <= getDerajat(); i++) {
        if (getKoefAt(i) != 0) {
            if (getKoefAt(i) > 0 && cetak)
                cout << "+";
            if (getKoefAt(i) < 0)
                cout << "-";
            if (i == 0) {
                cout << abs(getKoefAt(i));
            }else{
                if (abs(getKoefAt(i)) != 1){
                    cout << abs(getKoefAt(i));
                }
                cout << "x^" << i;
            }
            cetak = 1; //mengecek apakah sudah ada polinom yang pernah kecetak
        }
    }if (!cetak){
        cout << "0";
    }
    cout << "" << endl;
}