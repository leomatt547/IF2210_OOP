import java.util.*;

public class Dompet<T extends Number> {
    private ArrayList<Transaction> transactions;


    public Dompet() {
        // Constructor tanpa parameter, transactions diinisialisasi dengan array list baru
        transactions = new ArrayList<Transaction>();
    }


    public Dompet(T initialBalance) {
        // Constructor dengan parameter T initialBalance, inisialisasi transactions dengan array list baru dan tambahkan transaksi tambah dengan value initial balance
        /* contoh transaksi tambah: new Transaction<T>('+', initialBalance) */
        transactions = new ArrayList<Transaction>();
        transactions.add(new Transaction<T>('+', initialBalance));
    }

    public void addMoney(T money) {
        // Buat prosedur addMoney dengan parameter T money, tambahkan transaksi tambah dengan senilai money
        transactions.add(new Transaction<T>('+', money));
    }

    public boolean takeMoney(T money) {
        // Tambahkan transaksi kurang sebesar money (perlu ada pengecekan apakah balance cukup atau tidak)
        // false bila transaksi gagal, true bila berhasil
        Double saldo = getBalance();
        if(saldo < money.doubleValue()){
            return false;
        }else{
            transactions.add(new Transaction<T>('-', money));
            return true;
        }
    }

    public void setBalance(T balance) {
        // Mengganti transaksi agar bernilai sama dengan balance
        // Tips: inisialisasi ulang transactions, lalu tambahkan transaksi tambah sebanyak balance
        transactions = new ArrayList<Transaction>();
		transactions.add(new Transaction<T>('+', balance));
    }

    // Akses nilai Double dilakukan dengan .doubleValue()
    // Contoh: amount.doubleValue()

    public Double getBalance(){
        Double sum = 0.0;
        // Mencari balance dompet dari transaksi dengan cara menghitung total transaksi
        for (Transaction transaction : transactions) {
            sum += transaction.getAmount().doubleValue();
        }
        return sum;
    }

    public void printTransactions() {
        // Print seluruh transaksi yang ada pada array
        // Format: Transactions [indeks + 1]: [tipe transaksi] [amount]
        // Contoh: Transactions 3: + 500
        for (int i = 0; i < transactions.size(); i++) {
			int indeks = i+1;
			System.out.println("Transactions " + indeks + ": " + transactions.get(i).getType() + " " + transactions.get(i).getAmount());
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
			Double maks = transactions.get(0).getAmount().doubleValue();
			for (int i = 1; i < transactions.size(); i++) {
				if (maks < transactions.get(i).getAmount().doubleValue()) {
					maks = transactions.get(i).getAmount().doubleValue();
				}
			}
			return maks;
		}
    }
}