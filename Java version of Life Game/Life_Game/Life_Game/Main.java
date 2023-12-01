package Main.Life_Game;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // TODO: SETTING UP
    // first type of customization - simplistic
    private static int[] choose_preset(){
        int[][] presets = new int[3][5];
        presets[0]=new int[]{50, 50, 10, 20, 30};
        presets[1]=new int[]{100, 100, 30, 40, 30};
        presets[2]=new int[]{200, 200, 50, 60, 30};
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
    // second type of customization - sophisticated
    public static ArrayList<int[]> get_customized_positions(int amount_of_animals, int id){ // id=0 is carnivore; =1 - herbivore
        ArrayList<int[]> positions =  new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        for (int i = 1; i <= amount_of_animals; i++) {
            int[] local=new int[2];
            if(id==0){
                System.out.printf("Carnivore no. %d\n",i);
            }else{
                System.out.printf("Herbivore no. %d\n",i);
            }

            System.out.print("X: ");
            local[1]=scanner.nextInt();
            System.out.print("Y: ");
            local[0]=scanner.nextInt();
            positions.add(local);
        }
        return positions;
    }
    private static ArrayList<ArrayList<int[]>> fully_customized_preset(){ //
        System.out.println("Welcome to the Game of Life!\nYou've chosen to edit starting game preset.");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Field parameters:");
        int x,y,grass_percentage;
        System.out.print("X: " );
        x=scanner.nextInt();
        System.out.print("Y: " );
        y=scanner.nextInt();
        System.out.print("Empty tiles' percentage: ");
        grass_percentage=scanner.nextInt();

        scanner.nextLine();

        int c,h,c_age_cap,h_age_cap;
        System.out.println("Animals' parameters:");
        System.out.print("Amount of carnivores: ");
        c=scanner.nextInt();
        System.out.print("Amount of herbivores: ");
        h=scanner.nextInt();

        System.out.print("Max age of carnivore: ");
        c_age_cap=scanner.nextInt();
        System.out.print("Max age of herbivore: ");
        h_age_cap=scanner.nextInt();

        scanner.nextLine();

        ArrayList<int[]> main_preset = new ArrayList<>();
        // weird structure to achieve array compatibility
        main_preset.add(new int[]{x,y,c,h,grass_percentage,c_age_cap,h_age_cap});
        // final result in form of [[[]]] matrix
        ArrayList<ArrayList<int[]>> result = new ArrayList<>();
        result.add(main_preset);

        System.out.println("Do you want to manually place animals?");
        String response;
        response=scanner.nextLine();
        System.out.println(response);
        ArrayList<int[]> positions = new ArrayList<>();
        if(response.equals("Yes") || response.equals("yes")|| response.equals("YES")){
            ArrayList<int[]> positions_c = get_customized_positions(c, 0);
            ArrayList<int[]> positions_h =  get_customized_positions(h, 1);
            // first we add carn positions then herb
            positions.addAll(positions_c);
            positions.addAll(positions_h);
        }
        result.add(positions);
        System.out.println("Customization process has been completed.");
        return result;
    }

    public static void main(String[] args) {
        //int[] preset = choose_preset();
        int[] test = new int[]{5,5,2,2,10};
        //Game_field gf = new Game_field(test);

        //ArrayList<ArrayList<int[]>> preset = fully_customized_preset();
        Game_field gf = new Game_field(test);

        // TODO: GAME PROCESS
        Game_field.print();

    }

}
