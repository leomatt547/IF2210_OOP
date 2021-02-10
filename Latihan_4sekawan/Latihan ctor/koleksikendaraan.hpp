#ifndef _KOLEKSIKENDARAAN_HPP_
#define _KOLEKSIKENDARAAN_HPP_

#include "kendaraan.hpp"

class KoleksiKendaraan{
    private:
    Kendaraan* koleksi;
    int size;
    int Neff;

    public:
    KoleksiKendaraan();
    KoleksiKendaraan(int size);
    KoleksiKendaraan(const KoleksiKendaraan&);
    ~KoleksiKendaraan();
    KoleksiKendaraan& operator=(const KoleksiKendaraan&);
    void PrintAll();
    KoleksiKendaraan& operator<<(const Kendaraan&);
    KoleksiKendaraan& operator<<(const KoleksiKendaraan&);

};
#endif