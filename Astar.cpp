//
// Created by yyh0o on 2020/5/10.
//

#include "Astar.h"

Astar::Astar(const char *origin_map,int w, int h, COORD start, COORD end) {
    start_x = start.X;
    start_y = start.Y;
    end_x = end.X;
    end_y = end.Y;
    height = h;
    width = w;

    map = new node[h*w];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            node n;
            n.x = j;
            n.y = i;
            n.isBlock = origin_map[i * width + j] == BARRIER;
            n.isMarked = false;
            n.is_start = i == start_y && j == start_x;
            n.is_end = i == end_y && j == end_x;
            n.last = nullptr;
            map[i*width+j] = n;
        }
    }
}

double Astar::get_distance(node *o_node, node *d_node) {
    return sqrt(pow(o_node->x - d_node->x, 2) + pow(o_node->y - d_node->y, 2));
}

std::list<const node*> Astar::get_path(node *start, node *end) {
    end_x = end->x;
    end_y = end->y;
    openlist.clear();
    for (int i = 0; i < width * height; ++i) {
        map[i].isMarked = false;
        map[i].last = NULL;
    }
    std::list<const node*> result(0);
    openlist.push_back(start);
    start->isMarked = true;
    while(true){
        node* current_node = openlist.front();
        current_node->isMarked=true;
        if(current_node == end)
            break;
        node* tmp;
        for (int i = -1; i <= 1; ++i) {
            int t_y = current_node->y + i;
            if (t_y < 0 || t_y >= height)
                continue;
            for (int j = -1; j <=1; ++j) {
                if (i != 0 && j != 0)
                    continue;
                int t_x = current_node->x + j;
                if (t_x < 0 || t_x >= width)
                    continue;
                tmp = &map[t_y*width + t_x];
                if (tmp->isMarked || tmp->isBlock)
                    continue;
                tmp->isMarked = true;
                tmp->last = current_node;
                tmp->f = 1 + get_distance(tmp, end);
                if (tmp->f > openlist.back()->f){
                    openlist.push_back(tmp);
                }
                else{
                    for(auto item = openlist.begin(); item != openlist.end(); item++){
                        if  ((*item)->f >= tmp->f){
                            openlist.insert(item, tmp);
                            break;
                        }
                    }
                }

            }
        }
        for(auto item = openlist.begin(); item != openlist.end(); item++){
            if ((*item) == current_node){
                openlist.erase(item);
                break;
            }
        }
    }
    for (node* tmp = &map[end_y*width+end_x]; tmp; tmp = tmp->last){
        result.push_front(tmp);
    }
    return result;
}

std::list<const node *> Astar::get_path() {
    return get_path(&map[start_x+start_y*width], &map[end_x+end_y*width]);
}

std::list<const node *> Astar::get_path(COORD start, COORD end) {
    return get_path(&map[start.X+start.Y*width], &map[end.X+width*end.Y]);
}

void Astar::display() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (map[i*width+j].isBlock){
                std::cout << '3';
            } else{
                std::cout << '0';
            }
        }
        std::cout << std::endl;
    }
}

COORD Astar::getNextStep(COORD start, COORD end) {
    if (start.X == end.X && start.Y == end.Y){
        return start;
    }
    std::list<const node*> tmp = get_path(start, end);
//    for (auto i : tmp){
//        std::cout << "(" << i->x << ", " << i->y << ")" << std::endl;
//    }
    tmp.pop_front();
    COORD result;
    result.X = tmp.front()->x;
    result.Y = tmp.front()->y;
    return result;
}

Astar::Astar()= default;;


