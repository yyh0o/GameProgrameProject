//
// Created by yyh0o on 2020/4/29.
//

#include "Spirit.h"
Spirit::Spirit(int p_x, int p_y, std::vector<Frame*> &animation_frames){
    position_x = p_x;
    position_y = p_y;
    width = 1;
    height = 1;
    animation_key_frames = animation_frames;
    current_frame = animation_key_frames.begin();
}
Spirit::Spirit(int p_x, int p_y, int width, int height, std::vector<Frame*> &animation_frames){
    position_x = p_x;
    position_y = p_y;
    this->width = width;
    this->height = height;
    animation_key_frames = animation_frames;
    current_frame = animation_key_frames.begin();
}

Frame* Spirit::getCurrentFrame() {
    return *current_frame;
}

void Spirit::move(int x, int y) {
    position_x += x;
    position_y += y;
}

void Spirit::setAnimationFrames(std::vector<Frame *> &key_frames) {
    animation_key_frames = key_frames;
}

void Spirit::updateFrame() {
    current_frame++;
    if (current_frame == animation_key_frames.end()){
        current_frame = animation_key_frames.begin();
    }
}

Frame *Spirit::getFrame(char c) {
    Frame *frame = new Frame();
    frame->push_back(std::vector<char>(0));
    (*frame)[0].push_back(c);
    return frame;
}

Frame *Spirit::getFrame(char c[], int height, int width) {
    Frame *frame = new Frame(height);
    for (int i = 0; i < height; ++i) {
        std::vector<char> tmp(width);
        for (int j = 0; j < width; ++j) {
            tmp[j] = c[i*width + j];
        }
        (*frame)[i] = tmp;
    }
    return frame;
}