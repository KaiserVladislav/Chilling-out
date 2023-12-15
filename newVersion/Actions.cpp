
#include "Actions.h"
#include "Game_field.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include <algorithm>
bool Actions::game_over_E = false;
bool Actions::game_over_H = false;
bool Actions::game_over_C = false;
int Actions::iteration = 0;

int Actions::getIteration() {
    return iteration;
}
bool Actions::isGameOverE() {
    return game_over_E;
}

bool Actions::isGameOverC() {
    return game_over_C;
}

bool Actions::isGameOverH() {
    return game_over_H;
}


void Actions::moveEverybody() {
    for (Herbivore hb : Game_field::getHerbivores()) {
        hb.move();
    }

    for (Carnivore cv : Game_field::getCarnivores()) {
        cv.move();
    }

    iteration++;
}

void Actions::eatEverybody() {
    for (Herbivore hb : Game_field::getHerbivores()) {
        hb.eat();
    }

    for (Carnivore cv : Game_field::getCarnivores()) {
        cv.eat();
    }
}

void Actions::refresh() {
    std::vector<Herbivore> herbivores = Game_field::getHerbivores();
    std::vector<Carnivore> carnivores = Game_field::getCarnivores();

    /*
    auto herbivorePredicate = [](const Herbivore& hb) { return !hb.isAliveStatus(); };
    herbivores.erase(std::remove_if(herbivores.begin(), herbivores.end(), herbivorePredicate),
                     herbivores.end());

    auto carnivorePredicate = [](const Carnivore& cv) { return !cv.isAliveStatus(); };
    carnivores.erase(std::remove_if(carnivores.begin(), carnivores.end(), carnivorePredicate),
                     carnivores.end());
    */

    if (herbivores.empty() && carnivores.empty()) {
        gameOverEverybody();
    }

    if (herbivores.empty()) {
        gameOverHerbivores();
    }

    if (carnivores.empty()) {
        gameOverCarnivores();
    }
}

void Actions::gameOverEverybody() {
    game_over_E = true;
}

void Actions::gameOverHerbivores() {
    game_over_H = true;
}

void Actions::gameOverCarnivores() {
    game_over_C = true;
}


