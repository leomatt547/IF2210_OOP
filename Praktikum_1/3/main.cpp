/*new empty box 2
new empty box with default id 0
new empty box 1
assign box 0 <- 2
copy box 1
box 2
box 1
destroy box 2
destroy box 1
destroy box 1
destroy box 2*/

#include "Box.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Box * b1 = new Box(2);
    Box * b2 = new Box();
    Box * b3 = new Box(1);
    (*b2) = (*b1);
    Box * b4 = new Box(*b3);
    b1->peek();
    b3->peek();
    delete b1;
    delete b3;
    delete b4;
    delete b2;
    return 0;
}
