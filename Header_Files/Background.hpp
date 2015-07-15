#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <vector>

class Background
{
    private:
        // Private variables
        sf::Texture backgroundTexture;
        std::vector<sf::Sprite> vecBackgrounds;

    public:
        // Constructor
        Background();

        // Methods
        void draw(sf::RenderWindow& w);
};

#endif
