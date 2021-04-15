import java.io.*;

public class NormalPokemon extends Pokemon{
    // Buat constructor tanpa parameter, mencetak "ctor1 NormalPokemon" ke layar
    NormalPokemon(){
        super();
        System.out.println("ctor1 NormalPokemon");
    }

    // Buat constructor dengan parameter String name, mencetak "ctor2 NormalPokemon" ke layar
    NormalPokemon(String name){
        super(name);
        System.out.println("ctor2 NormalPokemon");
    }

    // Buat prosedur checkElement yang mencetak "No element for NormalPokemon" ke layar
    public void checkElement(){
        System.out.println("No element for NormalPokemon");
    }

    // Override prosedur displayClass yang mencetak "Sub Class NormalPokemon"    
    @Override
    public void displayClass() {
        System.out.println("Sub Class NormalPokemon");
    }
}
