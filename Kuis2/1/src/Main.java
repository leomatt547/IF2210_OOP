import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws Exception {
        List<Member> goldmember = new ArrayList<>();
        goldmember.add(new GoldMember(2));
        goldmember.add(new GoldMember(3));
        Kasir kasirgold = new Kasir(1, goldmember, true);
        if(kasirgold.shiftEnds){
            kasirgold.pisahkanAntrian();
        }
    }
}
