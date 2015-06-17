#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <fstream>
#include <sstream>
#include <iostream>

#include "Menu.hpp"
#include "Game.hpp"
#include "Credits.hpp"
#include "Sounds.hpp"

int main()
{
    //Default window
    sf::RenderWindow window(sf::VideoMode(800, 612), "Pug Trail", sf::Style::Titlebar | sf::Style::Close);

    //Main variables
    Game    mainGame;
    Menu    mainMenu;
    Sounds  mainSounds;
    Credits mainCredits;

    //menuCounter == 1 -> Main Menu
    //menuCounter == 0 -> Game Menu
    //menuCounter == 2 -> Credits Menu
    unsigned menuCounter = 1;

    //Game loop
    while(window.isOpen())
    {

        //Menu screen
        while(menuCounter == 1)
        {
            //Continue music if it stops
            mainSounds.continueMusic();

            //Menu updating
            mainMenu.updateHighScore();
            mainMenu.updateRecentScore();
            mainMenu.updateSelectionLocation();
            mainMenu.updateSelectionAnimation();

            if(mainSounds.checkDefaultCondition() == true)
            {
                mainSounds.clearKey();
                mainSounds.stopMusic();
                mainSounds.playDefault();
            }

            else if(mainSounds.checkSecretCondition() == true)
            {
                mainSounds.clearKey();
                mainSounds.stopMusic();
                mainSounds.playSecret();
            }

            //Event handling
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && mainMenu.returnSelectionCounter() == 0)
                {
                    menuCounter = 0;
                    break;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && mainMenu.returnSelectionCounter() == 1)
                {
                    mainCredits.reset();
                    menuCounter = 2;
                    break;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
                    mainSounds.updateKey('b');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))
                    mainSounds.updateKey('i');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
                    mainSounds.updateKey('g');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    mainSounds.updateKey('a');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::N))
                    mainSounds.updateKey('n');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    mainSounds.updateKey('d');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                    mainSounds.updateKey('e');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
                    mainSounds.updateKey('f');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::U))
                    mainSounds.updateKey('u');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
                    mainSounds.updateKey('l');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
                    mainSounds.updateKey('t');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    mainSounds.clearKey();
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    mainMenu.changeSelectionCounter(1);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    mainMenu.changeSelectionCounter(-1);
            }

            //window display
            window.clear(sf::Color::White);
            mainMenu.draw(window);
            window.display();
        }

        //Credit Screen
        while(menuCounter == 2)
        {
            //Continue music if it stops
            mainSounds.continueMusic();

            //Credits updating
            mainCredits.updateTextCounter();
            mainCredits.updateText();
            mainCredits.updatePugMovement();
            mainCredits.updateExitClock();

            //Event loop
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && mainCredits.returnExitClockTime() > 11.50)
                {
                    mainCredits.reset();
                    menuCounter = 1;
                }
            }

            //window display
            window.clear(sf::Color::White);
            mainCredits.draw(window);
            window.display();
        }

        //Game Screen
        while(menuCounter == 0)
        {
            //Continue music if it stops
            mainSounds.continueMusic();

            //Game updating
            mainGame.updateScore();
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
            if(mainGame.eatConditions() == true)
            {
                mainGame.onEat();

                //Pug woof sound
                mainSounds.playWoof();
            }

            //Event handling
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    mainGame.updateDirection(0);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    mainGame.updateDirection(1);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    mainGame.updateDirection(2);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    mainGame.updateDirection(3);
        }

            //Window display
            window.clear();
            mainGame.draw(window);
            window.display();
        }
    }
}
