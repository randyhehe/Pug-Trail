#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <fstream>
#include <sstream>

#include "Pug.h"
#include "Animal.h"
#include "Background.h"
#include "Menu.h"
#include "Sounds.h"
#include "Game.h"

int main()
{
    //Default window
    sf::RenderWindow window(sf::VideoMode(800, 612), "Animal Trail", sf::Style::Titlebar | sf::Style::Close);

    //Main variables
    Game    mainGame;
    Menu    mainMenu;
    Sounds  mainSounds;

    //menuCounter == 1 -> Main Menu
    //menuCounter == 2 -> Game Menu
    unsigned menuCounter = 1;
    
    //Game loop
    while(window.isOpen())
    {  
        //Menu screen
        while(menuCounter == 1)
        {
            //Menu updating
            mainMenu.updateHighScore();
            mainMenu.updateRecentScore();

            //Event handling
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    window.close();
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                {
                    menuCounter = 0;
                    break;
                }
            }
            window.clear(sf::Color::White);
            
            mainMenu.draw(window);

            window.display();
        }
        
        while(menuCounter == 0)
        {
            //Set score
            mainGame.updateScore();

            //Set movement
            mainGame.updateMovement();
        
            //End the game
            if(mainGame.loseConditions() == true)
            {
                //Set screen back to menu
                menuCounter = 1;

                //Update high Ssore
                if(mainGame.returnSize() > mainMenu.returnHighScore())
                {
                    mainMenu.changeHighScore(mainGame.returnSize());
                }

                //Update recent score
                mainMenu.changeRecentScore(mainGame.returnSize());

                //Reset game properties
                mainGame.reset();
                
                //Play dog whine
                mainSounds.playWhine();
            }
        
            //Consume
            while(mainGame.eatConditions() == true)
            {
                mainGame.onEat();

                //Pug woof sound
                mainSounds.playWoof();
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
                    mainGame.updateDirection(0);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    mainGame.updateDirection(1);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    mainGame.updateDirection(2);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    mainGame.updateDirection(3);
        }

            window.clear();
 
            mainGame.draw(window);
            //window.draw(scoreText);

            window.display();
        }
    }
}
