import java.util.ArrayList;

public class CompositeService extends AbstractService {
    private ArrayList<AbstractService> serviceList = new ArrayList<AbstractService>();
    CompositeService(String name){
        super(name);
    }
    @Override
    public void init() {
        this.setServiceState(STATE.INIT);
        for (AbstractService as : serviceList) {
            as.init();
        }
    }
    @Override
    public void start() {
        this.setServiceState(STATE.RUNNING);   
        for (AbstractService as : serviceList) {
            as.start();
        }
    }
    @Override
    public void stop() {
        int count = 0;
        for (AbstractService abstractService : serviceList) {
            if(abstractService.getServiceState() == STATE.RUNNING){
                count += 1;
            }
        }
        System.out.print("RUNNING service total : ");
        System.out.print(count + "\n");
        this.setServiceState(STATE.DIE);
        for (AbstractService as : serviceList) {
            as.stop();
        }
    }

    public ArrayList<AbstractService> getServices(){
        return (this.serviceList);
    }

    public void addService(AbstractService a){
        if (this.getServiceState() != STATE.DIE){
            serviceList.add(a);
        }
    }

    public void removeService(AbstractService a){
        if (this.getServiceState() != STATE.DIE){
            serviceList.remove(a);
        }
    }
}
