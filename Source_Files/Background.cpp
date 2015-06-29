#include "../Header_Files/Background.hpp"

Background::Background()
{
    //Load texture
    backgroundTexture.loadFromFile("../Textures/grass.png");

    //Set background sprite
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

//Draw the background.
void Background::draw(sf::RenderWindow& w)
{
    for(unsigned i = 0; i < vecBackgrounds.size(); i++)
        w.draw(vecBackgrounds.at(i));
}
