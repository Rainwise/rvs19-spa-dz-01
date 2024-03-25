#include "Bird.h"

Bird::Bird(sf::RenderWindow* window, float yPosition)
    : window(window), speed(200), direction(1), yPosition(yPosition) {
    body.setRadius(15);
    body.setFillColor(sf::Color::Yellow);
    body.setPosition(0, yPosition); 

}

void Bird::update(float deltaTime) {
    float xPosition = body.getPosition().x + (speed * deltaTime * direction);
    if (xPosition > window->getSize().x || xPosition < -body.getRadius() * 2) {
        direction *= -1; 
    }
    body.setPosition(xPosition, yPosition);
}

void Bird::draw() {
    window->draw(body);
}
