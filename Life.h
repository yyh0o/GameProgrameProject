//
// Created by yyh0o on 2020/5/7.
//

#ifndef MINI_GAME_LIFE_H
#define MINI_GAME_LIFE_H

#include "Spirit.h"
#include "GameMap.h"

class Life {
protected:
    Spirit cur_spirit;
    int position_x{};
    int position_y{};
    int health{};
    bool isAlive{};
public:
    Life(int x, int y, const Spirit& spirit);
    Life();

    void move(int x, int y);
    bool safeMove(int x, int y, GameMap &map);

    Spirit getSpirit();
};


#endif //MINI_GAME_LIFE_H
