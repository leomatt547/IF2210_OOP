//Nama : Leonard Matheus
//NIM : 13519215
//Topik : Praktikum 1
#include "A.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    A * a = new A(1);
    A * b = new A(2);
    A * c = new A(3);
    A * d = new A(4);
    *c = *a; //ingat, c jadi '1'
    A * e = new A(5);
    *d = *e; //ingat, d jadi '5'
    delete e;
    A * f = new A(6);
    A * g = new A(*d); //g jadi 5 lagi
    A * b2 = new A(*b);
    *b2 = *f; //ingat b2 jadi 6;
    *a = *g; //ingat a jadi '5'
    b->show();
    delete b;
    delete d;
    delete b2;
    delete a;
    delete c;
    delete f;
    delete g;
    return 0;
}
