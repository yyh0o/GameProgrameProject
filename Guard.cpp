//
// Created by yyh0o on 2020/5/7.
//

#include "Guard.h"

Guard::Guard(int x, int y, const char *map, int w, int h) {
    astar = Astar(map, w, h, {0,0}, {0,0});
    position_x = x;
    position_y = y;
    Animation guardAnimation = Spirit::loadAnimation("../resource/Guard.txt");
    cur_spirit = Spirit(x, y, guardAnimation);
}

void Guard::chaseEnemy(int des_x, int des_y) {
    COORD start = {static_cast<SHORT>(position_x), static_cast<SHORT>(position_y)};
    COORD end = {static_cast<SHORT>(des_x), static_cast<SHORT>(des_y)};
    COORD nextStep = astar.getNextStep(start, end);
//    auto tmpList = astar.get_path(start, end);
//    for(auto item : tmpList){
//        std::cout << "(" << item->x << ", " << item->y << ")" << std::endl;
//    }
    position_x = nextStep.X;
    position_y = nextStep.Y;
    cur_spirit.setPos(position_x, position_y);
}

void Guard::getPos(int *x, int *y) {
    *x = position_x;
    *y = position_y;
}
