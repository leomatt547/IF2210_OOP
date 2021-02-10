#ifndef _FOOMEM_HPP
#define _FOOMEM_HPP

#include <iostream>

class FooMem{
    private:
    int * Mem;
    int Size;
    int Left;
    int Right;
    const int Max;

    public:
    //ctor
    FooMem();
    //ctor objek bertype FooMem, memori dialokasikan sebesar _s
    //size=_s<=Max
    FooMem(int _s);
    //cctor
    FooMem(FooMem& F);
    //dtor
    ~FooMem();
    //operator
    FooMem& operator=(FooMem& F);

    //Fungsi
    //Mengembalikan Posisi Mem yang terisi terakhir di kiri
    int GetLeft();
    //Mengembalikan Posisi Mem yang terisi terakhir di kanan
    int GetRight();

    //Predikat Kosong
    bool IsEmpty() const;
    //Predikat Penuh
    bool IsFull() const;

    //Add
    void Add(int x); //Menambahkan x ke Mem dengan aturan yang dijelaskan
    //Del
    int Del(); //Menghapus elemen FooMem sesuai aturan
    //PrintAll
    void PrintAll();
};
#endif