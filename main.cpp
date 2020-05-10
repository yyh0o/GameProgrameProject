#include <iostream>
#include <conio.h>
#include "Renderer.h"
#include "Controller.h"
#include "windows.h"
#include "Spirit.h"
#include "config.h"
#include "Astar.h"


int main() {
    Renderer renderer(100, 50);
    Controller controller(renderer);
    controller.test();
    controller.run();
    return 0;

//    char array[] = {			// 实例
//             '1','0','0','3','0','3','0','0','0','0' ,
//             '0','0','3','0','0','3','0','3','0','3' ,
//             '3','0','0','0','0','3','3','3','0','3' ,
//             '3','0','3','0','0','0','0','0','0','3' ,
//             '3','0','0','0','0','3','0','0','0','3' ,
//             '3','0','0','3','0','0','0','3','0','3' ,
//             '3','0','0','0','0','3','3','0','0','0' ,
//             '0','0','0','0','0','0','0','0','0','0' ,
//             '3','3','3','0','0','3','0','3','0','3' ,
//             '3','0','0','0','2','3','3','3','0','3'
//    };
//    Astar t(array, 10, 10, {0,0}, {4, 9});
//    t.display();
//    auto l = t.get_path();
//    for (auto i : l){
//        std::cout << "(" << i->x << ", " << i->y << ")" << std::endl;
//    }
}
