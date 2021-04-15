import java.io.*;
/*
import java.nio.charset.Charset;
import java.util.Random;*/

// Buat kelas GhostPokemon yang merupakan turunan dari kelas Pokemon dan mengimplementasi interface ElementalType<String>
public class GhostPokemon extends Pokemon implements ElementalType<String>{
    // Atribut tolong dilihat sendiri pada diagram kelas
    private String id;
    private String elementalName;

    /*public String randomstring() {
        byte[] array = new byte[7]; // length is bounded by 7
        new Random().nextBytes(array);
        String generatedString = new String(array, Charset.forName("UTF-8"));
        return generatedString;
    }*/

    // Buat constructor tanpa parameter, meng-assign "Ghost" ke atribut elementalName dan mencetak "ctor1 GhostPokemon" ke layar
    GhostPokemon(){
        super();
        id = "";
        elementalName = "Ghost";
        System.out.println("ctor1 GhostPokemon");
    }
    // Buat constructor dengan parameter String name, meng-assign "Ghost" ke atribut elementalName dan mencetak "ctor2 GhostPokemon" ke layar
    GhostPokemon(String name){
        super(name);
        id = "";
        elementalName = "Ghost";
        System.out.println("ctor2 GhostPokemon");
    }
    // Buat prosedur checkElement yang mencetak "[name] have [elementName] type" ke layar
    public void checkElement(){
        System.out.println(name + " have " + elementalName + " type");
    }
    // Override prosedur displayClass yang mencetak "Sub Class GhostPokemon"
    @Override
    public void displayClass() {
        System.out.println("Sub Class GhostPokemon");
    }
    // Realisasi prosedur displayAura, mencetak "There is ominous aura around"
    @Override
    public void displayAura() {
        System.out.println("There is ominous aura around");
    }
    // Realisasi prosedur specialSkill, mencetak "Special skill invisible"
    @Override
    public void specialSkill() {
        System.out.println("Special skill invisible");
    }
    // Realisasi setUniqueID dan getUniqueID
    @Override
    public void setUniqueID(String id) {
        this.id = id;
    }

    @Override
    public String getUniqueID() {
        return this.id;
    }
}
