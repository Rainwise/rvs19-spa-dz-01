#pragma once
#include <SFML/Graphics.hpp>

class Bird {
public:
    Bird(sf::RenderWindow* window, float yPosition);
    void update(float deltaTime);
    void draw();

private:
    sf::RenderWindow* window;
    sf::CircleShape body;
    sf::ConvexShape wing;
    float speed;
    float direction; // 1 for right, -1 for left
    float yPosition; // Vertical position of the bird
};