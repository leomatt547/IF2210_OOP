import java.util.ArrayList;
public class Main {
    public static void main(String[] args) throws Exception {
        CompositeService cs = new CompositeService("cs");
        cs.addService(new CompositeService("s1"));
        cs.addService(new CompositeService("s2"));
        cs.init();
        cs.start();
        cs.stop();
        cs.addService(new CompositeService("s3"));
        ArrayList<AbstractService> wah = new ArrayList<AbstractService>();
        wah = cs.getServices();
        for (AbstractService aw : wah) {
            System.out.println(aw.getName());
        }
    }
}
