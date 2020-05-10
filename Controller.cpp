//
// Created by yyh0o on 2020/5/4.
//

#include <conio.h>
#include "Controller.h"

void Controller::init() {
    HANDLE timer;
    HANDLE timerQueue;
    timerQueue = CreateTimerQueue();
    CreateTimerQueueTimer(
            &timer,
            timerQueue,
            (WAITORTIMERCALLBACK)Renderer::TimeProc,
            &renderer,
            0,
            ANIMATION_DELAY,
            0
    );
    CreateThread(NULL, 0, Renderer::renderer_update, &renderer, 0, NULL);
    CreateThread(NULL, 0, Renderer::renderer_display, &renderer, 0, NULL);
}

void Controller::test() {
//    char background[] = {
//        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
//        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
//    };
//    char background_1[] = {
//        '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
//        '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
//        '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
//        '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
//        '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
//        '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
//        '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'
//    };
//    char start_title[] = {
//          0 ,'#','#','#', 0 ,'#','#','#','#','#', 0 , 0 ,'#','#', 0 , 0 ,'#','#','#','#', 0 , 0 ,'#','#','#','#','#',
//         '#', 0 , 0 , 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0 ,'#', 0 , 0 ,'#', 0 , 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0 ,
//          0 ,'#','#', 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 ,'#','#','#','#', 0 , 0 ,'#','#','#', 0 , 0 , 0 , 0 ,'#', 0 , 0 ,
//          0 , 0 , 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0 ,'#', 0 , 0 ,'#', 0 ,'#', 0 , 0 , 0 , 0 ,'#', 0 , 0 ,
//         '#','#','#', 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0 ,'#', 0 , 0 ,'#', 0 , 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0
//    };
//    char exit_title[] = {
//        0 , 0 , 0 ,'#','#','#','#', 0 ,'#', 0 , 0 , 0 ,'#', 0 ,'#','#','#', 0 ,'#','#','#','#','#', 0 , 0 , 0 , 0 ,
//        0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 , 0 ,'#', 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 , 0 , 0 ,
//        0 , 0 , 0 ,'#','#','#', 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 , 0 , 0 ,
//        0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 , 0 ,'#', 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 , 0 , 0 ,
//        0 , 0 , 0 ,'#','#','#','#', 0 ,'#', 0 , 0 , 0 ,'#', 0 ,'#','#','#', 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 , 0 , 0
//    };
//
//    Animation background_animation(1, Spirit::generateFrame(background, 7, 27));
//    background_animation.push_back(Spirit::generateFrame(background_1, 7, 27));
//    Spirit start_title_background(true,4, 3, 27, 7, background_animation);
//    Spirit exit_title_background(false,4, 11, 27, 7, background_animation);
//    Animation start_animation(1, Spirit::generateFrame(start_title, 5, 27));
//    Animation exit_animation(1, Spirit::generateFrame(exit_title, 5, 27));
//    Spirit start_spirit(4,4,27,5,start_animation);
//    Spirit exit_spirit(4,12,27,5,exit_animation);
////    renderer.addSpirit(&start_title_background);
////    renderer.addSpirit(&exit_title_background);
////    renderer.addSpirit(&start_spirit);
////    renderer.addSpirit(&exit_spirit);
//    Animation testAnimation;
//    bool test = Spirit::loadAnimation("../resource/ready.txt", &testAnimation);
//    Spirit testSpirit(0, 0, 36, 1, testAnimation);
//    Player p(0,0);
////    Spirit playerSpirit = p.getSpirit();
////    renderer.addSpirit(playerSpirit);
////    renderer.addSpirit(testSpirit);
//    HANDLE timer;
//    HANDLE timerQueue;
//    timerQueue = CreateTimerQueue();
//    CreateTimerQueueTimer(
//            &timer,
//            timerQueue,
//            (WAITORTIMERCALLBACK)Renderer::TimeProc,
//            &renderer,
//            0,
//            ANIMATION_DELAY,
//            0
//    );
//    CreateThread(NULL, 0, Renderer::renderer_update, &renderer, 0, NULL);
//    CreateThread(NULL, 0, Renderer::renderer_display, &renderer, 0, NULL);
//    while(1){
//        if(_kbhit()){
//            int ch = _getch();
//            if (ch == 27){
//                break;
//            }
//            switch (ch){
//                case 'w':
//                    start_title_background.setVisible(true);
//                    exit_title_background.setVisible(false);
//                    break;
//                case 's':
//                    start_title_background.setVisible(false);
//                    exit_title_background.setVisible(true);
//                    break;
//            }
//        }
//    }
    Maze m(1, 21, 2, &renderer);
    m.update();
}

Controller::Controller(Renderer &r) {
    renderer = r;
    status = READY;
    maze = Maze();
    difficulty = 0;
}

void Controller::run() {
    HANDLE timer;
    HANDLE timerQueue;
    timerQueue = CreateTimerQueue();
    CreateTimerQueueTimer(
            &timer,
            timerQueue,
            (WAITORTIMERCALLBACK)Renderer::TimeProc,
            &renderer,
            0,
            ANIMATION_DELAY,
            0
    );
    CreateThread(NULL, 0, Renderer::renderer_update, &renderer, 0, NULL);
    CreateThread(NULL, 0, Renderer::renderer_display, &renderer, 0, NULL);

    Animation readyAnimation = Spirit::loadAnimation("../resource/ready.txt");;
    Animation loadingAnimation = Spirit::loadAnimation("../resource/loading.txt");
    Animation chooseDifficulty = Spirit::loadAnimation("../resource/choose_difficulty.txt");
    Animation selectBar = Spirit::loadAnimation("../resource/select_bar.txt");


    Spirit selectBarSpirit(40, 15, selectBar);
    Spirit chooseDifficultySpirit(53, 15, chooseDifficulty);
    Spirit readySpirit(40, 15,readyAnimation);
    Spirit loadingSpirit(40, 15, loadingAnimation);
    std::vector<Spirit *> readyScene(0);
    std::vector<Spirit *> loadingScene(0);
    std::vector<Spirit *> difficultSelectScene(0);
    std::vector<Spirit *> gameScene(0);
    difficultSelectScene.push_back(&selectBarSpirit);
    difficultSelectScene.push_back(&chooseDifficultySpirit);
    readyScene.push_back(&readySpirit);
    loadingScene.push_back(&loadingSpirit);
    int controlFlag;
    do {
        controlFlag = getControlFlag();
        switch (status) {
            case READY:
                renderer.changeScene(readyScene);
                while (controlFlag != ENTER){
                    controlFlag = getControlFlag();
                    if (controlFlag == ESC)
                        break;
                }
                renderer.changeScene(difficultSelectScene);
                int tmpFlag;
                do {
                    tmpFlag = getControlFlag();
                    switch (tmpFlag) {
                        case KV_UP:
                            if (difficulty != 0){
                                selectBarSpirit.move(0, -1);
                                difficulty--;
                            }
                            break;
                        case KV_DOWN:
                            if (difficulty != 2){
                                selectBarSpirit.move(0, 1);
                                difficulty++;
                            }
                            break;
                        case ENTER:
                            status = START;
                            tmpFlag = ESC;
                            break;
                    }
                }while(tmpFlag != ESC);
                break;
            case START:
                renderer.changeScene(loadingScene);
                // todo load game
                maze = Maze(difficulty, ((difficulty+1)*10+1), difficulty+1, &renderer);
                maze.run();
                status = READY;
                break;
            default:
                break;
        }
    }while(controlFlag != ESC);
}

int Controller::getControlFlag() {
    if (_kbhit()){
        int c = _getch();
        return c;
    }
    return 0;
}

void Controller::chooseDifficulty() {
    int c = getControlFlag();
    if (c == KV_UP){
        difficulty -= 1;
        if (difficulty < 0){
            difficulty += 3;
        }
    }
    if (c == KV_DOWN) {
        difficulty += 1;
        if (difficulty > 2) {
            difficulty -= 3;
        }
    }
}
