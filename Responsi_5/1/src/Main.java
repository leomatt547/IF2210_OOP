public class Main {
    public static void main(String[] args) throws Exception {
        Dompet<Integer> d = new Dompet<Integer>();
        d.addMoney(50000);
        d.printTransactions();
    }
}
