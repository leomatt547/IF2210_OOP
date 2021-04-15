public class Main{
    public static void main(String[] args) {
        Time t = new Time(00,00,01);
        Time t1 = new Time(00,00,01);
        Time t2 = t.minus(t1);
        t2.printTime();
    }
}
