import java.util.ArrayList;

public class CompositeService extends AbstractService {
    private ArrayList<AbstractService> serviceList = new ArrayList<AbstractService>();
    CompositeService(String name){
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
        int count = 0;
        for (AbstractService abstractService : serviceList) {
            if(abstractService.getServiceState() == STATE.RUNNING){
                count += 1;
            }
        }
        System.out.print("RUNNING service total : ");
        System.out.print(count + "\n");
    }

    public ArrayList<AbstractService> getServices(){
        return (this.serviceList);
    }

    public void addService(AbstractService a){
        if (a.getServiceState() != STATE.DIE){
            serviceList.add(a);
        }
    }

    public void removeService(AbstractService a){
        if (a.getServiceState() != STATE.DIE){
            serviceList.remove(a);
        }
    }
}
