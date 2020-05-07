//
// Created by yyh0o on 2020/5/4.
//

#include <conio.h>
#include "Controller.h"

void Controller::init() {
}

void Controller::test() {
    char background[] = {
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
    };
    char background_1[] = {
        '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
        '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
        '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
        '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
        '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
        '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',
        '_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'
    };
    char start_title[] = {
          0 ,'#','#','#', 0 ,'#','#','#','#','#', 0 , 0 ,'#','#', 0 , 0 ,'#','#','#','#', 0 , 0 ,'#','#','#','#','#',
         '#', 0 , 0 , 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0 ,'#', 0 , 0 ,'#', 0 , 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0 ,
          0 ,'#','#', 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 ,'#','#','#','#', 0 , 0 ,'#','#','#', 0 , 0 , 0 , 0 ,'#', 0 , 0 ,
          0 , 0 , 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0 ,'#', 0 , 0 ,'#', 0 ,'#', 0 , 0 , 0 , 0 ,'#', 0 , 0 ,
         '#','#','#', 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0 ,'#', 0 , 0 ,'#', 0 , 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0
    };
    char exit_title[] = {
        0 , 0 , 0 ,'#','#','#','#', 0 ,'#', 0 , 0 , 0 ,'#', 0 ,'#','#','#', 0 ,'#','#','#','#','#', 0 , 0 , 0 , 0 ,
        0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 , 0 ,'#', 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 , 0 , 0 ,
        0 , 0 , 0 ,'#','#','#', 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 , 0 , 0 ,
        0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 , 0 ,'#', 0 ,'#', 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 , 0 , 0 ,
        0 , 0 , 0 ,'#','#','#','#', 0 ,'#', 0 , 0 , 0 ,'#', 0 ,'#','#','#', 0 , 0 , 0 ,'#', 0 , 0 , 0 , 0 , 0 , 0
    };

    Animation background_animation(1, Spirit::generateFrame(background, 7, 27));
    background_animation.push_back(Spirit::generateFrame(background_1, 7, 27));
    Spirit start_title_background(true,4, 3, 27, 7, background_animation);
    Spirit exit_title_background(false,4, 11, 27, 7, background_animation);
    Animation start_animation(1, Spirit::generateFrame(start_title, 5, 27));
    Animation exit_animation(1, Spirit::generateFrame(exit_title, 5, 27));
    Spirit start_spirit(4,4,27,5,start_animation);
    Spirit exit_spirit(4,12,27,5,exit_animation);
    renderer.addSpirit(&start_title_background);
    renderer.addSpirit(&exit_title_background);
    renderer.addSpirit(&start_spirit);
    renderer.addSpirit(&exit_spirit);
//    Animation testAnimation;
//    bool test = Spirit::loadAnimation("../resource/test.txt", &testAnimation);
//    Spirit testSpirit(0, 0, 10, 5, testAnimation);
//    renderer.addSpirit(&testSpirit);
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
    while(1){
        if(_kbhit()){
            int ch = _getch();
            if (ch == 27){
                break;
            }
            switch (ch){
                case 'w':
                    start_title_background.setVisible(true);
                    exit_title_background.setVisible(false);
                    break;
                case 's':
                    start_title_background.setVisible(false);
                    exit_title_background.setVisible(true);
                    break;
            }
        }
    }
}

Controller::Controller(Renderer &r) {
    renderer = r;
}

void Controller::run() {
    int controlFlag;
    init();
    do{
        controlFlag = getControlFlag();
        switch (controlFlag) {
            case START_FLAG:
                break;
            default:
                break;
        }
    }while (controlFlag != EXIT_FLAG);
}

int Controller::getControlFlag() {
    return 0;
}
