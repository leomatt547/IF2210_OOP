//Responsi Minggu 9
/* Nama : Leonard Matheus
NIM : 13519215
*/
public class Main {
    public static void main(String[] args) {
        System.out.println("-----1-----");
        A.stat();
        B.stat();
        C.stat();
        D.stat();
        E.stat();
        System.out.println("-----------");
        System.out.println("");
        System.out.println("-----2-----");
        E e = new E();
        C c = new C(10,5);
        D d = new D(3,3);
        A.stat();
        B.stat();
        C.stat();
        D.stat();
        E.stat();
        System.out.println("-----------");
        System.out.println("");
        System.out.println("-----3-----");
        B e2 = new E(1,2);
        C c2 = new C(1,1);
        A d2 = new D(1,1);
        A a2 = new A(1,2);
        B b2 = new B(1,1);
        b2.show();
        d2.show();
        e2.show();
        c2.show();
		a2.show();
        System.out.println("-----------");
		System.out.println();
		System.out.println("-----4-----");
        C c3 = new C(14,4);
        C c4 = new C(15,8);
        A a3 = new A(11,3);
        B b3 = new B(12,5);
        A a4 = new A(10,1);
        D d3 = new D(16,6);
        D d4 = new D(17,7);
        E e3 = new E(18,9);
        B b4 = new B(13,2);
        E e4 = new E(19,0);
        d3.calc();
        d4.calc();
        a3.calc();
        b3.calc();
        e4.calc();
        b4.calc();
        c3.calc();
        c4.calc();
        e3.calc();
        a4.calc();
        System.out.println("-----------");
		System.out.println();
		A.stat();
		B.stat();
		C.stat();
		D.stat();
		E.stat();
    }
}
