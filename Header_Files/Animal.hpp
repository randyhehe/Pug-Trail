#ifndef ANIMAL_H
#define ANIMAL_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <cstdlib>
#include <ctime>

class Animal
{
    private:
        //Private variables
        sf::Texture animalTexture;
        sf::Sprite animalSprite;
        sf::Clock clock;

        //Counters
        unsigned animationCounter;

    public:
        //Constructor
        Animal();

        //Methods
        void setRandomLocation();
        void draw(sf::RenderWindow& w);

        //Gets
        sf::Sprite returnAnimalSprite();
};

#endif
