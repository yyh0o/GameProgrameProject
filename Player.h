//
// Created by yyh0o on 2020/5/7.
//

#ifndef MINI_GAME_PLAYER_H
#define MINI_GAME_PLAYER_H

#include "Life.h"

#define MAX_HEALTH 100

class Player: public Life {

public:
    Player();
    Player(int x, int y, const Spirit& spirit);
    Player(int x, int y);
    void attack();
    Player(int x, int y, Animation animation);
    void move(int x, int y);
    void getPos(int *x, int *y);
};


#endif //MINI_GAME_PLAYER_H
