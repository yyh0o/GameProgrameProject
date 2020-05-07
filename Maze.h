//
// Created by yyh0o on 2020/5/7.
//

#ifndef MINI_GAME_MAZE_H
#define MINI_GAME_MAZE_H

#include <vector>
#include "GameMap.h"
#include "Player.h"
#include "Guard.h"

class Maze {
    Player player;
    std::vector<Guard> guards;
    GameMap map;
    int number{};
    int height{};
    int width{};
    int guard_amount{};
    void setPlayer();
    void setGuards();
public:
    Maze();
    Maze(int n, int h, int w, int guard_amount){
        this->guard_amount = guard_amount;
        number = n;
        height = h;
        width = w;
        setGuards();
        setPlayer();
    }

};


#endif //MINI_GAME_MAZE_H
