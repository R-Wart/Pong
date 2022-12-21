#include <iostream>
#include "Bat.h"
#include "Ball.h"

int windowWidth = 640;

int windowHeight = 480;

void setup(sf::RenderWindow &window){
    sf::RectangleShape line;
    line.setSize(sf::Vector2f(5, 30));
    for(int y = 15; y < 480; y += line.getGlobalBounds().height + 30){
        line.setPosition(windowWidth/2 - line.getGlobalBounds().width/2, y);
        window.draw(line);
    }
}

void userInput(Ball &ball, Bat &p1, Bat &p2, bool &started, bool &running) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !running){
        ball.start();
        running = true;
        if(!started){
            started = true;
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
        ball.reset(windowWidth/2, windowHeight/2);
        running = false;
        started = false;
    }

    if(p1.getBounds().top >= 10 && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        p1.moveUp();
    }

    if(p1.getBounds().top + p1.getBounds().height <= windowHeight - 10 && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        p1.moveDown();
    }

    p1.update();

    if (p2.getBounds().top >= 10 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        p2.moveUp();
    }

    if (p2.getBounds().top + p2.getBounds().height <= windowHeight - 10 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        p2.moveDown();
    }

    p2.update();
}

void collision(Ball &ball, Bat &p1, Bat &p2, bool &running, sf::Text &player1Score, int &p1Score, sf::Text &player2Score, int &p2Score){
    if(ball.getBounds().top <= 0 || ball.getBounds().top + ball.getBounds().height >= windowHeight){
        ball.reboundSides();
    }

    if(ball.getBounds().intersects(p1.getBounds()) || ball.getBounds().intersects(p2.getBounds())){
        ball.reboundBats();
    }

    if(ball.getBounds().left <= 0 ) {
        p2Score += 1;
        player2Score.setString(std::to_string(p2Score));

        ball.reset(windowWidth/2, windowHeight/2);
        running = false;
    }

    if(ball.getBounds().left + ball.getBounds().width >= windowWidth){
        p1Score += 1;
        player1Score.setString(std::to_string(p1Score));

        ball.reset(windowWidth/2, windowHeight/2);
        running = false;
    }

    ball.update();
}

void draw(sf::RenderWindow &window, sf::Text p1Score, sf::Text p2Score,Bat p1, Bat p2, Ball ball){
    window.draw(p1Score);

    window.draw(p2Score);

    window.draw(p1.getShape());

    window.draw(p2.getShape());

    window.draw(ball.getShape());

    window.display();
}

int main() {
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong");

    sf::Text player1Score;
    sf::Text player2Score;

    sf::Font font;
    if (!font.loadFromFile("resources/Square.ttf")) {
        std::cout << "Couldn't find font" << std::endl;
    }

    player1Score.setFont(font);
    player1Score.setString("0");
    player1Score.setCharacterSize(24);
    player1Score.setFillColor(sf::Color::White);
    player1Score.setPosition(windowWidth/2 - (windowWidth/2)/2, 10);

    player2Score.setFont(font);
    player2Score.setString("0");
    player2Score.setCharacterSize(24);
    player2Score.setFillColor(sf::Color::White);
    player2Score.setPosition(windowWidth/2 + (windowWidth/2)/2, 10);

    Bat player1(10,windowHeight/2);
    Bat player2(windowWidth - 20, windowHeight/2);
    Ball ball(windowWidth/2, windowHeight/2);

    int p1Score = 0;
    int p2Score = 0;

    bool gameStarted = false;
    bool gameRunning = false;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        setup(window);

        userInput(ball, player1, player2, gameStarted,gameRunning);

        collision(ball, player1, player2, gameRunning, player1Score, p1Score, player2Score, p2Score);

        draw(window, player1Score, player2Score, player1, player2, ball);
    }
}