#ifndef HERBIVORE_H
#define HERBIVORE_H

#include <vector>
#include <array>
#include <string>
#include "Game_field.h"
using namespace std;

//class Game_field

class Herbivore {
private:
    bool isAlive;
    int age;
    vector<int> position;
    int id;
    int hunger;
    static int AGE_CAP;
    static int STARVATION_CAP;
    string tileUnderneath;

public:
    Herbivore(int id, vector<int> position);

    vector<vector<int>> getSurroundings();

    void move();

    void eat();

    void die();

    void aging();

    void starving();

    int getId();

    int getAge();

    string getTileUnderneath();

    void setTileUnderneath(string tileUnderneath);

    vector<int> getPosition();

    void setPosition(vector<int> position);

    void setAge(int age);

    int getHunger();

    void increaseHunger();

    void decreaseHunger();

    bool isAliveStatus();

    static void setAgeCap(int ageCap);
};

#endif // HERBIVORE_H
