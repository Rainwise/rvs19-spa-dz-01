#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) : window(window) {}

void Cvijet::draw()
{
    sf::CircleShape circle(50); // Create a circle for the center of the flower
    circle.setFillColor(sf::Color(255, 255, 0)); // Set color to yellow
    circle.setPosition(375, 275); // Position the circle

    sf::RectangleShape stem(sf::Vector2f(10, 300)); // Create a stem
    stem.setFillColor(sf::Color(0, 255, 0)); // Set color to green
    stem.setPosition(395, 325); // Position the stem

    window->draw(circle); // Draw the center of the flower
    window->draw(stem); // Draw the stem
    // You can add more shapes to complete your flower design
}