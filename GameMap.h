//
// Created by yyh0o on 2020/5/7.
//

#ifndef MINI_GAME_GAMEMAP_H
#define MINI_GAME_GAMEMAP_H

#include <fstream>

#define WALL '#'
#define AIR ' '
#define PLAYER '0'
#define GUARD '1'
#define START_POINT '2'
#define END_POINT '3'

class GameMap {
    char* map_array{};
    int width{};
    int height{};
public:
    GameMap();
    GameMap(char* array, int w, int height);
    bool checkInRange(int x, int y) const;
    bool checkAvailable(int x, int y);
    const char* get_content();
    void get_size(int *width, int *height) const;
    bool static loadMap(const char* file_name, GameMap *map);
    bool static writeMap(const char* file_name, GameMap &map);
    GameMap static getTestMap();
};


#endif //MINI_GAME_GAMEMAP_H
