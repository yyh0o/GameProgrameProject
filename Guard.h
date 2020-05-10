//
// Created by yyh0o on 2020/5/7.
//

#ifndef MINI_GAME_GUARD_H
#define MINI_GAME_GUARD_H

#include "Life.h"
#include "Astar.h"
#include <windows.h>

class Guard: public Life {
    int status{};
    Astar astar;

public:
    Guard(int x, int y, const char *map, int w, int h);
    void patrol();          // 巡视敌人
    void chaseEnemy(int des_x, int des_y);      // 追击敌人
    void changeStatus();    // 改变状态
};


#endif //MINI_GAME_GUARD_H
