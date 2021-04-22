import java.util.ArrayList;

public class CompileErrorException extends Exception{

    /**
     *
     */
    private static final long serialVersionUID = -3603084513448511846L;
    private ArrayList<Integer> errorLocations = new ArrayList<Integer>();
    CompileErrorException(ArrayList<Integer> error){
        errorLocations = error;
    }
    public void showErrors(){
        for (Integer item : errorLocations) {
            System.out.print("Error di baris : ");
            System.out.print(item);
            System.out.print("\n");
        }
    }
}
