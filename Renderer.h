//
// Created by yyh0o on 2020/4/27.
//

#ifndef MINI_GAME_RENDERER_H
#define MINI_GAME_RENDERER_H
#include <iostream>
#include <vector>
#include <windows.h>

typedef struct{
    char character;
    int color;
} UNIT;

typedef std::vector<std::vector<char>> Frame;

class Renderer {
    int width;
    int height;
    Frame frame;
    bool is_frame_1;
    int sleep_time = 17;
    HANDLE consoleHandle1, consoleHandle2;
    COORD coord = {0, 0};
    DWORD bytes = 0;
public:
    Renderer(int w, int h);
    void render();
    void drawArea(int left_x, int top_y, int right_x, int bottom_y, const std::vector<char>& info);
    void fillArea(int left_x, int top_y, int right_x, int bottom_y, char filler);
    void flash();
    void changeFlag();
    void drawChar(int x, int y, char character);
};


#endif //MINI_GAME_RENDERER_H
