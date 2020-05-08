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

const char *GameMap::get_content() {
    return map_array;
}

void GameMap::get_size(int *pWidth, int *pHeight) const {
    *pWidth = this->width;
    *pHeight = this->height;
}

bool GameMap::loadMap(const char *file_name, GameMap *map){
    std::ifstream in(file_name);
    if (in.is_open()){
        in >> map->height >> map->width;
        for (int i = 0; i < map->height; ++i) {
            for (int j = 0; j < map->width; ++j) {
                in >> map->map_array[i*map->height+j];
            }
        }
        in.close();
        return true;
    }
    return false;
}

bool GameMap::writeMap(const char *file_name, GameMap &map) {
    std::ofstream out(file_name);
    if (out.is_open()){
        out << map.height << ' ' << map.width << std::endl;
        for (int i = 0; i < map.height; ++i) {
            for (int j = 0; j < map.width; ++j) {
                out << map.map_array[i*map.height + j];
            }
            out << std::endl;
        }
        out.close();
        return true;
    }
    return false;
}

GameMap::GameMap() = default;
