#include "MessageAnimation.hpp"

MessageAnimation::MessageAnimation()
:direction(0)
{
    pugTexture.loadFromFile("Textures/pug.png");

    pugSprite.setTexture(pugTexture);
    pugSprite.setTextureRect(sf::IntRect(0, 0, 32 ,32));

    scTexture.loadFromFile("Textures/starcraft.png");

    sf::Sprite tempSprite;
    tempSprite.setTexture(scTexture);
    tempSprite.setTextureRect(sf::IntRect(0, 0, 1, 1));
    tempSprite.setPosition(5, 5); //Top-left Corner
    cornerSprites.push_back(tempSprite);
    tempSprite.setPosition(770, 5); //Top-right Corner
    cornerSprites.push_back(tempSprite);
    tempSprite.setPosition(5, 570); //Bottom-left Corner
    cornerSprites.push_back(tempSprite);
    tempSprite.setPosition(770, 570); //Bottom-right Corner
    cornerSprites.push_back(tempSprite);
}

//Updates the movement of the sprite based on direction and animationCounter.
void MessageAnimation::updateMovement()
{
    if(clock.getElapsedTime().asSeconds() < 0.10)
        return;
    clock.restart();

    if(direction == 0)
        pugSprite.move(-5, 0);
    else if(direction == 1)
        pugSprite.move(0, -5);
    else if(direction == 2)
        pugSprite.move(5, 0);
    else if(direction == 3)
        pugSprite.move(0, 5);

    animationCounter += 32;
    if(animationCounter > 64)
        animationCounter = 0;
}

//When the sprite touches a corner, redirect its direction.
void MessageAnimation::updateTouchCorner()
{
    if(direction == 0)
    {
        if((pugSprite.getGlobalBounds()).intersects(cornerSprites.at(2).getGlobalBounds()))
        {
            direction = 1;
        }
    }
    else if(direction == 1)
    {
        if((pugSprite.getGlobalBounds()).intersects(cornerSprites.at(0).getGlobalBounds()))
        {
            direction = 2;
        }
    }
    else if(direction == 2)
    {
        if((pugSprite.getGlobalBounds()).intersects(cornerSprites.at(1).getGlobalBounds()))
        {
            direction = 3;
        }
    }
    else if(direction == 3)
    {
        if((pugSprite.getGlobalBounds()).intersects(cornerSprites.at(3).getGlobalBounds()))
        {
            direction = 0;
        }
    }
}

//Sets the position of the sprite.
void MessageAnimation::setPosition(int x, int y)
{
    pugSprite.setPosition((float)x, (float)y);
}

//Change the direction of the sprite.
void MessageAnimation::changeDirection(unsigned i)
{
    direction = i;
}

//Draw all properties.
void MessageAnimation::draw(sf::RenderWindow &w)
{
    unsigned movement = 0;
    if(direction == 3)
        movement = 0;
    else if(direction == 0)
        movement = 1;
    else if(direction == 2)
        movement = 2;
    else if(direction == 1)
        movement = 3;

    pugSprite.setTexture(pugTexture);
    pugSprite.setTextureRect(sf::IntRect(animationCounter, movement * 32, 32 ,32));
    w.draw(pugSprite);
}
