#include <iostream>

class X{
    protected:
    int a;
};
class Y: public X{
    public:
    void set(X x, int c){
        x.a = c;
    }
};
// Salah di a karena non accesible