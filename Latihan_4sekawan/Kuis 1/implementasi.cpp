#include <iostream>
#include "deretlampu.hpp"
#include "lampu.hpp"

using namespace std;

//Implementasi Lampu
Lampu::Lampu(){
    this->nomor = 0;
    this->nyala = 0;
}

Lampu::Lampu(int nomor, bool nyala){
    this->nomor = nomor;
    this->nyala = nyala;
}

Lampu::Lampu(const Lampu& L){
    this->nomor = L.nomor;
    this->nyala = L.nyala;
}

Lampu& Lampu::operator=(const Lampu& L){
    this->nomor = L.nomor;
    this->nyala = L.nyala;
    return *this;
}

Lampu::~Lampu(){
    cout << "Lampu " << this->nomor << "Dibuang" << endl;
}

void Lampu::set_nyala(){
    this->nyala = 1;
}

void Lampu::set_mati(){
    this->nyala = 0;
}

bool Lampu::get_info(){
    if(this->nyala == 0){
        cout << "Lampu nomor " << this->nomor << "Tidak Menyala";
    }else{
         cout << "Lampu nomor " << this->nomor << "Menyala";
    }
}

//Implementasi Deret Lampu
Deret_Lampu::Deret_Lampu(){
   deret = new Lampu[100];
   Lampu::Lampu(1,0);
   Lampu::Lampu(2,0);
   Lampu::Lampu(3,0);
   Lampu::Lampu(4,0);
   Lampu::Lampu(5,0);
   Lampu::Lampu(6,0);
   Lampu::Lampu(7,0);
   Lampu::Lampu(8,0);
   Lampu::Lampu(9,0);
   Lampu::Lampu(10,0);
   this->size = 100;
   this->neff = 10;
}

Deret_Lampu::Deret_Lampu(int n){
   deret = new Lampu[100];
   Lampu::Lampu(1,0);
   Lampu::Lampu(2,0);
   Lampu::Lampu(3,0);
   Lampu::Lampu(4,0);
   Lampu::Lampu(5,0);
   Lampu::Lampu(6,0);
   Lampu::Lampu(7,0);
   Lampu::Lampu(8,0);
   Lampu::Lampu(9,0);
   Lampu::Lampu(10,0);
   this->size = 100;
   this->neff = 10;
   this->size = 100;
   this->neff = min(n,10);
}

Deret_Lampu::Deret_Lampu(const Deret_Lampu& dl){
   this->deret = new Lampu[100];
   this->size = dl.size;
   this->neff = dl.size;
   for (int i = 0; i<dl.neff ; i++){
       this->deret[i] = dl.deret[i];
   }
}

Deret_Lampu& Deret_Lampu::operator= (const Deret_Lampu& dl){
    this->deret = new Lampu[100];
    this->size = dl.size;
    this->neff = dl.size;
    for (int i = 0; i<dl.neff ; i++){
       this->deret[i] = dl.deret[i];
    }
    return *this;
}

Deret_Lampu::~Deret_Lampu(){
    delete [] deret;
    this->size = 0;
    this->neff = 0;
}

Deret_Lampu& Deret_Lampu::operator*=(const Deret_Lampu& dl){
    this->deret = new Lampu[100];
    this->size *= 2;
    this->neff *= 2;
    for (int i = 0; i<dl.neff ; i++){
       this->deret[i] = dl.deret[i];
    }
    for(int i=dl.neff; i<=dl.neff*2; i++){
        Lampu::Lampu(i,0);
    }
    return *this;
}

void Deret_Lampu::atur_nyala(int){
    int i = 0;
    Lampu L;
    while (i<(this->neff)){
        L.nomor = i;
        L.set_nyala();
        i += int
    }
}