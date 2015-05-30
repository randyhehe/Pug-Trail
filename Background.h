#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <vector>

class Background
{
    private:
        sf::Texture backgroundTexture;
        std::vector<sf::Sprite> vecBackgrounds;

    public:
        Background();
        void draw(sf::RenderWindow& w);
};

Background::Background()
{
    backgroundTexture.loadFromFile("grass.png");

    sf::Sprite temp;
    temp.setTexture(backgroundTexture);
    vecBackgrounds.push_back(temp);

    temp.setPosition(200, 0);
    vecBackgrounds.push_back(temp);

    temp.setPosition(0, 180);
    vecBackgrounds.push_back(temp);

    temp.move(180, 0);
    vecBackgrounds.push_back(temp);
}

void Background::draw(sf::RenderWindow& w)
{
    for(unsigned i = 0; i < vecBackgrounds.size(); i++)
        w.draw(vecBackgrounds.at(i));
}

#endif
