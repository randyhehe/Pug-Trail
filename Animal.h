#ifndef ANIMAL_H
#define ANIMAL_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <cstdlib>
#include <ctime>

class Animal
{
    private:
        sf::Texture animalTexture;
        sf::Sprite animalSprite;
        sf::Clock clock;
        unsigned animationCounter;

    public:
        Animal();
        void setRandomLocation();
        void draw(sf::RenderWindow& w);
        sf::Sprite getSprite();
        ~Animal(){};
};

Animal::Animal()
{
    //Initialize srand
    srand(time(0));

    animalTexture.loadFromFile("Textures/pug.png");
    animalSprite.setTexture(animalTexture);
    animalSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    animalSprite.setScale(0.90, 0.90);

    //Places animalSprite to a random location
    setRandomLocation();
}

void Animal::setRandomLocation()
{
    //Randomize x and y values
    float xLocation = (rand() % 30) * 20;
    float yLocation = (rand() % 30) * 20;
    sf::Vector2<float> location(xLocation, yLocation);

    //Assign x and y to animalSprite
    animalSprite.setPosition(location);
}

void Animal::draw(sf::RenderWindow& w)
{
    //set animation
    if(clock.getElapsedTime().asSeconds() > 0.10)
    {
        clock.restart();

        animationCounter += 32;
        if(animationCounter > 64)
            animationCounter = 0;
        
        animalSprite.setTextureRect(sf::IntRect(animationCounter, 0, 32, 32));
    }
    w.draw(animalSprite);
}

sf::Sprite Animal::getSprite()
{
    return animalSprite;
}

#endif
