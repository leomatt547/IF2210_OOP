#include "WarungSaltedEgg.hpp"
#include <iostream>
using namespace std;

WarungSaltedEgg::WarungSaltedEgg(int uang, int nasi, int telur, int telurAsin, int ayam) : WarungNasi(uang, telur, nasi){
    this->telurAsin = telurAsin;
    this->ayam = ayam;
}

bool WarungSaltedEgg::masak(int pesanan) {
    if (WarungNasi::getNasi() < pesanan && WarungNasi::getTelur() < pesanan && this->telurAsin < 3*pesanan && this->ayam < pesanan) {
        return false;
    } else {
        int pendapatan = pesanan * 30000;
        WarungNasi::setUang(getUang() + pendapatan);
        return true;
    }
}
