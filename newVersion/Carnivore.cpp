#include "Carnivore.h"
#include "Game_field.h"
using namespace std;

int Carnivore::AGE_CAP;
int Carnivore::STARVATION_CAP;

Carnivore::Carnivore(int id, vector<int> position){
    this->age=0;
    this->position=position;
    this->id=id;
}

vector<vector<int>> Carnivore::getSurroundings() {
    vector<int> old_position = getPosition();
    int y = old_position[0];
    int x = old_position[1];
    vector<vector<int>> pool;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            // looking for bordering tiles
            if ( (x+j)>=0&&(x+j)<Game_field::getX() && (y+i)>=0&&(y+i)<Game_field::getY()
                    && ((x+j)!=x || (y+i)!=y)  ){
                if(!Game_field::game_field[y+i][x+j].compare("C")==0 && !Game_field::game_field[y+i][x+j].compare("X")==0){ // excludes overlapping same kin
                    // creating a pool of valid coordinates to move in
                    pool.push_back({y+i, x+j});
                }   
            }
        }
    return pool;
    }
}
void Carnivore::move() {
    vector<int> old_position = getPosition();
    vector<vector<int>>pool = getSurroundings();
    
    int randIndex= rand()%(pool.size());
    vector<int> new_position = pool[randIndex];

    //TODO: carnivores aint vegans man
    string previous_tile=getTileUnderneath();
    Game_field::game_field[old_position[0]][old_position[1]]=previous_tile; // to ensure carnivore does not consume grass
    setTileUnderneath(Game_field::game_field[new_position[0]][new_position[1]]);
    Game_field::game_field[new_position[0]][new_position[1]]="C";
    setPosition(new_position);

    aging();
    starving();
}

void Carnivore::eat() {
    vector<vector<int>> surroundings = getSurroundings();
        for(vector<int> coordinates:surroundings){
            if (Game_field::game_field[coordinates[0]][coordinates[1]].compare("H")==0){
                Game_field::getHerbivoreByPosition(coordinates).die(); // logically...
                decreaseHunger();
                break; // eating just once per turn
            }
        }
}

void Carnivore::die() {
    isAlive = false;
    vector<int> coordinates=getPosition();
    Game_field::game_field[coordinates[0]][coordinates[1]]="X";
}

void Carnivore::aging() {
    setAge(getAge()+1);
        if(getAge()==AGE_CAP){
            die();
        }
}

void Carnivore::starving() {
    hunger++;
        if (hunger==STARVATION_CAP){
            die();
        }
        //int chance_of_death = age-hunger;
}

int Carnivore::getId() {
    return id;
}

int Carnivore::getAge() {
    return age;
}

string Carnivore::getTileUnderneath() {
    return tileUnderneath;
}
void Carnivore::setTileUnderneath(string tileUnderneath) {
    this->tileUnderneath=tileUnderneath;
}

vector<int> Carnivore::getPosition(){
    return position;
}

void Carnivore::setPosition(vector<int> position) {
    this->position=position;
}

void Carnivore::setAge(int age) {
    this->age=age;
}

int Carnivore::getHunger() {
    return hunger;
}

void Carnivore::decreaseHunger() {
    hunger--;
}

bool Carnivore::isAliveStatus() {
    return isAlive;
}

void Carnivore::setAgeCap(int ageCap) {
    AGE_CAP = ageCap;
}

