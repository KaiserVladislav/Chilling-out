package Main.Life_Game;

import java.util.ArrayList;
import java.util.Random;

public class Herbivore {
    private boolean is_alive;
    private int age;
    private int[] position;
    private int id;
    private int hunger=0;
    private static int AGE_CAP=5;
    private static int STARVATION_CAP;
    private String tile_underneath="-";


    public Herbivore(int id, int[] position, Random random){
        //this.age = random.nextInt(1,10);
        this.age=0;
        this.position = position;
        this.id=id;
        is_alive=true;
    }

    public ArrayList<int[]> getSurroundings(){
        int[] old_position = getPosition();
        int y = old_position[0];
        int x = old_position[1];
        ArrayList<int[]> pool = new ArrayList<>();

        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                // looking for bordering tiles
                if ( (x+j)>=0&&(x+j)<Game_field.getX() && (y+i)>=0&&(y+i)<Game_field.getY()
                        && ((x+j)!=x || (y+i)!=y)  ){
                    if(!Game_field.game_field[y+i][x+j].equals("H") && !Game_field.game_field[y+i][x+j].equals("X") ){// excludes overlapping same kin
                        // creating a pool of valid coordinates to move in
                        pool.add(new int[]{y+i, x+j});
                    }
                }
            }
        }
        return pool;
    }

    public void move(){
        int[] old_position = getPosition();
        ArrayList<int[]> pool = getSurroundings();
        int randIndex=Game_field.getRandom().nextInt(0, pool.size());
        int[] new_position = pool.get(randIndex);

        //
        String previous_tile=getTile_underneath();
        Game_field.game_field[old_position[0]][old_position[1]]=previous_tile;
        setTile_underneath(Game_field.game_field[new_position[0]][new_position[1]]);
        Game_field.game_field[new_position[0]][new_position[1]]="H";
        setPosition(new_position);

        //starving();
        aging();
    }

    public void eat(){
        ArrayList<int[]> surroundings = getSurroundings();
        for(int[] coordinates:surroundings){
            if (Game_field.game_field[coordinates[0]][coordinates[1]].equals("+")){
                Game_field.game_field[coordinates[0]][coordinates[1]]="-";
                decreaseHunger();
                break; // eating just once per turn
            }
        }
    }

    public void die(){
        is_alive = false;
        int[]coordinates=getPosition();
        Game_field.game_field[coordinates[0]][coordinates[1]]="X";
    }
    public void aging(){
        setAge(getAge()+1);
        if(getAge()>=AGE_CAP){
            die();
        }
    }
    public void starving(){
        hunger++;
        if (hunger==STARVATION_CAP){
            die();
        }
        int chance_of_death = age-hunger;

    }

    public int getId() {
        return id;
    }
    public int getAge() {
        return age;
    }

    public String getTile_underneath() {
        return tile_underneath;
    }

    public void setTile_underneath(String tile_underneath) {
        this.tile_underneath = tile_underneath;
    }

    public int[] getPosition() {
        return position;
    }

    public void setPosition(int[] position) {
        this.position = position;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getHunger() {
        return hunger;
    }

    public void increaseHunger() {
        hunger++;
    }
    public void decreaseHunger() {
        hunger--;
    }

    public boolean is_alive() {
        return is_alive;
    }
    public static void setAgeCap(int ageCap) {
        AGE_CAP = ageCap;
    }
}
