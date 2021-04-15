public class SilverMember extends Member{
    SilverMember(){
        super();
        setState(STATE.SILVER);
    }

    SilverMember(int id2){
        super(id2);
        setState(STATE.SILVER);
    }

    public STATE getState() {
        return STATE.SILVER;
    }
}
