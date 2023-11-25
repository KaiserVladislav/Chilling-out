package Main.Life_Game;

import java.util.ArrayList;
import java.util.Arrays;

public class Actions {
    private static boolean trigger=false;

    private static int iteration=0;
    public static int getIteration() {
        return iteration;
    }

    public static void move_everybody() {
        for (Herbivore hb:
             Game_field.getHerbivores()) {
            System.out.println(Arrays.toString(hb.getPosition()));
            hb.move();
            System.out.println(Arrays.toString(hb.getPosition()));
        }
        for (Carnivore cv:
             Game_field.getCarnivores()) {
            System.out.println(Arrays.toString(cv.getPosition()));
            cv.move();
            System.out.println(Arrays.toString(cv.getPosition()));
        }
        iteration++; // id esta one year passed?
    }

    public static void eat_everybody(){
        ArrayList<Herbivore> herbivores = Game_field.getHerbivores();
        ArrayList<Carnivore> carnivores = Game_field.getCarnivores();

        for (Herbivore hb:
                herbivores) {
            hb.eat();
        }
        for(Carnivore cv:
                carnivores){
            cv.eat();
        }
    }

    public static void refresh(){
        ArrayList<Herbivore> herbivores = Game_field.getHerbivores();
        ArrayList<Carnivore> carnivores = Game_field.getCarnivores();

        if (herbivores.size()>=1){
            herbivores.removeIf(hb -> !hb.is_alive()); // Collections.removeIf!!!
        }
        if (carnivores.size()>=1){
            carnivores.removeIf(cv -> !cv.is_alive());
        }
    }

}

