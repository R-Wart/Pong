#include "Bat.h"
#include "Ball.h"

int windowWidth = 640;

int windowHeight = 480;

void userInput(Ball &ball, Bat &p1, Bat &p2, bool &running) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !running){
        ball.start();
        running = true;
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

void collision(Ball &ball, Bat &p1, Bat &p2, bool &running){
    if(ball.getBounds().top <= 0 || ball.getBounds().top + ball.getBounds().height >= windowHeight){
        ball.reboundSides();
    }

    if(ball.getBounds().intersects(p1.getBounds()) || ball.getBounds().intersects(p2.getBounds())){
        ball.reboundBats();
    }

    if(ball.getBounds().left <= 0 || ball.getBounds().left + ball.getBounds().width >= windowWidth){
        ball.ballPassEdge(windowWidth/2, windowHeight/2);
        running = false;
    }

    ball.update();
}

int main() {
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong");

    Bat player1(10,windowHeight/2);
    Bat player2(windowWidth - 20, windowHeight/2);
    Ball ball(windowWidth/2, windowHeight/2);

    bool gameRunning = false;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        //User input
        userInput(ball, player1, player2, gameRunning);

        //Collision Detection
        collision(ball, player1, player2, gameRunning);

        //Draw
        window.clear();

        window.draw(player1.getShape());

        window.draw(player2.getShape());

        window.draw(ball.getShape());

        window.display();
    }
}