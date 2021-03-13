#ifndef STACK_H
#define STACK_H

class Stack{
    public:
    //deklarasi ctor, cctor, dtor & assignment operator

    void push(int x);
    int pop();
    friend std::istream& operator>>(istream& os, Stack& stack){
        if (topStack < currentCapacity){
            for(int i = 0; i < 1; ++i){
                is >> stack.data[stack.topStack+1];
                stack.topStack++;
            }
            return is;
        }
    }

    private:
    int * data; // array untuk menampung elemen pada Stack
    int currentCapacity; //ukuran alokasi array pada data
    int topStack; //posisi stack saat ini
};
#endif