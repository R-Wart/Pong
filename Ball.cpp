//
// Created by Ryan on 21/12/2022.
//

#include "Ball.h"

Ball::Ball(float x, float y) {
    ballPos.x = x;
    ballPos.y = y;

    ball.setSize(sf::Vector2f(10, 10));
    ball.setPosition(ballPos);
}

sf::RectangleShape Ball::getShape() {
    return ball;
}

sf::FloatRect Ball::getBounds() {
    return ball.getGlobalBounds();
}

void Ball::reboundSides() {
    yVelocity *= -1;
}

void Ball::reboundBats() {
    xVelocity *= -1;
}

void Ball::ballPassEdge(int x, int y) {
    xVelocity = 0;
    yVelocity = 0;

    ballPos.x = x;
    ballPos.y = y;
}

void Ball::start() {
    xVelocity = ballSpeed;
    yVelocity = ballSpeed;

    int i = rand() % 4;

    switch(i){
        case 1:
            xVelocity *= -1;
            break;
        case 2:
            yVelocity *= -1;
            break;
        case 3:
            xVelocity *= -1;
            yVelocity *= -1;
            break;
        default:
            break;
    }
}

void Ball::update() {
    ballPos.x += xVelocity;
    ballPos.y += yVelocity;

    ball.setPosition(ballPos);
}