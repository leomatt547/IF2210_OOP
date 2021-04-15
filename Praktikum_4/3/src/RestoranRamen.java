import java.util.*;

public class RestoranRamen{
    private Map<Integer, Integer> daftarMeja;

    //constructor: membuat restoran dengan daftar meja kosong
    public RestoranRamen(){
        daftarMeja = new HashMap<Integer,Integer>();
    }

    //menambahkan jumlah order yang dipesan oleh meja n, dengan harga p
    //jika meja sudah diisi maka akan menambah total yang telah dipesan
    public void tambahOrder(int n, int p){
        //Set<Integer> keys = new HashSet<>();
        //keys = daftarMeja.keySet(); //mengembalikan sebuah set berisi seluruh key pada map
        //memeriksa apakah 1 sudah ada dalam himpunan key
        if(daftarMeja.containsKey(n)){
            int ordernya = daftarMeja.get(n);
            daftarMeja.put(n, (p + ordernya));
        }else{
            daftarMeja.put(n, p);
        }
    }

    //mengembalikan total harga pesanan pada meja n
    //menghapus entri untuk meja tersebut
    public int tutupOrder(int n){
        int harganya = daftarMeja.get(n);
        daftarMeja.remove(n);
        return harganya;
    }

    //mengembalikan total harga pesanan pada meja n
    public int cekTotal(int n){
        return daftarMeja.get(n);
    }

    //mengembalikan jumlah meja yang terisi saat itu
    //restoran mungkin kosong
    public int totalMeja(){
        Set<Integer> keys = new HashSet<>();
        keys = daftarMeja.keySet(); //mengembalikan sebuah set berisi seluruh key pada map
        return keys.size();
    }

    //menjetak semua meja yang terisi pada restoran diakhiri dengan new line
    //contoh:
    /*
        Meja 1 = 5000
        Meja 2 = 3000
        Meja 3 = 10000
    */
    //jika restoran kosong akan mencetak "Restoran kosong" diakhiri new line
    public void cetakMeja(){
        if(totalMeja()==0){
            System.out.println("Restoran kosong");
        }else{
            Set<Integer> keys = new HashSet<>();
            keys = daftarMeja.keySet();
            for (Integer n : keys) {
                System.out.print("Meja ");
                System.out.print(n);
                System.out.print(" = ");
                System.out.print(daftarMeja.get(n));
                System.out.print("\n");
            }
        }
    }
}