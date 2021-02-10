#include "kendaraan.hpp"
#include <string>
#include <iostream>

using namespace std;

Kendaraan::Kendaraan(){
    this->nomor = 0;
    this->tahun = 0;
    this->merk = "XXX";
    this->kategori = "mobil";
}

Kendaraan::Kendaraan(int nomor, string kategori, string merk, int tahun){
    this->nomor = nomor;
    this->tahun = tahun;
    this->merk = merk;
    this->kategori = kategori;
}

Kendaraan::Kendaraan(const Kendaraan& kendaraan){
    this->nomor = kendaraan.nomor;
    this->tahun = kendaraan.tahun;
    this->merk = kendaraan.merk;
    this->kategori = kendaraan.kategori;
}

Kendaraan::~Kendaraan(){
    //    
}

Kendaraan& Kendaraan::operator=(const Kendaraan& kendaraan){
    this->nomor = kendaraan.nomor;
    this->tahun = kendaraan.tahun;
    this->merk = kendaraan.merk;
    this->kategori = kendaraan.kategori;
    return *this;
}

void Kendaraan::PrintInfo() const{
    cout << "Nomor: " << this->nomor << endl;
    cout << "Kategori: " << this->kategori << endl;
    cout << "Merk: " << this->merk << endl;
    cout << "Tahun Keluaran: " << this->tahun << endl;
}

long Kendaraan::BiayaSewa(int lamaSewa) const{
    if (this->kategori == "bus"){
        return (1000000*lamaSewa);
    } else if (this->kategori == "minibus"){
        if (lamaSewa <= 5){
            return(5000000);
        }else{
            return(5000000+500000*(lamaSewa-5));
        }
    }else{
        return(500000*lamaSewa);
    }
}

