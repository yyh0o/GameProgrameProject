//
// Created by yyh0o on 2020/4/27.
//

#include <iostream>
#include "Renderer.h"

Renderer::Renderer(int w, int h) {
    width = w;
    height = h;
    frame_buffer_1 = Frame(h);
    frame_buffer_2 = Frame(h);
    for (int i = 0; i < h; ++i) {
        frame_buffer_1[i] = Frame_1d(w);
        frame_buffer_2[i] = Frame_1d(w);
    }
    is_frame_1 = true;
    console_handle_1 = CreateConsoleScreenBuffer(
            GENERIC_WRITE,
            FILE_SHARE_WRITE,
            NULL,
            CONSOLE_TEXTMODE_BUFFER,
            NULL
            );
    console_handle_2 = CreateConsoleScreenBuffer(
            GENERIC_WRITE,
            FILE_SHARE_WRITE,
            NULL,
            CONSOLE_TEXTMODE_BUFFER,
            NULL
    );
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(console_handle_1, &cci);
    SetConsoleCursorInfo(console_handle_2, &cci);
    is_handle_1 = true;
    update_event = CreateEvent(NULL, FALSE, FALSE, NULL);
    background_spirit = NULL;
    foreground_spirit = NULL;
    frame = &frame_buffer_1;
}

void Renderer::display() {
        while (true) {
            HANDLE handle;
            if(is_handle_1){
                handle = console_handle_2;
            }
            else {
                handle = console_handle_1;
            }
            for (int i = 0; i < height; ++i) {
                coord.Y = i;
                for (int j = 0; j < width; ++j) {
                    coord.X = j;
                    WriteConsoleOutputCharacterA(handle, &((*frame)[i][j]), 1, coord, &bytes);
                }
            }
            is_handle_1 = !is_handle_1;
            SetConsoleActiveScreenBuffer(handle);
            Sleep(SCREEN_DELAY);
        }
}

void Renderer::update() {
    Frame* frame_buffer;
    if(is_frame_1) {
        frame_buffer = &frame_buffer_2;
    }
    else {
        frame_buffer = &frame_buffer_1;
    }
    flash(frame_buffer);
    if (background_spirit){
        drawSpirit(frame_buffer, background_spirit);
    }
    for (auto item : spirit_list){
        if(item->isVisible()){
            drawSpirit(frame_buffer, item);
        }
    }
    if (foreground_spirit){
        drawSpirit(frame_buffer, foreground_spirit);
    }
    frame = frame_buffer;
    is_frame_1 = !is_frame_1;
}

void Renderer::drawFrame(Frame *source_frame, Frame *des_frame, int x, int y, int w, int h) {
    for (int i = 0; i < h; ++i) {
        int pos_y = y + i;
        for (int j = 0; j < w; ++j) {
            int pos_x = x + j;
            // 未检测越界
            char source_char = (*source_frame)[i][j];
            if (source_char == NOT_SHOW){ continue;}
            (*des_frame)[pos_y][pos_x] = source_char;
        }
    }
}

void Renderer::drawSpirit(Frame *des_frame, Spirit *spirit) {
    Frame *source;
    source = spirit->getCurrentFrame();
    spirit->updateFrame();
    drawFrame(source, des_frame, spirit->getX(), spirit->getY(), spirit->getWidth(), spirit->getHeight());
}

void Renderer::flash(Frame *buffer) const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            (*buffer)[i][j] = ' ';
        }
    }
}

void Renderer::addSpirit(Spirit *spirit) {
    spirit_list.push_back(spirit);
}

void Renderer::timeBat() {
    SetEvent(update_event);
}

PHANDLE Renderer::getUpdateEvent() {
    return &update_event;
}

void Renderer::updateBackground(Spirit *background) {
    background_spirit = background;
}

void Renderer::updateForeground(Spirit *foreground) {
    foreground_spirit = foreground;
}



