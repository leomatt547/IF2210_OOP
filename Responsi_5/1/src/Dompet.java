import java.util.*;

public class Dompet<T extends Number> {
    private ArrayList<Transaction<T>> transactions;


    public Dompet() {
        // Constructor tanpa parameter, transactions diinisialisasi dengan array list baru
        transactions = new ArrayList<Transaction<T>>();
    }


    public Dompet(T initialBalance) {
        // Constructor dengan parameter T initialBalance, inisialisasi transactions dengan array list baru dan tambahkan transaksi tambah dengan value initial balance
        /* contoh transaksi tambah: new Transaction<T>('+', initialBalance) */
        transactions = new ArrayList<Transaction<T>>();
        transactions.add(new Transaction<T>('+', initialBalance));
    }

    public void addMoney(T money) {
        // Buat prosedur addMoney dengan parameter T money, tambahkan transaksi tambah dengan senilai money
        transactions.add(new Transaction<T>('+', money));
    }

    public boolean takeMoney(T money) {
        // Tambahkan transaksi kurang sebesar money (perlu ada pengecekan apakah balance cukup atau tidak)
        // false bila transaksi gagal, true bila berhasil
        Double d = getBalance();
        if (money.doubleValue() <= d) {
			transactions.add(new Transaction<T>('-', money));
			return true;
		} else {
			return false;
		}
    }

    public void setBalance(T balance) {
        // Mengganti transaksi agar bernilai sama dengan balance
        // Tips: inisialisasi ulang transactions, lalu tambahkan transaksi tambah sebanyak balance
        transactions = new ArrayList<Transaction<T>>();
		transactions.add(new Transaction<T>('+', balance));
    }

    // Akses nilai Double dilakukan dengan .doubleValue()
    // Contoh: amount.doubleValue()

    public Double getBalance(){
        //Mencari balance dompet dari transaksi dengan cara menghitung total transaksi
        Double d = 0.0;
        for (int i = 0; i < transactions.size(); i++) {
			if (transactions.get(i).getType() == '+') {
				d += transactions.get(i).getAmount().doubleValue();
			} else {
				d -= transactions.get(i).getAmount().doubleValue();
			}
		}
		return d;
    }

    public void printTransactions() {
        // Print seluruh transaksi yang ada pada array
        // Format: Transactions [indeks + 1]: [tipe transaksi] [amount]
        // Contoh: Transactions 3: + 500
        for (int i = 0; i < transactions.size(); i++) {
			int idx = i+1;
			System.out.println("Transactions " + idx + ": " + transactions.get(i).getType() + " " + transactions.get(i).getAmount());
		}
    }

    public Double getAverageTransaction() {
        // Mencari rata-rata transaksi (jika tidak ada transaksi, berikan hasil null)
        if (transactions.size() == 0) {
			return null;
		} else {
			return getBalance() / transactions.size();
		}
    }

    public Double getMinimumTransaction() {
        // Mencari nilai minimum transaksi (jika tidak ada transaksi, berikan hasil null; hanya perlu membandingkan nilainya saja tanpa peduli type)
        if (transactions.size() == 0) {
			return null;
		} else {
			Double min = transactions.get(0).getAmount().doubleValue();
			for (int i = 1; i < transactions.size(); i++) {
				if (min > transactions.get(i).getAmount().doubleValue()) {
					min = transactions.get(i).getAmount().doubleValue();
				}
			}
			return min;
		}
    }

    public Double getMaximumTransaction() {
        // Mencari nilai maksimum transaksi (jika tidak ada transaksi, berikan hasil null; hanya perlu membandingkan nilainya saja tanpa peduli type)
        if (transactions.size() == 0) {
			return null;
		} else {
			Double max = transactions.get(0).getAmount().doubleValue();
			for (int i = 1; i < transactions.size(); i++) {
				if (max < transactions.get(i).getAmount().doubleValue()) {
					max = transactions.get(i).getAmount().doubleValue();
				}
			}
			return max;
		}
    }
}
