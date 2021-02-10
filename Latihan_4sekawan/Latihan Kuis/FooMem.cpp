#include <iostream>
#include "FooMem.hpp"

using namespace std;

int Maksimum = 10;

FooMem::FooMem():Max(Maksimum) {
    this->Size = Max;
    this->Left = -1;
    this->Right = Max;
    Mem = new int[this->Size];
}

FooMem::FooMem(int _s):Max(Maksimum) {
    if(_s >= Max){
    this->Size = Max;
    this->Left = -1;
    this->Right = this->Size;
    Mem = new int[Max];
}else{
    this->Size = _s;
    this->Left = -1;
    this->Right = this->Size;
    Mem = new int[_s];
    }
}

FooMem::FooMem(FooMem& F) : Max(F.Max){
    this->Size = F.Size;
    this->Left = F.Left;
    this->Right = F.Right;
    this->Mem = new int[F.Size];
    for (int i = 0; i<this->Size;i++){
        this->Mem[i] = F.Mem[i];
    }
}

FooMem& FooMem::operator=(FooMem& F){
    this->Size = F.Size;
    this->Left = F.Left;
    this->Right = F.Right;
    this->Mem = new int[F.Size];
    for (int i = 0; i<this->Size;i++){
        this->Mem[i] = F.Mem[i];
    }
    return *this;
}

FooMem::~FooMem(){
    this->Left = -1;
    this->Right = Max;
    this->Size = 0;
    delete [] Mem;
}

int FooMem::GetLeft(){
    return this->Left;
}

int FooMem::GetRight(){
    return this->Right;
}

bool FooMem::IsEmpty() const{
    return(this->Left==-1 && this->Right==this->Size);
}

bool FooMem::IsFull() const{
    return((this->Left)==(this->Right)-1);
}

void FooMem::Add(int x){
    int kiri = (this->Left)-(-1);
    int kanan = (this->Size)-(this->Right);
    if(!IsFull()){
        if(kiri<=kanan){
            Mem[(this->Left)+1] = x;
            (this->Left)++;
        }else{
            Mem[(this->Right)-1] = x;
            (this->Right)--;
        }
    }
}

int FooMem::Del(){
    int a;
    int kiri = (this->Left)-(-1);
    int kanan = (this->Size)-(this->Right);
    if(!IsFull()){
        if(kiri>kanan){
            a = this->Mem[(this->Left)];
            this->Mem[(this->Left)] = 0;
            (this->Left)--;
        }else{
            a = this->Mem[(this->Right)];
            this->Mem[(this->Right)] = 0;
            (this->Right)++;
        }
    }
    return a;
}

void FooMem::PrintAll(){
    int i;
    if (this->IsEmpty()){
        cout << "Tidak ada elemen" << endl;
    }else{
        for (i = 0; i<this->Size; i++){
            cout << "| " << this->Mem[i] << " |";
        }
        cout << "" << endl;
    }
}