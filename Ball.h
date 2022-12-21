//
// Created by Ryan on 21/12/2022.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <SFML/Graphics.hpp>
#include <algorithm>

class Ball {
private:
    sf::Vector2f ballPos;
    float ballSpeed = 0.05;
    float xVelocity = 0;
    float yVelocity = 0;
    sf::RectangleShape ball;
public:
    Ball(float x, float y);

    sf::RectangleShape getShape();

    sf::FloatRect getBounds();

    void reboundSides();

    void reboundBats();

    void reset(int x, int y);

    void start();

    void update();
};


#endif //PONG_BALL_H
