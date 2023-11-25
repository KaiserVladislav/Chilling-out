package Main.Life_Game;

import java.util.Scanner;

public class Main {// TODO: SETTING UP
    private static int[] choose_preset(){
        int[][] presets = new int[3][5];
        presets[0]=new int[]{100, 100, 10, 20, 70};
        presets[1]=new int[]{250, 250, 30, 40, 70};
        presets[2]=new int[]{500, 500, 50, 60, 70};
        System.out.println("Select game preset:");
        for (int i = 0; i < presets.length; i++) {
            System.out.printf("Preset %d: \nX: %d\nY: %d\nTotal carnivores: %d\nTotal herbivores: %d\nPercentage of empty tiles: %d%s",i+1,presets[i][0],presets[i][1],presets[i][2],presets[i][3],presets[i][4],"%");
            System.out.println("\n");
        }
        System.out.print("Your choice: ");
        Scanner scanner = new Scanner(System.in);
        String response = scanner.next();
        if (response.equals("1")){
            return presets[0];
        }else if(response.equals("2")){
            return presets[1];
        }
        else if (response.equals("3")){
            return presets[2];
        }else{
            System.out.println("Invalid input. Restarting program...");
            choose_preset();
        }
        return new int[0];
    }

    public static void main(String[] args) {
        //int[] preset = choose_preset();
        int[] test = new int[]{20,20,5,5,70};
        Game_field gf = new Game_field(test);
        // TODO: GAME PROCESS
        Game_field.print();
        //Game_field.play();
    }

}
