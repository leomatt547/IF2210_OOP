#include <iostream>
#include "FooMem.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    FooMem *F1, *F2;
    F1 = new FooMem();
    F1->Add(5);
    F1->Add(4);
    F1->Add(3);
    F1->Add(2);
    F1->PrintAll();
    
    return 0;
}
