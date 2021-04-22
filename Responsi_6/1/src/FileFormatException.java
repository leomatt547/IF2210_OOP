public class FileFormatException extends Exception{
    /**
     * Exception untuk mengecek kesalahan File
     */
    private static final long serialVersionUID = -8474880941254814506L;
    private final String errorMessage;
    public FileFormatException() {
        errorMessage = "Format salah";
    }
    public String getErrorMessage(){
        return errorMessage;
    }
    
}
