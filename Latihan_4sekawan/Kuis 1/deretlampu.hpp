#ifndef _DERETLAMPU_HPP_
#define _DERETLAMPU_HPP_

#include "lampu.hpp"
class Deret_Lampu {
  private:
  Lampu* deret;
  int size;
  int neff;
  public:
    Deret_Lampu();  /* ctor: Membuat array Deret Lampu dengan size 100, Neff = 10.
                             (Termasuk menciptakan 10 lampu awal untuk disimpan dalam array) */
    Deret_Lampu(int); /* ctor: Membuat array Deret Lampu dengan size n, Neff = max(n,10) */
    Deret_Lampu(const Deret_Lampu&); /* cctor */
    Deret_Lampu& operator= (const Deret_Lampu&);  /* operator assignment */
    ~Deret_Lampu();  /* dtor  */
    Deret_Lampu& operator*=(const Deret_Lampu&); /* Melipatgandakan rangkaian lampu: 
                  10 lampu menjadi 20 lampu, dengan nomor 1..20, asumsikan ukuran array cukup */
    void atur_nyala(int); /*Mengatur nyala lampu sesuai dengan aturan pilihan nomor saklar*/
};
#endif
