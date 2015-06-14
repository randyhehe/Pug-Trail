#ifndef PUG_H
#define PUG_H

#include <sstream>
#include <vector>

#include "Animal.h"

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
        bool hitBody();
        bool hitWall();

        //Gets
        unsigned getSize();
};

Pug::Pug()
{        
    srand(time(0));

    //Set pug texture
    pugTexture.loadFromFile("Textures/pug.png");
    
    //Initialize first pug
    sf::Sprite pugSprite;
    pugSprite.setTexture(pugTexture);
    pugSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    pugSprite.move(400, 300);
    vecDogSprites.push_back(pugSprite);

    //Randomize direction
    direction = rand() % 4;
}

void Pug::setDirection(int i)
{
    //Disables backwards direction
    if((direction == 0 && i == 3) || direction == 3 && i == 0)
        return;
    else if((direction == 1 && i == 2) || direction == 2 && i == 1)
        return;
        
    direction = i;
}

void Pug::setMovement()
{
    //Sets a slow tile-like movement. Lower value for faster speed.
    if(clock.getElapsedTime().asSeconds() < 0.10)
        return;
    clock.restart();

    //Sets movement for trailing animals
    for(unsigned i = vecDogSprites.size() - 1; i > 0; i--)
    {
        sf::Vector2<float> prevPos = vecDogSprites.at(i - 1).getPosition();
        vecDogSprites.at(i).setPosition(prevPos);
        
        //Set animation for trailing animals
        vecDogSprites.at(i).setTextureRect(vecDogSprites.at(i - 1).getTextureRect());
    }

    //Set animation for the main pug
    movementCounter += 32;
    if(movementCounter > 64)
        movementCounter = 0;

    //Set movement for the main pug
    if(direction == 0)
        vecDogSprites.at(0).move(0, 20);
    else if(direction == 1)
        vecDogSprites.at(0).move(-20, 0);
    else if(direction == 2)
        vecDogSprites.at(0).move(20, 0);
    else if(direction == 3)
        vecDogSprites.at(0).move(0, -20);
    
    vecDogSprites.at(0).setTextureRect(sf::IntRect(movementCounter, direction  * 32, 32, 32));
}

void Pug::addDog()
{
    sf::Sprite pugSprite;
    pugSprite.setTexture(pugTexture);
    pugSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    pugSprite.setScale(0.90, 0.90);

    vecDogSprites.push_back(pugSprite);
}

void Pug::reset()
{
    while(vecDogSprites.size() > 1)
        vecDogSprites.pop_back();

    vecDogSprites.at(0).setPosition(400, 300);
    direction = rand() % 4;
}

void Pug::draw(sf::RenderWindow& w)
{
    for(unsigned i = 0; i < vecDogSprites.size(); i++)
    {
       w.draw(vecDogSprites.at(i));
    }
}

bool Pug::eatAnimal(Animal &a)
{
    sf::FloatRect mainPugBox = vecDogSprites.at(0).getGlobalBounds();
    sf::FloatRect animalBox = a.getSprite().getGlobalBounds();
    
    //adjust animalBox properties to properly set the intersection
    animalBox.top += 15;
    animalBox.left += 15;
    animalBox.width -= 30;
    animalBox.height -= 30;

    if(mainPugBox.intersects(animalBox))
        return true;
    
    return false;
}

bool Pug::hitBody()
{
    for(unsigned i = 1; i < vecDogSprites.size(); i++)
    {
         sf::FloatRect mainPugBox = vecDogSprites.at(0).getGlobalBounds();
         sf::FloatRect animalBox = vecDogSprites.at(i).getGlobalBounds();
         animalBox.top += 15;
         animalBox.left += 15;
         animalBox.width -= 30;
         animalBox.height -= 30;
        
         if(mainPugBox.intersects(animalBox))
            return true;
    }
    return false;
}

bool Pug::hitWall()
{
    sf::Vector2<float> mainPugCoord = vecDogSprites.at(0).getPosition();

    //bottom and right edges
    if(mainPugCoord.x > 780 || mainPugCoord.y > 585)
        return true;
    
    //top and left edges
    if(mainPugCoord.x < 0 || mainPugCoord.y < 0)
        return true;

    return false;
}

unsigned Pug::getSize()
{
    return vecDogSprites.size();
}

#endif
