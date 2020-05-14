#include "Renderer.h"
#include "Controller.h"



int main() {
    Renderer renderer(100, 50); // 初始化renderer
    Controller controller(renderer);    // 初始化controller
    controller.run();                       //开始游戏
    return 0;

}
