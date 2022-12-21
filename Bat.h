//
// Created by Ryan on 21/12/2022.
//

#ifndef PONG_BAT_H
#define PONG_BAT_H

#include <SFML/Graphics.hpp>

class Bat {
private:
    sf::Vector2f batPos;
    float batSpeed = 0.1;
    sf::RectangleShape bat;

public:
    Bat(float x, float y);

    sf::RectangleShape getShape();

    sf::FloatRect getBounds();

    void moveUp();

    void moveDown();

    void update();
};


#endif //PONG_BAT_H
