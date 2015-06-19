#ifndef PUG_H
#define PUG_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <sstream>
#include <vector>

#include "Animal.hpp"

class Pug
{
    private:
        //Private variables
        sf::Texture pugTexture;
        sf::Clock clock;
        std::vector<sf::Sprite> vecDogSprites;
        unsigned direction;
        unsigned movementCounter;

    public:
        //Constructor
        Pug();

        //Methods
        void setDirection(int i);
        void setMovement();
        void addDog();
        void reset();
        void draw(sf::RenderWindow& w);
        bool eatAnimal(Animal &a);
        bool spawnOnBody(Animal &a);
        bool hitBody();
        bool hitWall();

        //Gets
        unsigned getSize();
};

#endif
