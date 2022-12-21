//
// Created by Ryan on 21/12/2022.
//

#include "Bat.h"

Bat::Bat(float x, float y) {
    bat.setSize(sf::Vector2f(10, 50));

    batPos.x = x;
    batPos.y = y - bat.getGlobalBounds().height/2;

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