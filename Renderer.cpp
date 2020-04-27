//
// Created by yyh0o on 2020/4/27.
//

#include <iostream>
#include "Renderer.h"

void Renderer::changeFlag() {
        is_frame_1 = !is_frame_1;
}

Renderer::Renderer(int w, int h) {
    width = w;
    height = h;
    frame = std::vector<std::vector<char>>(h);
    for (int i = 0; i < h; ++i) {
        frame[i] = std::vector<char>(w);
    }
    is_frame_1 = true;
    consoleHandle1 = CreateConsoleScreenBuffer(
            GENERIC_WRITE,
            FILE_SHARE_WRITE,
            NULL,
            CONSOLE_TEXTMODE_BUFFER,
            NULL
            );
    consoleHandle2 = CreateConsoleScreenBuffer(
            GENERIC_WRITE,
            FILE_SHARE_WRITE,
            NULL,
            CONSOLE_TEXTMODE_BUFFER,
            NULL
    );
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle1, &cci);
    SetConsoleCursorInfo(consoleHandle2, &cci);
}

void Renderer::render() {
    HANDLE handle;
    char a;
    if (is_frame_1){
        handle = consoleHandle1;
#ifdef DEBUG
        a = '1';
#endif
    }
    else{
        handle = consoleHandle2;
#ifdef DEBUG
        a = '2';
#endif
    }
    for (int i = 0; i < height; ++i) {
            coord.Y = i;
        for (int j = 0; j < width; ++j) {
            coord.X = j;
            WriteConsoleOutputCharacterA(handle, &frame[i][j], 1, coord, &bytes);
        }
    }
#ifdef DEBUG
    WriteConsoleOutputCharacterA(handle, &a, 1, coord, &bytes);
#endif
    SetConsoleActiveScreenBuffer(handle);
}

void Renderer::drawArea(int left_x, int top_y, int right_x, int bottom_y, const std::vector<char>& info) {
    if (left_x < 0 || top_y < 0 || bottom_y >= height || right_x >= width){
        std::cerr << "out of range" << std::endl;
        return;
    }
    int w = left_x - right_x + 1;
    int h = bottom_y - top_y + 1;
    if (info.size() > w * h){
        std::cerr << "out of bond" << std::endl;
        return;
    }

    for (int i = 0; i < info.size(); ++i) {
        frame[top_y + i/h][left_x + i % w] = {info[i]};
    }
}

void Renderer::flash() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            frame[i][j] = ' ';
        }
    }
}

void Renderer::drawChar(int x, int y, char character) {
    if (x < 0 || x >= width || y < 0 || y > height){
        std::cerr << "out of range" << std::endl;
    }
    frame[x][y] = character;
}

void Renderer::fillArea(int left_x, int top_y, int right_x, int bottom_y, char filler) {
    if (left_x < 0 || top_y < 0 || bottom_y >= height || right_x >= width){
        std::cerr << "out of range" << std::endl;
        return;
    }
    for (int i = top_y; i <= bottom_y; ++i) {
        for (int j = left_x; j <= right_x; ++j) {
            frame[i][j] = filler;
        }
    }
}


