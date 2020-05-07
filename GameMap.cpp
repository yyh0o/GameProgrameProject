//
// Created by yyh0o on 2020/5/7.
//

#include "GameMap.h"

GameMap::GameMap(char *array, int w, int h) {
    map_array = array;
    width = w;
    height = h;
}

bool GameMap::checkInRange(int x, int y) const {
    return (x >= 0 && x < width && y >= 0 && y < height);
}

bool GameMap::checkAvailable(int x, int y) {
    return checkInRange(x,y) && map_array[y * height + x] != WALL;
}

char *GameMap::get_content() {
    return map_array;
}

void GameMap::get_size(int *pWidth, int *pHeight) const {
    *pWidth = this->width;
    *pHeight = this->height;
}

GameMap::GameMap() = default;
