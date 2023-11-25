package Main.Life_Game;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Game_field {
    private static int x,y,c,h,grass_percent;

    //private static Herbivore[] herbivores;
    //private static Carnivore[] carnivores;

    private static ArrayList<Herbivore> herbivores;
    private static ArrayList<Carnivore> carnivores;

            static String[][] game_field;
            static Random random = new Random();
    private static int iteration=0;
    private static Scanner sc = new Scanner(System.in);


    public Game_field(int[] preset){
        x =preset[0];
        y =preset[1];
        c =preset[2];
        h =preset[3];
        grass_percent=preset[4];
        //carnivores = new Carnivore[c];
        //herbivores = new Herbivore[h];
        herbivores=new ArrayList<>();
        carnivores=new ArrayList<>();
        generate_field(x,y,grass_percent);
    }


    public static void generate_field(int x, int y, int empty_tiles_percent) {
        game_field = new String[y][x];
        // TODO: THIS IS IMPLEMENTATION BY RANDOM
//        for (int i = 0; i < y; i++) {
//            for (int j = 0; j < x; j++) {
//                game_field[i][j] = (random.nextInt(1, 101) <= empty_tiles_percent) ? "-" : "+";
//            }
//        }
        // TODO: THIS IS MORE ACCURATE IMPLEMENTATION
        // Calculate the number of grass tiles based on empty_tiles_percent
        for (int i = 0; i < y; i++) {
            Arrays.fill(game_field[i], "-");
        }
        int totalTiles = x * y;
        int emptyTiles = (empty_tiles_percent * totalTiles) / 100;
        int grassTiles = totalTiles - emptyTiles;
        // Fill the required number of grass tiles
        while (grassTiles > 0) {
            int row = random.nextInt(y);
            int col = random.nextInt(x);
            if (game_field[row][col].equals("-")) {
                game_field[row][col] = "+";
                grassTiles--;
            }
        }

        // Random emplacement of Carnivores and Herbivores
        int index_h = 0, index_c = 0;
        int c_local=c;
        int h_local=h;
        while (c_local > 0 || h_local > 0) {
            if (c_local > 0) {
                int[] position = {random.nextInt(0, y), random.nextInt(0, x)};
                while (game_field[position[0]][position[1]].equals("H")){
                    position = new int[]{random.nextInt(0, y), random.nextInt(0, x)};
                }
                //carnivores[index_c] = new Carnivore(index_c,position, random);
                carnivores.add(new Carnivore(index_c,position, random));
                index_c++;
                game_field[position[0]][position[1]] = "C";
                c_local--;
            }
            if (h_local > 0) {
                int[] position = {random.nextInt(0, y), random.nextInt(0, x)};
                while (game_field[position[0]][position[1]].equals("C")){
                    position = new int[]{random.nextInt(0, y), random.nextInt(0, x)};
                }
                //herbivores[index_h] = new Herbivore(index_h,position, random);
                herbivores.add(new Herbivore(index_h,position, random));
                index_h++;
                game_field[position[0]][position[1]] = "H";
                h_local--;
            }
        }
    }

    public static void play(){
        Actions.eat_everybody();
        Actions.refresh();
        Actions.move_everybody();
        print();

    }

    public static void print(){
        int c_g=0;
        int c_e=0;
        for (int i = 0; i < game_field.length; i++) {
            for (int j = 0; j < game_field[i].length; j++) {
                System.out.print(game_field[i][j]+" ");
                if(game_field[i][j].equals("-")){
                    c_e++;
                }else if (game_field[i][j].equals("+")){
                    c_g++;
                }
            }
            System.out.println();
        }
        System.out.println("CARNIVORES LEFT: "+getCarnivores().size());
        System.out.println("HERBIVORES LEFT: "+getHerbivores().size());
        System.out.println("GRASS: "+c_g);
        System.out.println("EMPTY: "+c_e);
        System.out.println("MOVE ITERATION: "+Actions.getIteration());
        System.out.println("CARNIVORES DEAD: "+ (getC()-getCarnivores().size()));
        System.out.println("HERBIVORES DEAD: "+ (getH()-getHerbivores().size()));
        System.out.println("TO CONTINUE, ENTER 1; ELSE 0");
        String response = sc.next();
        if(response.equals("1")){
            play();
        }else if (response.equals("0")){
            // terminate
        }
        else{
            // terminate
        }
    }

    public static int getX() {
        return x;
    }

    public static int getY() {
        return y;
    }

    public static int getH() {
        return h;
    }

    public static int getC() {
        return c;
    }

    public static ArrayList<Herbivore> getHerbivores() {
        return herbivores;
    }

    public static ArrayList<Carnivore>  getCarnivores() {
        return carnivores;
    }

    public static Random getRandom() {
        return random;
    }

    public static Herbivore getHerbivoreByPosition(int[] position){
        //Herbivore[] herbivores = getHerbivores();
        ArrayList<Herbivore> herbivores = getHerbivores();
        for (Herbivore herbivore : herbivores) {
            if (Arrays.equals(herbivore.getPosition(), position))
                return herbivore;
        }
        return null;
    }
    public static Carnivore getCarnivoreByPosition(int[] position){
        //Carnivore[] carnivores = getCarnivores();
        ArrayList<Carnivore> carnivores = getCarnivores();
        for (Carnivore carnivore : carnivores) {
            if (Arrays.equals(carnivore.getPosition(), position))
                return carnivore;
        }
        return null;
    }

}
