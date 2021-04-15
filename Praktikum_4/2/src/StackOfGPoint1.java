import java.util.ArrayList;

public class StackOfGPoint1 {
    private final int defaultStackSize = 10; //ukuran default stack
    private int size; //ukuran stack
    private int topStack; //indeks top (data teratas) dari stack
    private ArrayList<GPoint<Integer>> data; //penyimpanan elemen stack
    private static int nStack = 0; //jumlah stack yang pernah dibuat

   //Inisiasi stack berukuran default
    public StackOfGPoint1(){
        this.size = defaultStackSize;
        this.topStack = -1;
        this.data = new ArrayList<GPoint<Integer>>();
        nStack++;
    }
    //Inisiasi stack berukuran size
    public StackOfGPoint1(int size){
        this.size = size;
        this.topStack = -1;
        this.data = new ArrayList<GPoint<Integer>>();
        nStack++;
    } 
    //Menambahkan elemen baru ke stack
    public void Push(GPoint<Integer> p){
        if(IsFull()==0){
            this.data.add(p);
            this.topStack++;
        }
    }
    //Mengeluarkan elemen top stack
    public GPoint<Integer> Pop(){
        if(IsEmpty()==0){
            GPoint<Integer> elemen = this.data.get(this.topStack);
            this.data.remove(elemen);
            this.topStack--;
            return elemen;
        }else{
            return null;
        }
    }
    //Memeriksa apakah stack kosong
    public int IsEmpty(){
        if(this.topStack==-1){
            return 1;
        }else{
            return 0;
        }
    } 
    //Memeriksa apakah stack penuh
    public int IsFull(){
        if(this.topStack==this.size-1){
            return 1;
        }else{
            return 0;
        }
    } 
    //Mengembalikan jumlah stack yang pernah dibuat
    public static int NumStackObj(){
        return nStack;
    } 
}
