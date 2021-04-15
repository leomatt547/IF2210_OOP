public class ListMap implements Map{
    /**
     * Menambahkan (key, value) ke dalam map
     * Melakukan overwrite jika sudah terdapat elemen dengan key yang sama.
     */
    public void set(String key, String value){
        /*boolean found = false;
        while(!found){
            if (MapEntry.getKey().equals(key)){
                found = true;
            }
        }
        new MapEntry(key, value);
        */
    }

    /**
     * Mengembalikan value yang tersimpan untuk key tertentu pada map
     * Mengembalikan NULL apabila map tidak mengandung key masukan.
     */
    public String get(String key){
        return "NULL";
    }

    /**
     * Menghitung jumlah elemen yang ada pada map
     */
    public int size(){
        return 0;
    }
}
