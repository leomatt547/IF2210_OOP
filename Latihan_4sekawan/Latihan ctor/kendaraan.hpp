#ifndef _KENDARAAN_HPP
#define _KENDARAAN_HPP

#include <string>
#include <iostream>
using namespace std;

class Kendaraan{
    private:
    int nomor;
    string kategori;
    string merk;
    int tahun;

    public:
    //Constructor
    Kendaraan();
    Kendaraan(int nomor, string kategori, string merk, int tahun);
    Kendaraan(const Kendaraan& kendaraan);
    Kendaraan& operator= (const Kendaraan& kendaraan);
    ~Kendaraan();

    //Method
    void PrintInfo() const;
    long BiayaSewa(int lamaSewa) const;
};

#endif