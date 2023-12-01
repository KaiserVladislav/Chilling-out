package Main.Life_Game;

import java.util.ArrayList;

public class Actions {
    private static boolean game_over_E=false; // trigger to shut down the game
    private static boolean game_over_H=false; // trigger to shut down the game
    private static boolean game_over_C=false; // trigger to shut down the game
    private static int iteration=0; // basically time counter

    public static int getIteration() {
        return iteration;
    }
    public static void move_everybody() {
        for (Herbivore hb:
             Game_field.getHerbivores()) {
            hb.move();
        }
        for (Carnivore cv:
             Game_field.getCarnivores()) {
            cv.move();
        }
        iteration++; //one month mb
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

        if (herbivores.size()==0 && carnivores.size()==0){
            game_over_Everybody();
        }
        if(herbivores.size()==0){
            game_over_Herbivores();
        }

        if(carnivores.size()==0){
            game_over_Carnivores();
        }
    }

    public static void game_over_Everybody(){
        game_over_E=true;
    }
    public static void game_over_Herbivores(){
        game_over_H=true;
    }
    public static void game_over_Carnivores(){
        game_over_C=true;
    }

    public static boolean isGame_over_E() {
        return game_over_E;
    }

    public static boolean isGame_over_C() {
        return game_over_C;
    }

    public static boolean isGame_over_H() {
        return game_over_H;
    }
}

