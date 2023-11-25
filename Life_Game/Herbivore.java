package Main.Life_Game;

import java.util.ArrayList;
import java.util.Random;

public class Herbivore {
    private boolean is_alive;
    private int age;
    private int[] position;
    private int id;
    private int hunger=0;
    private static final int AGE_CAP=15;


    public Herbivore(int id, int[] position, Random random){
        this.age = random.nextInt(1,10);
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
                if ( (x+j)>=0&&(x+j)<Game_field.getX() && (y+i)>=0&&(y+i)<Game_field.getY()
                        && ((x+j)!=x || (y+i)!=y)  ){
                    // creating a pool of coordinates to move in
                    pool.add(new int[]{y+i, x+j});
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

        // TODO: EATING GRASS
        Game_field.game_field[old_position[0]][old_position[1]]="-";
        Game_field.game_field[new_position[0]][new_position[1]]="H";
        setPosition(new_position);
        //TODO: mb something about age?
        setAge(getAge()+1);
    }

    public void eat(){
        int[] position = getPosition();
        ArrayList<int[]> surroundings = getSurroundings();
        for(int[] coordinates:surroundings){
            if (Game_field.game_field[coordinates[0]][coordinates[1]].equals("+")){
                Game_field.game_field[coordinates[0]][coordinates[1]]="-";
                decreaseHunger();
                break;
            }
        }
    }

    public void die(){
        is_alive = false;
    }

    public int getId() {
        return id;
    }
    public int getAge() {
        return age;
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

    public void decreaseHunger() {
        hunger--;
    }

    public boolean is_alive() {
        return is_alive;
    }
}
