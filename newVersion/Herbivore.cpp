#include "Herbivore.h"
#include "Game_field.h"
using namespace std;
int Herbivore::AGE_CAP;
int Herbivore::STARVATION_CAP;


Herbivore::Herbivore(int id, vector<int> position) {
    this->age=0;
    this->position=position;
    this->id=id;
}

vector<vector<int>> Herbivore::getSurroundings()  {
    vector<int> old_position = getPosition();
    int y = old_position[0];
    int x = old_position[1];
    vector<vector<int>> pool;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            // looking for bordering tiles
            if ( (x+j)>=0&&(x+j)<Game_field::getX() && (y+i)>=0&&(y+i)<Game_field::getY()
                    && ((x+j)!=x || (y+i)!=y)  ){
                if(!Game_field::game_field[y+i][x+j].compare("H")==0 && !Game_field::game_field[y+i][x+j].compare("X")==0){ // excludes overlapping same kin
                    // creating a pool of valid coordinates to move in
                    pool.push_back({y+i, x+j});
                }   
            }
        }
    return pool;
    }
}

void Herbivore::move() {
    vector<int> old_position = getPosition();
    vector<vector<int>>pool = getSurroundings();
    
    int randIndex= rand()%(pool.size());
    vector<int> new_position = pool[randIndex];

    
    string previous_tile=getTileUnderneath();
    Game_field::game_field[old_position[0]][old_position[1]]=previous_tile; 
    setTileUnderneath(Game_field::game_field[new_position[0]][new_position[1]]);
    Game_field::game_field[new_position[0]][new_position[1]]="H";
    setPosition(new_position);

    aging();
    starving();
}


void Herbivore::eat() {
    vector<vector<int>> surroundings = getSurroundings();
        for(vector<int> coordinates:surroundings){
            if (Game_field::game_field[coordinates[0]][coordinates[1]].compare("+")==0){
                Game_field::game_field[coordinates[0]][coordinates[1]]="-";
                decreaseHunger();
                break; // eating just once per turn
            }
        }
}

void Herbivore::die() {
    isAlive = false;
    vector<int> coordinates=getPosition();
    Game_field::game_field[coordinates[0]][coordinates[1]]="X";
}

void Herbivore::aging() {
    setAge(getAge()+1);
        if(getAge()==AGE_CAP){
            die();
        }
}

void Herbivore::starving() {
     hunger++;
        if (hunger==STARVATION_CAP){
            die();
        }
        //int chance_of_death = age-hunger;
}

int Herbivore::getId() {
    return id;
}

int Herbivore::getAge() {
    return age;
}

string Herbivore::getTileUnderneath() {
    return tileUnderneath;
}

void Herbivore::setTileUnderneath(string tileUnderneath) {
    this->tileUnderneath=tileUnderneath;
}

vector<int> Herbivore::getPosition() {
    return position;
}

void Herbivore::setPosition(vector<int> position) {
    this->position=position;
}

void Herbivore::setAge(int age) {
    this->age=age;
}

int Herbivore::getHunger() {
    return hunger;
}

void Herbivore::decreaseHunger() {
    hunger--;
}


bool Herbivore::isAliveStatus() {
    return isAlive;
}

void Herbivore::setAgeCap(int ageCap) {
    AGE_CAP = ageCap;
}
