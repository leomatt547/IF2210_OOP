public class GoldMember extends Member{
    GoldMember(){
        super();
        setState(STATE.GOLD);
    }

    GoldMember(int id2){
        super(id2);
        setState(STATE.GOLD);
    }

    public STATE getState() {
        return STATE.GOLD;
    }
}
