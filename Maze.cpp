//
// Created by yyh0o on 2020/5/7.
//

#include <conio.h>
#include "Maze.h"

Maze::Maze() = default;

Maze Maze::getTestMaze() {
    Maze maze;
    maze.map = GameMap::getTestMap();
    maze.size = 10;
    maze.number = 0;
    maze.guard_amount = 1;

    return maze;
}

void Maze::setLife() {
    const char *map_content = map.get_content();
}

void Maze::show() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << maze_array[i*size+j];
        }
        std::cout << std::endl;
    }
}

Maze::Maze(int n, int size, int guard_amount, Renderer *r) {
    renderer = r;
    number = n;
    this->size = size;
    init();
    Generate();
    char *content = new char[size*size]();
    for (int i = 0; i < size * size; ++i) {
        if (maze_array[i] == UNAVAILABLE){
            content[i] = WALL;
        }
        else{
            content[i] = AIR;
        }
    }
    map = GameMap(content, size, size);
    int l = 0;
    for (int i = 0; i < size * size; ++i) {
        if (maze_array[i] == AVAILABLE){
            if (end_x == -1){
                end_x = i % size;
                end_y = i / size;
            }
            l++;
            if (l == 2 * GAP){
                Guard guard(i % size, i / size, map.get_content(), size, size);
                guards.push_back(guard);
            }
            if (l == 4 * GAP){
                Guard guard(i % size, i / size, map.get_content(), size, size);
                guards.push_back(guard);
            }
            start_x = i % size;
            start_y = i / size;
        }
    }
    player = Player(start_x, start_y);
}

void Maze::init() {
    maze_array = new int[size*size]();
    srand(time(0));
    for(int i=0;i<size/2;i++){
        for(int j=0;j<size/2;j++){
            maze.emplace_back(i,j);
        }
    }
}

void Maze::Generate() {//生成迷宫
    while(maze.size()){
        Node t=RandNode();
        std::queue<Node>q;
        q.push(t);
        int flag=0;
        while(q.size()){
            Node temp=q.front();q.pop();
            Erase(temp);
            maze_array[temp.x*2+1+(temp.y*2+1)*size]=AVAILABLE;
            int Vocation=FindWay(temp);
            if(Vocation==-1)break;
            Node Direct=Move[Vocation];
            int Nx=temp.x*2+1+Direct.x,Ny=temp.y*2+1+Direct.y;
            maze_array[Nx+Ny*size]=AVAILABLE;
            q.push(Node(temp.x+Direct.x,temp.y+Direct.y));
        }
    }
}

void Maze::Erase(Node t) {//删除节点，保证随机取点的正确性
    int l=-1,r=maze.size();
    while(r-l>1){
        int temp=(l+r)/2;
        if(maze[temp].x>t.x||(maze[temp].x==t.x&&maze[temp].y>t.y)){
            r=temp;
        }
        else l=temp;
    }
    Node lt=maze[l];
    maze.erase(maze.begin()+l);
}

int Maze::FindWay(Node a) {//寻找可移动的方向
    std::vector<int>temp;
    std::vector<int>reverse;
    for(int i=0;i<4;i++){
        int tx=a.x+Move[i].x;
        int ty=a.y+Move[i].y;
        if(tx<0||tx>=size/2||ty<0||ty>=size/2)continue;
        if(maze_array[tx*2+1+(ty*2+1)*size]==AVAILABLE){
            reverse.push_back(i);
            continue;
        }
        temp.push_back(i);
    }
    if(temp.size()==0){
        //如果无可移动方向，则可能为死点，将其四周可联通的方向全打通
        for(int i=0;i<4;i++){
            int tempx=a.x*2+1+Move[i].x;
            int tempy=a.y*2+1+Move[i].y;
            if(tempx>0&&tempx<size-1&&tempy>0&&tempy<size-1)
                maze_array[tempx+tempy*size]=AVAILABLE;
        }
        //如果是死点，则生成一个2*2的房间与周围相连，为个人优化
        for(int i=0;i<=1;i++){
            for(int j=0;j<=1;j++){
                int tx=a.x*2+1+i;
                int ty=a.y*2+1+j;
                if(tx>0&&tx<size-1&&ty>0&&ty<size-1){
                    maze_array[tx+ty*size]=AVAILABLE;
                }
            }
        }
        return -1;
    }
    else return temp[randInt(temp.size())];
}

Node Maze::RandNode() {
    int temp=randInt(maze.size());
    Node Now=maze[temp];
    return Now;
}

int Maze::randInt(int t) {//随机一个从0-(t-1)的整数
    return (int)rand()%t;
}

void Maze::run() {
    std::vector<Spirit *> *lastScene = renderer->getScene();
    std::vector<Spirit *> scene(0);
    Spirit s = getBackground();
    scene.push_back(&s);
    for (int i = 0; i < guards.size(); ++i) {
        scene.push_back(guards[i].getSpirit());
    }
    scene.push_back(player.getSpirit());
    renderer->changeScene(scene);

    int flag = 0;
    int t_x = 0;
    int t_y = 0;
    do{
        if (_kbhit()){
            t_x = 0;
            t_y = 0;
            flag = _getch();
            switch (flag) {
                case 72:    //up
                    t_y = -1;
                    break;
                case 77:    //right
                    t_x = 1;
                    break;
                case 80:    //down
                    t_y = 1;
                    break;
                case 75:    //left
                    t_x = -1;
                    break;
                case 'q':
                    return;
            }
            int p_x, p_y;
            player.getPos(&p_x, &p_y);
            p_x += t_x;
            p_y += t_y;
            if (map.checkAvailable(p_x, p_y)){
                player.move(t_x, t_y);
                for (auto & guard : guards) {
                    guard.chaseEnemy(p_x - t_x, p_y - t_y);
                }
            }
        }
    }while (flag != 27);
    renderer->changeScene(*lastScene);
}

Spirit Maze::getBackground() {
    Frame frame(size);
    for (int i = 0; i < size; ++i) {
        Frame_1d tf(size);
        for (int j = 0; j < size; ++j) {
            tf[j] = map.get_content()[i*size + j];
        }
        frame[i] = tf;
    }
    Animation ba(0);
    ba.push_back(frame);
    return Spirit(0, 0, ba);
}

void Maze::update() {
    for (auto & guard : guards) {
        guard.chaseEnemy(0,0);
    }
}
