import java.util.*;
import java.io.*;

class test{
    public static void main(String[] args) throws FileNotFoundException{
        String path = "Creation.txt";
        File file = new File(path);
        Scanner sc = new Scanner(file);
        System.out.println("File Contents:");

    
        while (sc.hasNextLine()){
            System.out.println(sc.nextLine());
        }   


        subclass obj = new subclass();

        test.subclass.eruption();
        test.obj.eruption();

        
    }

    static class subclass{
        public static void eruption(){
            System.out.println("ERUPTION");
        }

    }
}