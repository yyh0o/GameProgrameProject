//
// Created by yyh0o on 2020/5/7.
//

#ifndef MINI_GAME_GAMEMAP_H
#define MINI_GAME_GAMEMAP_H

#define WALL '#'
#define AIR ' '

class GameMap {
    char* map_array{};
    int width{};
    int height{};
public:
    GameMap();
    GameMap(char* array, int w, int height);
    bool checkInRange(int x, int y) const;
    bool checkAvailable(int x, int y);
    char* get_content();
    void get_size(int *width, int *height) const;
};


#endif //MINI_GAME_GAMEMAP_H
