import java.util.ArrayList;

public class IdentityService extends AbstractService {
    private final ArrayList<String> identityList = new ArrayList<String>();
    public IdentityService(String name) {
        super(name);
    }
    @Override
    public void init() {
        setServiceState(STATE.INIT);   
    }
    @Override
    public void start() {
        setServiceState(STATE.RUNNING);   
    }
    @Override
    public void stop() {
        setServiceState(STATE.DIE);   
    }

    public ArrayList<String> getIdentity(){
        return this.identityList;
    }

    public void addIdentity(String a){
        if (a.equals("RUNNING")){
            identityList.add(a);
        }
    }

    public void removeIdentity(String a){
        if (a.equals("RUNNING")){
            identityList.remove(a);
        }
    }

    public Boolean isIdentityExist(String a){
        if(!a.equals("RUNNING")){
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
