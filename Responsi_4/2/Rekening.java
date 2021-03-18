public class Rekening {
    // Daftar transaksi yang telah dilakukan pada rekening ini
    private Transaksi[] daftarTransaksi;
    // Jumlah transaksi yang telah dilakukan pada rekening ini
    private int jumlahTransaksi;
    // Jumlah transaksi maksimum yang dapat disimpan
    private int maxTransaksi;

    // Konstruktor, dengan nilai maxTransaksi awal
    public Rekening(int maxTrans) {
        this.maxTransaksi = maxTrans;
        this.daftarTransaksi = new Transaksi[maxTrans];
        /*for (int i = 0; i < maxTrans; i++){
            daftarTransaksi[i] = null;
        }*/
        this.jumlahTransaksi = 0;
    }

    // Getter
    public int getJumlahTransaksi() {
        return this.jumlahTransaksi;
    }
    public int getMaxTransaksi() {
        return this.maxTransaksi;
    }

    // Mengembalikan array baru yang berisi `count` transaksi terakhir yang dilakukan
    public Transaksi[] getLastTransaksi(int count) {
        Transaksi[] last;
        last = new Transaksi[count];
        int j = 0;
        for (int i = jumlahTransaksi - count ;i <= jumlahTransaksi-1 ; i++){
            last[j] = this.daftarTransaksi[i];
            j++;
        }
        return last;
    }

    // Mengembalikan saldo pada rekening, yaitu hasil penjumlahan perubahan semua transaksi yang telah dilakukan
    public double getSaldo() {
        double sum = 0;
        for (int i = 0; i < this.jumlahTransaksi ; i++) {
            sum += daftarTransaksi[i].getPerubahan();
        }
        return sum;
    }

    // Membuat transaksi baru yang menambahkan `amount` uang pada rekening.
    // `amount` harus positif dan harus ada sisa tempat di rekening.
    // Mengembalikan status berhasil/gagal penyimpanan uang. (Jika berhasil, mengembalikan true)
    public boolean simpanUang(double amount) {
        if (amount < 0 || this.jumlahTransaksi == this.maxTransaksi){
            return false;
        }else{
            Transaksi input;
            input = new Transaksi(this, amount);
            daftarTransaksi[jumlahTransaksi] = input;
            this.jumlahTransaksi++;
            return true;
        }
    }

    // Membuat transaksi baru yang mengurangi `amount` uang pada rekening.
    // `amount` harus positif dan lebih kecil dari saldo, dan harus ada sisa tempat di rekening.
    // Harus ada sisa tempat di rekening.
    // Mengembalikan status berhasil/gagal penarikan uang. (Jika berhasil, mengembalikan true)
    public boolean tarikUang(double amount) {
        if (amount < 0 || this.getSaldo() <= amount || jumlahTransaksi==maxTransaksi){
            return false;
        }else{
            Transaksi input;
            input = new Transaksi(this, (-1)*amount);
            daftarTransaksi[jumlahTransaksi] = input;
            this.jumlahTransaksi++;
            return true;
        }
    }
}