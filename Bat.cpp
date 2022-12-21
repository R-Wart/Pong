//
// Created by Ryan on 21/12/2022.
//

#include "Bat.h"

Bat::Bat(float x, float y) {
    batPos.x = x;
    batPos.y = y;

    bat.setSize(sf::Vector2f(10, 50));
    bat.setPosition(batPos);
}

sf::RectangleShape Bat::getShape() {
    return bat;
}

sf::FloatRect Bat::getBounds() {
    return bat.getGlobalBounds();
}

void Bat::moveUp() {
    batPos.y -= batSpeed;
}

void Bat::moveDown() {
    batPos.y += batSpeed;
}

void Bat::update() {
    bat.setPosition(batPos);
}