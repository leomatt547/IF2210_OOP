import java.util.ArrayList;

public class IdentityService extends AbstractService {
    private final ArrayList<String> identityList = new ArrayList<String>();
    public IdentityService(String name) {
        super(name);
    }
    @Override
    public void init() {
        this.setServiceState(STATE.INIT);   
    }
    @Override
    public void start() {
        this.setServiceState(STATE.RUNNING);   
    }
    @Override
    public void stop() {
        this.setServiceState(STATE.DIE);   
    }

    public ArrayList<String> getIdentity(){
        return this.identityList;
    }

    public void addIdentity(String a){
        if (this.getServiceState() == STATE.RUNNING){
            identityList.add(a);
        }
    }

    public void removeIdentity(String a){
        if (this.getServiceState() == STATE.RUNNING){
            identityList.remove(a);
        }
    }

    public Boolean isIdentityExist(String a){
        if(this.getServiceState() != STATE.RUNNING){
            return null;
        }else{
            if(identityList.contains(a)){
                return true;
            }else{
                return false;
            }
        }
    }
}
