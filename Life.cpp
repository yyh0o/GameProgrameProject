//
// Created by yyh0o on 2020/5/7.
//

#include "Life.h"

void Life::move(int x, int y) {
    position_x += x;
    position_y += y;
    cur_spirit.move(x, y);
}

bool Life::safeMove(int x, int y, GameMap &map) {
    if (map.checkAvailable(x, y)){
        move(x, y);
        return true;
    }
    else{
        return false;
    }
}

Life::Life(int x, int y, const Spirit& spirit) {
    position_x = x;
    position_y = y;
    cur_spirit = spirit;
}

Spirit* Life::getSpirit() {
    return &cur_spirit;
}

Life::Life(int x, int y, Animation animation) {
    position_x = x;
    position_y = y;
    cur_spirit = Spirit(x, y, animation);
}

Life::Life() = default;
