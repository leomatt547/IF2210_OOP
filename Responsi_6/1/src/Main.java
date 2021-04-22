public class Main {
    public static void main(String[] args) throws Exception {
        Program p = new Program("program.sumatrascript");
        p.addCommand("//komentar");
        p.addCommand("//Ini adalah sebuah komentar");
        p.addCommand("var t = 10;");
        p.addCommand("var x = a + b;");
        p.addCommand("var arr = [];");
        p.removeCommand(1);
        p.removeCommand(1);
        p.removeCommand(1);
        p.removeCommand(1);
        p.removeCommand(1);
        p.addCommand("tes");
        p.addCommand("int x = 10;");
        p.addCommand("/* tes */");
        p.addCommand("method();");
        try{
            p.compile();
        }catch(CompileErrorException e){
            e.showErrors();;
        }
    }
}
