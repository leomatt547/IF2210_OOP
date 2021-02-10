#include "kendaraan.hpp"
#include "koleksikendaraan.hpp"
#include <iostream>
#include <string>

using namespace std;

KoleksiKendaraan::KoleksiKendaraan(){
    this->size = 100;
    this->Neff = 0;
    koleksi = new Kendaraan[this->size];
}

KoleksiKendaraan::KoleksiKendaraan(int size){
    this->size = size;
    this->Neff = 0;
    koleksi = new Kendaraan[this->size];
}

KoleksiKendaraan::KoleksiKendaraan(const KoleksiKendaraan& KK){
    this->size = KK.size;
    this->Neff = KK.Neff;
    koleksi = new Kendaraan[this->size];
    for(int i = 0; i < this->Neff; i++){
        koleksi[i] = KK.koleksi[i];
    }
}

KoleksiKendaraan::~KoleksiKendaraan(){
    delete [] koleksi;
    this->size = 0;
    this->Neff = 0;
}

KoleksiKendaraan& KoleksiKendaraan::operator=(const KoleksiKendaraan& KK){
    this->size = KK.size;
    this->Neff = KK.Neff;
    koleksi = new Kendaraan[this->size];
    for(int i = 0; i < this->Neff; i++){
        this->koleksi[i] = KK.koleksi[i];
    }
    return *this;
}

void KoleksiKendaraan::PrintAll(){
    int i;
    if (this->Neff == 0){
        cout << "Tidak ada kendaraan" << endl;
    }else{
        for (i = 0; i<Neff; i++){
            cout << "[" << i << "]" << endl;
            koleksi[i].PrintInfo();
        }
    }
}

KoleksiKendaraan& KoleksiKendaraan::operator<<(const Kendaraan& K){
    koleksi[this->Neff] = K;
    this->Neff++;
    return *this;
}

KoleksiKendaraan& KoleksiKendaraan::operator<<(const KoleksiKendaraan& KK){
    int i, j;
    int currNeff = this->Neff;
    if(this->Neff + KK.Neff > this->size){
        this->Neff = this->size;
    }else{
        this->Neff += KK.Neff;
    }

    for(i=currNeff; i<this->Neff; i++){
        this->koleksi[i] = KK.koleksi[i-currNeff];
    }
    return *this;
}