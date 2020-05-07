//
// Created by yyh0o on 2020/5/7.
//

#ifndef MINI_GAME_GUARD_H
#define MINI_GAME_GUARD_H

#include "Life.h"

class Guard:Life {
int status;
public:
    void patrol();
    void chaseEnemy();
    void changeStatus();
};


#endif //MINI_GAME_GUARD_H
