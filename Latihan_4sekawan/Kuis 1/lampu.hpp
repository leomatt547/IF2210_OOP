class Lampu {
  private:
    int nomor;
    bool nyala;
  public:
    Lampu();  /* ctor: membuat Lampu */
    Lampu(int nomor, bool nyala); /* ctor: membuat Lampu dengan identitas nomor dan status nyala lampu */
    Lampu(const Lampu&); /* cctor  */
    Lampu& operator= (const Lampu&); /* operator assignment */
    ~Lampu();                        /* dtor */	
    void set_nyala(/*int*/); /* Mengeset nilai true untuk status nyala lampu sesuai nomor lampu */
    void set_mati(/*int*/); /* Mengeset nilai false untuk status nyala lampu sesuai nomor lampu */
    bool get_info(/*int*/); /* Memperoleh info status nyala lampu saat ini sesuai nomor lampu */
};
