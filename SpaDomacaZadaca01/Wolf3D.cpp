#include "Wolf3D.h"


Wolf3D::Wolf3D(sf::RenderWindow* window) : window(window), bird(window, 150), health(100), ammo(50)
{

    bird = Bird(window, 80.0f);

    if (!font.loadFromFile("fonts/RETROTECH.ttf"))
    {
    }

    if (!characterFaceTexture.loadFromFile("assets/ilija.png")) 
    {
    }

    // Plavi bottom ui 
    background.setSize(sf::Vector2f(window->getSize().x, 100)); 
    background.setPosition(0, window->getSize().y - 100); 
    background.setFillColor(sf::Color(0, 0, 255, 150));

    // Tekst za health
    healthText.setFont(font);
    healthText.setCharacterSize(25);
    healthText.setFillColor(sf::Color::White);
    healthText.setPosition(10, window->getSize().y - 60);

    // Text za ammo
    ammoText.setFont(font);
    ammoText.setCharacterSize(25); 
    ammoText.setFillColor(sf::Color::White);
    ammoText.setPosition(window->getSize().x - 120, window->getSize().y - 60);

    // Avatar u sredini
    characterFaceSprite.setTexture(characterFaceTexture);
    sf::Vector2u textureSize = characterFaceTexture.getSize();

    float scaleX = 100.0f / textureSize.x;
    float scaleY = 100.0f / textureSize.y;

    characterFaceSprite.setScale(scaleX, scaleY);
    float spriteWidth = textureSize.x * scaleX;
    float spriteHeight = textureSize.y * scaleY;

    float xPosition = (window->getSize().x / 2.0f) - (spriteWidth / 2.0f);
    float spaceAboveBackground = background.getSize().y - spriteHeight;
    float yPosition = window->getSize().y - background.getSize().y + (spaceAboveBackground / 2.0f);
    characterFaceSprite.setPosition(xPosition, yPosition);
}


// Crta pozadinu sa drvima
void Wolf3D::drawBackground() {

    // Boja za pozadinu
    sf::RectangleShape backgroundShape(sf::Vector2f(window->getSize().x, window->getSize().y - background.getSize().y));
    backgroundShape.setFillColor(sf::Color(0, 0, 0)); 
    window->draw(backgroundShape);

    // Boja za drvece
    sf::Color trunkColor(101, 67, 33); 
    sf::Color leafColor(0, 128, 0);

    // Setup drveca
    const int treeWidth = 40;      
    const int treeHeight = 200;    
    const int foliageWidth = 120;  
    const int foliageHeight = 120;
    const int treeBasePosition = window->getSize().y - background.getSize().y - 50;


    for (int i = 0; i < 5; ++i) {

        sf::RectangleShape treeTrunk(sf::Vector2f(treeWidth, treeHeight));
        treeTrunk.setFillColor(trunkColor);
        int trunkXPosition = 60 + i * (window->getSize().x / 5);
        treeTrunk.setPosition(trunkXPosition, treeBasePosition - treeHeight);
        window->draw(treeTrunk);

        for (int j = 0; j < 2; ++j) {
            sf::ConvexShape treeFoliage;
            treeFoliage.setPointCount(3);
            treeFoliage.setFillColor(leafColor);
            // Top
            treeFoliage.setPoint(0, sf::Vector2f(trunkXPosition + treeWidth / 2, treeBasePosition - treeHeight - (j * foliageHeight)));
            // Bottom left
            treeFoliage.setPoint(1, sf::Vector2f(trunkXPosition - foliageWidth / 2, treeBasePosition - treeHeight + foliageHeight - (j * foliageHeight)));
            // Bottom right
            treeFoliage.setPoint(2, sf::Vector2f(trunkXPosition + treeWidth + foliageWidth / 2, treeBasePosition - treeHeight + foliageHeight - (j * foliageHeight)));
            window->draw(treeFoliage);
        }
    }
}

void Wolf3D::update(float deltaTime) {
    bird.update(deltaTime);
}

void Wolf3D::draw()
{
    
    drawBackground();
    bird.draw();
    healthText.setString("Health: " + std::to_string(health));
    ammoText.setString("Ammo: " + std::to_string(ammo));
    window->draw(background);
    window->draw(healthText);
    window->draw(ammoText);
    window->draw(characterFaceSprite);
}

void Wolf3D::setHealth(int health)
{
    this->health = health;
}

void Wolf3D::setAmmo(int ammo)
{
    this->ammo = ammo;
}