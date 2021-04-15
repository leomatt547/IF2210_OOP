public class Member{
    protected int id;
    public enum STATE {
        NEW,GOLD,SILVER
    }

    protected STATE memberState;
    
    public Member() {
		this.id = 0;
        this.memberState = STATE.NEW;
	}

    public Member(int id2) {
		this.id = id2;
        this.memberState = STATE.NEW;
	}

    public int getid(){
        return this.id;
    }

    public void setState(STATE state){
        this.memberState = state;
    }

}
