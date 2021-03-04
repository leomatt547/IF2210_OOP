//Nama: Leonard Matheus
//NIM: 13519215
//Topik: Responsi 3
#include "A.hpp"
#include "B.hpp"

int main() {
  B b;
  A* a;
  a = &b;
  a->setValue(888);
  b.setValue(10888);
  
  b.print(); // OUTPUT: (888, 10888)
  return 0;
}