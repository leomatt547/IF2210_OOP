public class Time {
    private int hour;
    private int minute;
    private int second;

    public Time() {
        // Set seluruh atribut dengan nilai 0
        this.hour = 0;
        this.minute = 0;
        this.second = 0;
    }

    public Time(int hour, int minute, int second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public Time(Time t) {
        // Set atribut dengan atribut milik t
        this.hour = t.hour;
        this.minute = t.minute;
        this.second = t.second;
    }

    public int getHour() {
        return this.hour;
    }

    public void setHour(int hour) {
        this.hour = hour; 
    }

    public int getMinute() {
        return this.minute;
    }

    public void setMinute(int minute) {
        this.minute = minute; 
    }

    public int getSecond() {
        return this.second;
    }

    public void setSecond(int second) {
        this.second = second;
    }

    public int convertToSecond() {
        return (3600 * this.hour + 60 * this.minute + this.second);
    }

    public Time add(Time t) {
        // Return penjumlahan dua objek jam, yaitu *this* dan t.
        // Apabila hasil penjumlahan melebihi 23:59:59, maka Anda harus mengonversinya seperti tampilan jam digital asli.
        // Contoh : 24:00:00 dituliskan 00:00:00, 25:00:00 dituliskan 01:00:00, dst.
        Time tot = new Time();
        int sum = convertToSecond() + t.convertToSecond();
        tot.hour = (sum/ 3600) % 24;
        sum -= hour * 3600;
        tot.minute = (sum / 60) % 60;
        sum -= minute * 60;
        tot.second = sum % 60;
        return tot;
    }

    public Time minus(Time t) {
        // Return selisih antara dua objek jam, yaitu *this* dan t.
        // Perhitungan selisih hanya dapat dilakukan jika objek ruas kiri lebih akhir dari atau sama dengan objek ruas kanan.
        // Jika objek ruas kiri lebih awal, maka kembalikan nilai objek ruas kiri.
        // Contoh: 00:00:01 - 00:00:02 = 00:00:01
        Time tot = new Time();
        if (!lessThan(t)) {
            int sum = convertToSecond() - t.convertToSecond();
            tot.hour = (sum / 3600) % 24;
            sum -= hour * 3600;
            tot.minute = (sum / 60) % 60;
            sum -= minute * 60;
            tot.second = sum % 60;
        }else{
            tot.hour = this.hour;
            tot.minute = this.minute;
            tot.second = this.second;
        }   
        return tot;
    }

    public boolean lessThan(Time t) {
        // Returns true jika *this* < t menurut definisi waktu
        return (convertToSecond() < t.convertToSecond());
    }

    public boolean greaterThan(Time t) {
        // Returns true jika *this* > t menurut definisi waktu
        return (convertToSecond() > t.convertToSecond());
    }

    public void printTime() {
        // Menuliskan jam dalam format hh:mm:ss diakhiri dengan newline. Perhatikan bahwa setiap parameter harus dituliskan 2 digit.
        if (this.hour < 10) {
            System.out.print(0);
        }
        System.out.print(this.hour);
        System.out.print(":");
        if (this.minute < 10) {
            System.out.print(0);
        }
        System.out.print(this.minute);
        System.out.print(":");
        if (this.second < 10) {
            System.out.print(0);
        }
        System.out.print(this.second + "\n");
    }
}