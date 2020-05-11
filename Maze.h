//
// Created by yyh0o on 2020/5/7.
//

#ifndef MINI_GAME_MAZE_H
#define MINI_GAME_MAZE_H

#include <vector>
#include <ctime>
#include <queue>
#include <iostream>
#include "GameMap.h"
#include "Player.h"
#include "Guard.h"
#include "Renderer.h"

#define AVAILABLE 1
#define UNAVAILABLE 0

#define WIN 5
#define LOSS 6

#define GAP 10

struct Node{
    int x,y;
    Node(){x=0;y=0;}
    Node(int x,int y):x(x),y(y){}
};

class Maze {
    int status = 0;
    int start_x = -1;
    int start_y = -1;
    int end_x = -1;
    int end_y = -1;
    Player player;  // 玩家
    std::vector<Guard> guards{};  // 守卫
    GameMap map;    // 地图
    int number{};   // 迷宫编号
    int size{};     // 迷宫尺寸
    int guard_amount{}; // 守卫数量
    void setLife();   // 放置玩家和守卫
    int *maze_array{};
    std::vector<Node>maze;//用于随机取点
    Renderer *renderer;

    Node Move[4]={Node(-1,0),Node(0,1),Node(1,0),Node(0,-1)};//上下左右移动
    static int randInt(int t);
    Node RandNode();
    int FindWay(Node a);

    void Erase(Node t);

    void Generate();
    void init();
    Spirit getBackground();


public:
    Maze();
    Maze(int n, int size, int guard_amount, Renderer *r);
    void show();

    static Maze getTestMaze();
    void run();
    void update();
    bool checkStop();
    int getStatus() const;
};


#endif //MINI_GAME_MAZE_H
