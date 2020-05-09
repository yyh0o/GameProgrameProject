//
// Created by yyh0o on 2020/5/7.
//

#ifndef MINI_GAME_GUARD_H
#define MINI_GAME_GUARD_H

#include "Life.h"

class Guard: public Life {
int status;
public:
    void patrol();          // 巡视敌人
    void chaseEnemy();      // 追击敌人
    void changeStatus();    // 改变状态
};


#endif //MINI_GAME_GUARD_H
