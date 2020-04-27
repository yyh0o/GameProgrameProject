#include <iostream>
#include "Renderer.h"
#include "windows.h"
#include <conio.h>

DWORD WINAPI render(LPVOID lpParameter){
    Renderer *renderer = (Renderer*)lpParameter;
    while(1){
        renderer->render();
    }
}


typedef struct {
    int x;
    int y;
    char c;
    Renderer &renderer;
} Spirit;

DWORD WINAPI animation(LPVOID lpParameter){
    Spirit *me = (Spirit*)lpParameter;
    while (1){
        me->renderer.drawChar(me->x, me->y, 'o');
        me->renderer.changeFlag();
        Sleep(300);
        me->renderer.drawChar(me->x, me->y, 'O');
        me->renderer.changeFlag();
        Sleep(300);
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    Renderer renderer(25, 15);
    Spirit me = {5,5, 'o', renderer};
//    int color;
//    std::cin >> color;
    renderer.flash();
    HANDLE renderThread = CreateThread(NULL, 0, render, &renderer, 0, NULL);
    HANDLE animationThread = CreateThread(NULL, 0, animation, &me, 0, NULL);
    while(1){
        if(_kbhit()){
            int ch = _getch();
            if (ch == 27){
                break;
            }
            switch (ch){
                case 'w':
                    me.x -= 1;
                    break;
                case 's':
                    me.x += 1;
                    break;
                case 'a':
                    me.y -= 1;
                    break;
                case 'd':
                    me.y += 1;
                    break;
                case 'j':
                    renderer.changeFlag();
            }
        }
    }
    return 0;
}
