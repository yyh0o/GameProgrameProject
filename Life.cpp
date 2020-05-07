//
// Created by yyh0o on 2020/5/7.
//

#include "Life.h"

void Life::move(int x, int y) {
    position_x += x;
    position_y += y;
}

bool Life::safeMove(int x, int y) {
    if (map.checkAvailable(x, y)){
        move(x, y);
        return true;
    }
    else{
        return false;
    }
}

Life::Life(int x, int y, const Spirit& spirit, const GameMap& map) {
    position_x = x;
    position_y = y;
    this->map = map;
    cur_spirit = spirit;
}

Life::Life() = default;
