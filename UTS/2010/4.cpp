#include <iostream>
using namespace std;

int f(int &c){ //Kesalahan: c yang masuk haruslah pointer, gabisa 5 masuk
    return c++;
}

int main(){
    cout << "f(5) = " << f(5) << endl;
    return 0;
}