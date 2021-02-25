#ifndef _HEWAN_H_
#define _HEWAN_H_

#include <iostream>
#include <string>

using namespace std;

class Hewan{
    public:
        Hewan(string namahewan){nama = namahewan;}
        ~Hewan(){cout << "Hewan mati " << nama << endl;}
        virtual void print(){
            cout << "Hewan ini namanya " << nama << endl;
        }
    protected:
        string nama;
};

class Anjing : public Hewan{
    public:
        Anjing(string namahewan): Hewan::Hewan(namahewan){}
        ~Anjing(){cout << "Anjing mati " << nama << endl;}
        virtual void print(){
            cout << "Anjing ini namanya " << nama << endl;
        }
};

class Kucing : public Hewan{
    public:
        Kucing(string namahewan): Hewan::Hewan(namahewan){}
        virtual ~Kucing(){cout << "Kucing mati " << nama << endl;}
};

class KucingAnggora : public Kucing{
    public:
        KucingAnggora(string namahewan, string pemiliknya): Kucing::Kucing(namahewan){pemilik = pemiliknya;}
        ~KucingAnggora(){cout << "Kucing anggora mati " << nama << endl;}
        void print(){
            cout << "Kucing anggora ini namanya " << nama <<". Pemiliknya adalah "<<pemilik<<endl;
        }
    protected:
        string pemilik;
};

class AnjingBulldog : public Anjing{
    public:
        AnjingBulldog(string namahewan, string pemiliknya) : Anjing::Anjing(namahewan){pemilik = pemiliknya;}
        ~AnjingBulldog(){cout << "Anjing bulldog mati " << nama << endl;}
        void print(){
            cout << "Anjing bulldog ini namanya " << nama<<". Pemiliknya adalah "<<pemilik << endl;
        }
    protected:
        string pemilik;
};

#endif