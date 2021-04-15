import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;

import Member.STATE;

import java.time.Duration;
import java.io.*;
public class Kasir {
    private int id;
    private List<? extends Member> antrian;
    private boolean gold;
    Kasir(List<? extends Member> antrian){
        this.id = 0;
        antrian = new ArrayList<Member>(); 
        gold = false;
    }

    Kasir(int id2, List<? extends Member> antrian, boolean isgold){
        this.id = id2;
        antrian = new ArrayList<Member>();
        gold = isgold;
    }

    public void setAntrianGold(List<GoldMember> antriangold){
        if(this.gold){
            antrian = antriangold;
        }else{
            System.out.println("Tidak menerima gold");
        }
    }

    LocalTime shiftEnds = LocalTime.of(20,0); // pukul 20:00:00
    LocalTime now = LocalTime.now(); // misal saat ini pukul 19:30:10
    boolean shiftEnded = Duration.between(now,shiftEnds).toMinutes() < 0;
    // false, Duration.between() masih = 29 menit.

    public List<GoldMember> pisahkanAntrian(){
        List<GoldMember> alpha = new ArrayList<GoldMember>();
        for (Member member : this.antrian) {
            if(member.memberState == STATE.GOLD){
                alpha.add(member);
            }
        }
        return alpha;
    }

}
