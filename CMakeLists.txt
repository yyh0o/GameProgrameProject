cmake_minimum_required(VERSION 3.15)
project(MIni_Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mini_Game main.cpp Renderer.cpp Spirit.cpp Controller.cpp Controller.h Life.cpp Life.h Player.cpp Player.h Guard.cpp Guard.h GameMap.cpp GameMap.h Maze.cpp Maze.h)