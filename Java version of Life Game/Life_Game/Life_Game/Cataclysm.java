package Main.Life_Game;

import java.util.ArrayList;

public class Cataclysm {
    private static final int chance_M=1;
    private static final int chance_A=2;
    private static final int chance_D=3;
    private static final int chance_E=4;

    public static void Meteorite_strike(){
        ArrayList<Carnivore> carnivores = Game_field.getCarnivores();
        ArrayList<Herbivore> herbivores = Game_field.getHerbivores();
        // everyone dies
        for (Carnivore cv:
             carnivores) {
            cv.die();
        };
        for (Herbivore hb:
                herbivores) {
            hb.die();
        };
        System.out.println("PHU BAM! EVERYONE IS DEAD NOW!");
    }
    public static void Acid_rains(){
        // half randomly dies
    }
    public static void Deadly_blizzard(){
        // all grass dies
    }
    public static void Earthquake(){
        // quarter randomly dies
    }


}
