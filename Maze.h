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
    Player player;  // 玩家
    std::vector<Guard> guards;  // 守卫
    GameMap map;    // 地图
    int number{};   // 迷宫编号
    int height{};   // 高度
    int width{};    // 宽度
    int guard_amount{}; // 守卫数量
    void setPlayer();   // 放置一个玩家
    void setGuards();   // 放置守卫
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
