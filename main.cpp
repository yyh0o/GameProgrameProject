#include <iostream>
#include <conio.h>
#include "Renderer.h"
#include "Controller.h"
#include "windows.h"
#include "Spirit.h"
#include "config.h"

int main() {
    Renderer renderer(100, 50);
    Controller controller(renderer);
//    controller.test();
    controller.run();
//    return 0;
}
