//Nama : Leonard Matheus
//NIM : 13519215
//Topik : Praktikum 1

#include <iostream>
#include "BunchOfKeys.hpp"

BunchOfKeys::BunchOfKeys(){
    this->n_keys = 0;
}

void BunchOfKeys::add(){
    this->n_keys++;
}

void BunchOfKeys::shake(){
    if(this->n_keys==1){
        cout << "Tidak Terjadi apa-apa" << endl;
    }else{
        for(int i=1; i<=this->n_keys;i++){
            cout << "krincing" << endl;
        }
    }
}

