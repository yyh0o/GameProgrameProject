#include <iostream>
#include <conio.h>
#include "Renderer.h"
#include "windows.h"
#include "Spirit.h"


//typedef struct {
//    int x;
//    int y;
//    char c;
//    Renderer &renderer;
//} Spirit;

//DWORD WINAPI animation(LPVOID lpParameter){
//    Spirit *me = (Spirit*)lpParameter;
//    while (1){
//        me->renderer.drawChar(me->x, me->y, 'o');
//        me->renderer.changeFlag();
//        Sleep(300);
//        me->renderer.drawChar(me->x, me->y, 'O');
//        me->renderer.changeFlag();
//        Sleep(300);
//    }
//}

DWORD WINAPI renderer_update(LPVOID lpParameter){
//    std::cout << "in" << std::endl;
    Renderer *renderer = nullptr;
    if(lpParameter){
        renderer = (Renderer *)lpParameter;
        while(TRUE){
//            std::cout << (*renderer->frame)[2][2] << std::endl;
            renderer->update();
            WaitForMultipleObjects(1, renderer->getUpdateEvent(), FALSE, INFINITE);
        }
    }
    return 0;
}
DWORD WINAPI renderer_display(LPVOID lpParameter){
    Renderer *renderer = nullptr;
    if(lpParameter){
        renderer = (Renderer *)lpParameter;
        renderer->display();
    }
    return 0;
}

VOID CALLBACK TimeProc(PVOID lpParameter, BOOLEAN TimerOrWaitFired){
    Renderer *renderer = nullptr;
//    std::cout << "timer" << std::endl;
    if(lpParameter){
        renderer = (Renderer *)lpParameter;
        renderer->timeBat();
    }
}

int main() {
    Renderer renderer(25, 25);
    std::vector<Frame *> frame_list = std::vector<Frame *>(0);
    frame_list.push_back(Spirit::getFrame('a'));
    frame_list.push_back(Spirit::getFrame('b'));
    frame_list.push_back(Spirit::getFrame('c'));
    frame_list.push_back(Spirit::getFrame('d'));
    frame_list.push_back(Spirit::getFrame('e'));
    Spirit* spirit = new Spirit(2, 2, 1, 1, frame_list);
    renderer.addSpirit(spirit);
    std::vector<Frame *> frame_list_2 = std::vector<Frame* >(0);
    frame_list_2.push_back(Spirit::getFrame('-'));
    frame_list_2.push_back(Spirit::getFrame('\\'));
    frame_list_2.push_back(Spirit::getFrame('|'));
    frame_list_2.push_back(Spirit::getFrame('/'));
    renderer.addSpirit(new Spirit(0,0,1,1,frame_list_2));

    std::vector<Frame*> frame_list_3 = std::vector<Frame *>(0);
    char temp_1[] = {
            '1', '1', '1',
            '1', '1', '1',
            '1', '1', '1'
    };
    char temp_2[] = {
            '0', '0', '0',
            '0', '0', '0',
            '0', '0', '0'
    };
    frame_list_3.push_back(Spirit::getFrame(temp_1,3,3));
    frame_list_3.push_back(Spirit::getFrame(temp_2,3,3));
    renderer.addSpirit(new Spirit(3,3,3,3,frame_list_3));

    HANDLE timer;
    HANDLE timerQueue;
    timerQueue = CreateTimerQueue();
    CreateTimerQueueTimer(
            &timer,
            timerQueue,
            (WAITORTIMERCALLBACK)TimeProc,
            &renderer,
            0,
            200,
            0
            );
    CreateThread(NULL, 0, renderer_update, &renderer, 0, NULL);
    CreateThread(NULL, 0, renderer_display, &renderer, 0, NULL);
//    while(1){
//        renderer.update();
////        renderer.display();
//    }
//    std::cout << "Hello, World!" << std::endl;
//    Renderer renderer(25, 15);
//    Spirit me = {5,5, 'o', renderer};
////    int color;
////    std::cin >> color;
//    renderer.flash();
//    HANDLE renderThread = CreateThread(NULL, 0, render, &renderer, 0, NULL);
//    HANDLE animationThread = CreateThread(NULL, 0, animation, &me, 0, NULL);
    while(1){
        if(_kbhit()){
            int ch = _getch();
            if (ch == 27){
                break;
            }
            int x,y;
            switch (ch){
                case 'w':
                    x = 0;
                    y = -1;
                    break;
                case 's':
                    x = 0;
                    y = 1;
                    break;
                case 'a':
                    x = -1;
                    y = 0;
                    break;
                case 'd':
                    x = 1;
                    y = 0;
                    break;
            }
            spirit->move(x, y);
        }
    }
//    return 0;
}
