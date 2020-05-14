//
// Created by yyh0o on 2020/4/27.
//

#ifndef MINI_GAME_RENDERER_H
#define MINI_GAME_RENDERER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include "config.h"
#include "Spirit.h"



class Renderer {
    HANDLE updated_event = INVALID_HANDLE_VALUE;
    int width;
    int height;
    Frame frame_buffer_1;
    Frame frame_buffer_2;
    bool is_frame_1;
    int sleep_time = 10;
    HANDLE console_handle_1, console_handle_2;
    bool is_handle_1;
    COORD coord = {0, 0};
    DWORD bytes = 0;
    Spirit background_spirit{};
    Spirit foreground_spirit{};
    std::vector<Spirit *> spirit_list;
    HANDLE update_event;
public:
    Frame* frame;
    PHANDLE getUpdateEvent();
    void display();
    void update();
    void timeBat();
    Renderer(int width, int height);
    void flash(Frame* buffer) const;
    /**
     * 将图像绘制到另一张图像
     * @param source_frame 源图像
     * @param des_frame 目标图像
     * @param x 相对坐标x
     * @param y 相对坐标y
     * @param w 源图像宽度
     * @param h 源图像高度
     */
    static void drawFrame(Frame *source_frame, Frame *des_frame, int x, int y, int w, int h);

    /**
     * 将图像绘制到Spirit
     * @param des_frame 源图像
     * @param spirit 目的精灵
     */
    static void drawSpirit(Frame* des_frame, Spirit &spirit);
    std::vector<Spirit *> *getScene();
    void addSpirit(Spirit &spirit);
    void updateBackground(Spirit &background);
    void updateForeground(Spirit &foreground);

    /**
     * 切换场景
     * @param scene 待切换场景
     */
    void changeScene(std::vector<Spirit *> &scene);

    static DWORD WINAPI renderer_update(LPVOID lpParameter);
    static DWORD WINAPI renderer_display(LPVOID lpParameter);
    static VOID CALLBACK TimeProc(PVOID lpParameter, BOOLEAN TimerOrWaitFired);
};


#endif //MINI_GAME_RENDERER_H
