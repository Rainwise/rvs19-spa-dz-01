#pragma once
#include <SFML/Graphics.hpp>
#include "Bird.h"

class Wolf3D
{
public:
    Wolf3D(sf::RenderWindow* window);
    void draw();
    void setHealth(int health);
    void setAmmo(int ammo);
    void update(float deltaTime);
    void drawBackground();

private:
    sf::RenderWindow* window;
    int health;
    int ammo;
    Bird bird;

    sf::Font font;
    sf::Text healthText;
    sf::Text ammoText;
    sf::RectangleShape background;
    sf::Texture characterFaceTexture; 
    sf::Sprite characterFaceSprite;
};