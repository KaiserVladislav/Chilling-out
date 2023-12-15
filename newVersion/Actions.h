// Actions.h
#ifndef ACTIONS_H
#define ACTIONS_H

#include <vector>
#include "Herbivore.h"
#include "Carnivore.h"

class Actions {
private:
    static bool game_over_E;
    static bool game_over_H;
    static bool game_over_C;
    static int iteration;

public:
    static int getIteration();

    static void moveEverybody();

    static void eatEverybody();

    static void refresh();

    static void gameOverEverybody();

    static void gameOverHerbivores();

    static void gameOverCarnivores();

    static bool isGameOverE();

    static bool isGameOverC();

    static bool isGameOverH();
};

#endif // ACTIONS_H
