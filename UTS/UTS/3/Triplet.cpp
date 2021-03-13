#include <iostream>

using namespace std;

template <class T, class U, class V>
class Triplet{
    private:
        T First;
        U Second;
        V Third;
    public:
        Triplet(T _First, U _Second, V _Third){
            First = _First;
            Second = _Second;
            Third = _Third;
        }
        T getFirst() const{
            return First;
        }
        U getSecond() const{
            return Second;
        }
        V getThird() const{
            return Third;
        }
        bool operator==(const Triplet& _Triplet){
            return (First==_Triplet.First && Second==_Triplet.Second && Third==_Triplet.Third);
        } 
};

int main(int argc, char const *argv[])
{
    Triplet<string, float, string> a("abc", 4.5, "def");
    Triplet<string, float, string> b("ghi", -1.0, "def");
    Triplet<string, float, string> c("abc", 4.5, "def");

    if (a == b) {
    cout << "a == b" << endl;
    }
    if (a == c) {
    cout << "a == c" << endl;
    }

}
