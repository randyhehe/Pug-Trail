#include "Animal.hpp"

Animal::Animal()
{
    //Initialize srand
    srand(time(0));

    //Initialize texture
    animalTexture.loadFromFile("Textures/pug.png");

    //Initialize sprite
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
    //Draw animation
    w.draw(animalSprite);

    //Normalize animation speed
    if(clock.getElapsedTime().asSeconds() < 0.10)
        return;
    clock.restart();

    //Sprite movement
    animationCounter += 32;
    if(animationCounter > 64)
        animationCounter = 0;

    animalSprite.setTextureRect(sf::IntRect(animationCounter, 0, 32, 32));
}

sf::Sprite Animal::returnAnimalSprite()
{
    return animalSprite;
}
