#include "WarungNasgor.hpp"
#include <iostream>
using namespace std;

WarungNasgor::WarungNasgor(int uang, int nasi, int telur, int kecap) : WarungNasi(uang, telur, nasi){
    this->kecap = kecap;
}

bool WarungNasgor::masak(int pesanan) {
    if (WarungNasi::getNasi() < pesanan && WarungNasi::getTelur() < pesanan && this->kecap < pesanan) {
        return false;
    } else {
        int pendapatan = pesanan * 15000;
        WarungNasi::setUang(getUang() + pendapatan);
        return true;
    }
}
