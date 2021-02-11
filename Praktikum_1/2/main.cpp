//Nama : Leonard Matheus
//NIM : 13519215
//Topik : Praktikum 1
#include "A.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    A * a = new A('1');
    A * b = new A('2');
    A * c = new A(*a);
    *c = *b;
	c->show();
    delete c;
    delete b;
    delete a;
    return 0;
}