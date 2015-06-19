#ifndef MESSAGEANIMATION_H
#define MESSAGEANIMATION_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <vector>

class MessageAnimation
{
    private:
        sf::Clock clock;
        sf::Texture pugTexture;
        sf::Sprite pugSprite;
        sf::Texture scTexture;
        std::vector<sf::Sprite> cornerSprites;
        unsigned direction; //0 LEFT, 1 UP, 2 RIGHT, 3 DOWN
        unsigned animationCounter;

    public:
        MessageAnimation();
        void updateMovement();
        void updateTouchCorner();
        void setPosition(int x, int y);
        void changeDirection(unsigned i);
        void draw(sf::RenderWindow &w);
};

#endif
