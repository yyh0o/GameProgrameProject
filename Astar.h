//
// Created by yyh0o on 2020/5/10.
//

#ifndef MINI_GAME_ASTAR_H
#define MINI_GAME_ASTAR_H

#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <windows.h>
#include <vector>

#define STARTNODE	'1'//1表示起点
#define ENDNODE		'2'//2表示终点
#define BARRIER		'3'//3表示障碍

typedef struct p_node{
    bool isBlock;
    bool isMarked;
    int x,y;
    struct p_node* last;
    double f;
    bool is_end;
    bool is_start;
} node;

class Astar {
    int width = 30;
    int height = 20;
    int start_x{};
    int start_y{};
    int end_x{};
    int end_y{};
    int count = 0;
    node *map{};

    std::list<node*> openlist;

    static double get_distance(node* o_node, node* d_node);
public:
    Astar(const char* origin_map,int w, int h, COORD start, COORD end);

    Astar();

    std::list<const node*> get_path(node* start, node* end);

    std::list<const node*> get_path();

    std::list<const node*> get_path(COORD start, COORD end);

    void display();

    COORD getNextStep(COORD start, COORD end);
};


#endif //MINI_GAME_ASTAR_H
