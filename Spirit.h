//
// Created by yyh0o on 2020/4/29.
//

#ifndef MINI_GAME_SPIRIT_H
#define MINI_GAME_SPIRIT_H
#include <vector>

#define NOT_SHOW 0

typedef std::vector<char> Frame_1d;
typedef std::vector<Frame_1d> Frame;
typedef std::vector<Frame *> Animation;

class Spirit {
    bool visible;                       // 是否可见
    int position_x;                     // 图形左上角的x坐标
    int position_y;                     // 图形左上角的y坐标
    int width;                          // 图形的宽
    int height;                         // 图形的高
    Animation animation_key_frames;     // 动画关键帧
    Animation::iterator current_frame;  // 当前应该显示的帧
public:
    /***
     * 构造一个默认可见的Spirit
     * @param p_x x坐标
     * @param p_y y坐标
     * @param width 宽度
     * @param height 高度
     * @param animation_frames 动画帧
     */

    Spirit(int p_x, int p_y, int width, int height, std::vector<Frame*> &animation_frames);
    /***
     * 构造一个大小为 1*1 默认可见 的spirit
     * @param p_x x坐标
     * @param p_y y坐标
     * @param animation_frames 动画帧
     */
    Spirit(int p_x, int p_y, std::vector<Frame*> &animation_frames);

    /***
     * 构造一个Spirit
     * @param isVisible 是否可见
     * @param px x坐标
     * @param py y坐标
     * @param w 宽
     * @param h 高
     * @param animation_frames 动画帧
     */
    Spirit(bool isVisible, int px, int py, int w, int h, std::vector<Frame*> &animation_frames);

    /***
     * 构造一个大小为 1*1 的Spirit
     * @param isVisible 是否可见
     * @param p_x x坐标
     * @param p_y y坐标
     * @param animation_frames 动画帧
     */
    Spirit(bool isVisible, int p_x, int p_y, std::vector<Frame*> &animation_frames);

    /***
     * 设置当前Spirit是否可见
     * @param isVisible 是否可见
     */
    void setVisible(bool isVisible);

    /***
     * 返回当前Spirit是否可见
     * @return
     */
    bool isVisible();
    int getX() const{return position_x;};
    int getY() const{return position_y;};
    int getWidth() const{return width;};
    int getHeight() const{return height;};
    /**
     * 移动Spirit
     * @param x 在x轴移动的距离
     * @param y 在y轴移动的距离
     */
    void move(int x, int y);
    /**
     * 设置动画帧
     * @param key_frames
     */
    void setAnimationFrames(Animation &key_frames);
    /**
     * 获取当前应该显示的帧
     * @return
     */
    Frame* getCurrentFrame();
    /**
     * 更新动画帧
     */
    void updateFrame();

    /**
     * 生成一个1*1大小的帧
     * @param c
     * @return 生成地Frame
     */
    static Frame* generateFrame(char c);

    /**
     * 生成一个帧
     * @param c 帧内容
     * @param height 高度
     * @param width 宽度
     * @return 生成的Frame
     */
    static Frame* generateFrame(const char *c, int height, int width);
};


#endif //MINI_GAME_SPIRIT_H
