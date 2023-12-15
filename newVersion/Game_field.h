#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Herbivore.h"
#include "Carnivore.h"

using namespace std;

class Game_field{
private: static int x,y,c,h,empty_tiles_percent;
private: static vector<Carnivore> carnivores;
private: static vector<Herbivore> herbivores;
public: static vector<vector<string>> game_field;

public: Game_field(vector<int> preset);
public: Game_field(vector<vector<vector<int>>> preset);
public: static void generateField(int x, int y, int empty_tiles_percent);
public: static void generateField(int x, int y, int empty_tiles_percent, vector<Carnivore> carnivores, vector<Herbivore> herbivores);

public: static void print();
public: static void play();
public: static int getX();
public: static int getY();
public: static int getC();
public: static int getH();
public: static string getTile(vector<int> position);

public: static vector<Carnivore> getCarnivores();
public: static vector<Herbivore> getHerbivores();
public: static Carnivore getCarnivoreByPosition(vector<int> position);
public: static Herbivore getHerbivoreByPosition(vector<int> position);


};

#endif