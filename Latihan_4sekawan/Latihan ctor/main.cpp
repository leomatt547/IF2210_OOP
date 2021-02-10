#include <iostream>
#include <string>
#include "kendaraan.cpp"
#include "koleksikendaraan.cpp"

using namespace std;

int main(int argc, char const *argv[]){
    Kendaraan k;
    k.PrintInfo();
    Kendaraan l(9,"mobil","hyundai",2010);
    l.PrintInfo();
    cout << l.BiayaSewa(10) << endl;
    KoleksiKendaraan kk;
    kk<<k;
    kk<<l;

    cout << "-----------koleksi 1:"<<endl;
    kk.PrintAll();
    KoleksiKendaraan kl;

    Kendaraan m(22,"mobil","hyundai",2010);
    Kendaraan n(23,"mobil","honda",2013);
    kl<<m<<n;

    cout<<"------------koleksi 2:"<<endl;
    kl.PrintAll();

    cout<<"-----------koleksi 1+2:"<<endl;
    kk<<kl;
    kk.PrintAll();
    return 0;
}
