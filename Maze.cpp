//
// Created by yyh0o on 2020/5/7.
//

#include "Maze.h"

Maze::Maze() = default;

Maze Maze::getTestMaze() {
    Maze maze;
    maze.map = GameMap::getTestMap();
    maze.height = 10;
    maze.width = 10;
    maze.number = 0;
    maze.guard_amount = 1;
    maze.guards.emplace_back();

    return maze;
}

void Maze::setLife() {
    const char *map_content = map.get_content();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {

        }
    }
}
