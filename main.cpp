#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Pug.h"
#include "Animal.h"
#include "Background.h"

int main()
{
    //Default window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Animal Trail");
    
    Pug mainPug;
    Animal mainAnimal;
    Background mainBackground;

    //Game loop
    while(window.isOpen())
    {
        mainPug.setMovement();
        
        //End the game
        if(mainPug.hitBody())
        {
            
        }

        while(mainPug.eatAnimal(mainAnimal))
        {
            mainAnimal.setRandomLocation();
            mainPug.addDog();
        }
        
        //Event handling
        sf::Event event;
        while(window.pollEvent(event))
        {
            //Event close
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                mainPug.setDirection(0);
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                mainPug.setDirection(1);
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                mainPug.setDirection(2);
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                mainPug.setDirection(3);
        }

        window.clear();
        
        mainBackground.draw(window);
        mainAnimal.draw(window);
        mainPug.draw(window);

        window.display();
    }
}
