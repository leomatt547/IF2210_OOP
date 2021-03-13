#include <iostream>
#include <string.h>

class array{
    protected:
        int size;
        int *data;
    public:
        array(const int i_size): size(i_size), data(new int[size]){
            std::cout << "cctor" << std::endl;
            memset(data, '\0',size * sizeof(data[0]));
        }
        array(const array &src){
            std::cout << "cctor" << std::endl;
            size = src.size;
            data = new int[src.size];
            memcpy(data, src.data, size * sizeof(data[0]));
        }
        virtual ~array(void){
            std::cout << "dtor" << std::endl;
            delete []data;
            data = NULL;
        }
        array &operator=(const array &src){
            std::cout << "operator=" << std::endl;
            delete []data;
            size = src.size;
            data = new int[src.size];
            memcpy(data, src.data, size * sizeof(data[0]));
            return (*this);
        }
        int &operator [](const unsigned int item){
            std::cout << "operator[]" << std::endl;
            return data[item];
        }
};

void copy_array(array &dest, const array &src){
    std::cout << "copy array" << std::endl;
    dest = src;
}

int main(){
    array a(30), b(2);
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    copy_array(b, a);
    copy_array(a, a);
    std::cout << "a[0]: " << a[0] << ", a[1]: "<< a[1] << ", a[2]: " << a[2] << std::endl;
    std::cout << "b[0]: " << b[0] << ", b[1]: "<< b[1] << ", b[2]: " << b[2] << std::endl;
    return (0);
}

//Kesalahan: alamat dari a dicopy ke value yang alamatnya sama dengan valuenya