//
// Created by yyh0o on 2020/5/7.
//

#include "Player.h"

void Player::attack() {

}

Player::Player(int x, int y, const Spirit &spirit) : Life(x, y, spirit) {


}

Player::Player(int x, int y){
    position_x = x;
    position_y = y;
    health = MAX_HEALTH;
    isAlive = true;
    Animation playerAnimation;
    Spirit::loadAnimation("../resource/Player.txt", &playerAnimation);
    cur_spirit = Spirit(x, y, playerAnimation);
}

Player::Player() = default;
