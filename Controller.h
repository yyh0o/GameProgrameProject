//
// Created by yyh0o on 2020/5/4.
//

#ifndef MINI_GAME_CONTROLLER_H
#define MINI_GAME_CONTROLLER_H

#include "Renderer.h"
#include "config.h"

class Controller {
Renderer renderer = Renderer(0, 0);

public:
    Controller(Renderer &r);
    void run();
    void test();
    void init();
};


#endif //MINI_GAME_CONTROLLER_H
