//
// Created by yyh0o on 2020/4/29.
//

#include "Spirit.h"
Spirit::Spirit(int p_x, int p_y, Animation &animation_frames){
    visible = true;
    position_x = p_x;
    position_y = p_y;
    width = animation_frames[0][0].size();
    height = animation_frames[0].size();
    animation_key_frames = animation_frames;
    current_frame = 0;
    animation_size = animation_frames.size();
}
Spirit::Spirit(int p_x, int p_y, int width, int height, Animation &animation_frames){
    visible = true;
    position_x = p_x;
    position_y = p_y;
    this->width = width;
    this->height = height;
    animation_key_frames = animation_frames;
    current_frame = 0;
    animation_size = animation_frames.size();
}

Frame Spirit::getCurrentFrame() {
    return animation_key_frames[current_frame];
}

void Spirit::move(int x, int y) {
    position_x += x;
    position_y += y;
}

void Spirit::setAnimationFrames(Animation &key_frames) {
    animation_key_frames = key_frames;
}

void Spirit::updateFrame() {
    current_frame++;
    if (current_frame == animation_size){
        current_frame = 0;
    }
}

Frame Spirit::generateFrame(char c) {
    Frame frame(0);
    frame.push_back(Frame_1d(0));
    frame[0].push_back(c);
    return frame;
}

Frame Spirit::generateFrame(const char *c, int height, int width) {
    Frame frame(height);
    for (int i = 0; i < height; ++i) {
        Frame_1d tmp(width);
        for (int j = 0; j < width; ++j) {
            tmp[j] = c[i*width + j];
        }
        frame[i] = tmp;
    }
    return frame;
}

Spirit::Spirit(bool isVisible, int px, int py, int w, int h, Animation &animation_frames) {
    visible = isVisible;
    position_x = px;
    position_y = py;
    width = w;
    height = h;
    animation_key_frames = animation_frames;
    current_frame = 0;
    animation_size = animation_frames.size();
}

Spirit::Spirit(bool isVisible, int p_x, int p_y, Animation &animation_frames) {
    visible = isVisible;
    position_x = p_x;
    position_y = p_y;
    width = animation_frames[0][0].size();
    height = animation_frames[0].size();
    animation_key_frames = animation_frames;
    current_frame = 0;
    animation_size = animation_frames.size();
}

void Spirit::setVisible(bool isVisible) {
    visible = isVisible;
}

bool Spirit::isVisible() const {
    return visible;
}

bool Spirit::loadAnimation(const char *file_name, Animation *animation) {
    int frame_num;
    int height;
    int width;
    std::ifstream in(file_name, std::ios::in);
    if (in.is_open()){
        in >> frame_num;
        in >> height;
        in >> width;
        for (int i = 0; i < frame_num; ++i) {
            Frame tmp_frame(0);
            for (int j = 0; j < height; ++j) {
                Frame_1d tmp_frame_1d(0);
                for (int k = 0; k < width; ++k) {
                    char c;
                    in >> c;
                    if (c == '0'){
                        c = NOT_SHOW;
                    }
                    tmp_frame_1d.push_back(c);
                }
                tmp_frame.push_back(tmp_frame_1d);
            }
            animation->push_back(tmp_frame);
        }
        in.close();
        return true;
    }
    return false;
}

bool Spirit::writeAnimation(const char *file_name, const Animation& animation) {
    if (animation.empty()){
        return false;
    }
    else if (animation[0].empty()){
        return false;
    }
    else if (animation[0][0].empty()){
        return false;
    }
    else {
        int frame_num = animation.size();
        int height = animation[0].size();
        int width = animation[0][0].size();
        std::ofstream out(file_name, std::ios::out);
        if (out.is_open()){
            out << frame_num << " " << height << " " << width << std::endl;
            for (int i = 0; i < frame_num; ++i) {
                for (int j = 0; j < height; ++j) {
                    for (int k = 0; k < width; ++k) {
                        out << animation[i][j][k];
                    }
                }
            }
            out.close();
            return true;
        }
    }
    return false;
}

Animation Spirit::loadAnimation(const char *file_name) {
    int frame_num;
    int height;
    int width;
    Animation animation(0);
    std::ifstream in(file_name, std::ios::in);
    if (in.is_open()){
        in >> frame_num;
        in >> height;
        in >> width;
        for (int i = 0; i < frame_num; ++i) {
            Frame tmp_frame(0);
            for (int j = 0; j < height; ++j) {
                Frame_1d tmp_frame_1d(0);
                for (int k = 0; k < width; ++k) {
                    char c;
                    in >> c;
                    if (c == '0'){
                        c = NOT_SHOW;
                    }
                    tmp_frame_1d.push_back(c);
                }
                tmp_frame.push_back(tmp_frame_1d);
            }
            animation.push_back(tmp_frame);
        }
        in.close();
        return animation;
    }
    return Animation();
}

Spirit::Spirit() {
    visible = false;
}
