//
// Created by yyh0o on 2020/5/4.
//

#ifndef MINI_GAME_CONTROLLER_H
#define MINI_GAME_CONTROLLER_H

#include "Renderer.h"
#include "Maze.h"
#include "config.h"


#define ESC 27
#define START_FLAG 1
#define ENTER 13
#define KV_UP 72
#define KV_RIGHT 77
#define KV_DOWN 80
#define KV_LEFT 75

#define READY 1
#define START 2
#define SELECT 3
#define EXIT 4

#define EASY 0
#define NORMAL 1
#define HARD 2

class Controller {
    Maze maze;
    Renderer renderer = Renderer(0, 0);
    int status;
    int difficulty;
    void chooseDifficulty();
public:
    explicit Controller(Renderer &r);
    void run();
    void test();
    void init();
    static int getControlFlag();
};


#endif //MINI_GAME_CONTROLLER_H
