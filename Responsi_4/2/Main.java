public class Main {
    public static void main(String[] args) {
        Rekening rekening;
        Transaksi[] last;
        last = new Transaksi[10];
        rekening = new Rekening(10);
        //System.out.println(rekening.getJumlahTransaksi());
        rekening.simpanUang(50000);

        rekening.tarikUang(-439000);
        
        System.out.println(rekening.getSaldo());
        last = rekening.getLastTransaksi(1);
        int i = 0;
        while (last[i]!=null) {
            System.out.println(last[i].getRekening());
            System.out.println(last[i].getPerubahan());
            i++;
        }

    }
}
