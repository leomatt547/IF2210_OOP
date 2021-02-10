#include <iostream>
#include "Ball.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Ball b;
    b = Ball(5);
    b.bounce();
    b.~Ball();
    return 0;
}
