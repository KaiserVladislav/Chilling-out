package Main.Life_Game;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Game_field {
    // basic declaration;
    private static int x,y,c,h, empty_tiles_percent;
    private static ArrayList<Herbivore> herbivores;
    private static ArrayList<Carnivore> carnivores;
            // just static for better mobility and comfortability of coding (a bit against oop but irrelevant)
            static String[][] game_field;
            // general random to avoid exception with different randoms
            static Random random = new Random();
    private static Scanner sc = new Scanner(System.in);

    public Game_field(int[] preset){
        x =preset[0];
        y =preset[1];
        c =preset[2];
        h =preset[3];
        empty_tiles_percent =preset[4];
        herbivores=new ArrayList<>();
        carnivores=new ArrayList<>();
        generate_field(x,y, empty_tiles_percent);
    }

    public Game_field(ArrayList<ArrayList<int[]>> preset){
        int[] main_settings  =  preset.get(0).get(0);
        x =main_settings[0];
        y =main_settings[1];
        c =main_settings[2];
        h =main_settings[3];
        empty_tiles_percent =main_settings[4];
        herbivores=new ArrayList<>();
        carnivores=new ArrayList<>();

        Carnivore.setAgeCap(main_settings[5]);
        Herbivore.setAgeCap(main_settings[6]);

        ArrayList<int[]> positions = preset.get(1);
        if (preset.get(1).size()==0){
            generate_field(x,y, empty_tiles_percent);
        }
        else{
            for (int i = 0; i < c; i++) { //carnivores positions
                carnivores.add(new Carnivore(i,positions.get(i),random));
            }
            for (int i = c; i < positions.size(); i++) { //herbivores positions
                herbivores.add(new Herbivore(i,positions.get(i),random));
            }
            generate_field(x,y, empty_tiles_percent,carnivores,herbivores);
        }

    }

    public static void generate_field(int x, int y, int empty_tiles_percent) {
        game_field = new String[y][x];

        for (int i = 0; i < y; i++) {
            Arrays.fill(game_field[i], "-");
        }
        // Calculate the number of grass tiles based on empty_tiles_percent
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
    public static void generate_field(int x, int y, int empty_tiles_percent, ArrayList<Carnivore> carnivores, ArrayList<Herbivore> herbivores) {
        game_field = new String[y][x];

        for (int i = 0; i < y; i++) {
            Arrays.fill(game_field[i], "-");
        }
        // Calculate the number of grass tiles based on empty_tiles_percent
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

        // Emplacement of Carnivores and Herbivores
        for (Carnivore cv: carnivores){
            int[] l_position = cv.getPosition();
            game_field[l_position[0]][l_position[1]]="C";
        }
        for(Herbivore hb: herbivores){
            int[] l_position = hb.getPosition();
            game_field[l_position[0]][l_position[1]]="H";
        }

    }


    public static void play(){
        Actions.eat_everybody();
        Actions.refresh();
        Actions.move_everybody();
        Actions.refresh();
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

        if(Actions.isGame_over_E()){
            System.out.println("The game is over. Everybody is dead!");
            System.exit(0);
        }
        else if(Actions.isGame_over_C()){
            System.out.println("The game is over. All carnivores are dead!");
            System.exit(0);
        }
        else if(Actions.isGame_over_H()){
            System.out.println("The game is over. All herbivores are dead!");
            System.exit(0);
        }

            // looping the game process
            System.out.println("TO CONTINUE, ENTER 1; ELSE 0");
            String response = sc.next();
            if(response.equals("1")){
                play();
                // forced game shutdown
            }else if (response.equals("0")){
                System.exit(0);
            }


    }

    // GETTERS AND SETTERS

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

    public static String getTile(int[] position){
        return Game_field.game_field[position[0]][position[1]];
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
