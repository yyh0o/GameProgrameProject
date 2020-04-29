//
// Created by yyh0o on 2020/4/29.
//

#ifndef MINI_GAME_SPIRIT_H
#define MINI_GAME_SPIRIT_H
#include <vector>

typedef std::vector<char> Frame_1d;
typedef std::vector<Frame_1d> Frame;
typedef std::vector<Frame *> Animation;
class Spirit {
    int position_x;
    int position_y;
    int width;
    int height;
    Animation animation_key_frames;
    Animation::iterator current_frame;
public:
    Spirit(int p_x, int p_y, int width, int height, std::vector<Frame*> &animation_frames);
    Spirit(int p_x, int p_y, std::vector<Frame*> &animation_frames);
    int getX() const{return position_x;};
    int getY() const{return position_y;};
    int getWidth() const{return width;};
    int getHeight() const{return height;};
    void move(int x, int y);
    void setAnimationFrames(Animation &key_frames);
    Frame* getCurrentFrame();
    void updateFrame();
    static Frame* getFrame(char c);
    static Frame* getFrame(char c[], int height, int width);
};


#endif //MINI_GAME_SPIRIT_H
