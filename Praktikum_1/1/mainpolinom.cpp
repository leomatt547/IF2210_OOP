#include <iostream>
#include "Polinom.cpp"

int main(int argc, char const *argv[])
{
    Polinom P = Polinom(3);
    Polinom Q = Polinom(P);
    Polinom R = Polinom();
    Q.input();
    R = P;
    P.print();
    R.print();
    Q.print();
    cout << "Substitute " << Q.substitute(5) << endl;
    return 0;
}
