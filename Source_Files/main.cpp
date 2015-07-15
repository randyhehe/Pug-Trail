#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <fstream>
#include <sstream>
#include <iostream>

#include "../Header_Files/Menu.hpp"
#include "../Header_Files/Game.hpp"
#include "../Header_Files/Credits.hpp"
#include "../Header_Files/Sounds.hpp"
#include "../Header_Files/Message.hpp"
#include "../Header_Files/MessageAnimation.hpp"

int main()
{
    // FreeConsole();

    // Default window
    sf::RenderWindow window(sf::VideoMode(800, 612), "Pug Trail", sf::Style::Titlebar | sf::Style::Close);

    // Main variables
    Game    mainGame;
    Menu    mainMenu;
    Sounds  mainSounds;
    Credits mainCredits;
    Message mainMessage;

    // menuCounter == 1 -> Main Menu
    // menuCounter == 0 -> Game Menu
    // menuCounter == 2 -> Credits Menu
    // menuCounter == 3 -> Message
    // menuCounter == 4 -> Terminate Program
    unsigned menuCounter = 1;

    // Game loop
    while(window.isOpen())
    {

        // Menu screen
        while(menuCounter == 1)
        {
            // Continue music when finished
            mainSounds.continueMusic();

            // Updates
            mainMenu.updateHighScore();
            mainMenu.updateRecentScore();
            mainMenu.updateSelectionLocation();
            mainMenu.updateSelectionAnimation();

            // Music toggle
            if(mainMenu.clicksoundCollison() == true)
            {
                if(mainSounds.isMuted() == false)
                {
                    mainMenu.resetClickSpriteLocation();
                    mainMenu.switchSoundIcon(false);
                    mainSounds.muteMusic();
                }
                else if(mainSounds.isMuted() == true)
                {
                    mainMenu.resetClickSpriteLocation();
                    mainMenu.switchSoundIcon(true);
                    mainSounds.unmuteMusic();
                }
            }

            // Switch to default music
            if(mainSounds.checkDefaultCondition() == true)
            {
                mainSounds.clearKey();
                mainSounds.stopMusic();
                mainSounds.playDefault();
            }

            // Switch to secret music
            else if(mainSounds.checkSecretCondition() == true)
            {
                mainSounds.clearKey();
                mainSounds.stopMusic();
                mainSounds.playSecret();
            }

            if(mainMessage.correctKey() == true)
            {
                mainMessage.clearKey();
                menuCounter = 3;
                break;
            }

            // Event handling
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    window.close();
                    menuCounter = 4;
                }
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
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
                    mainMessage.updateKey('0');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
                    mainMessage.updateKey('6');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
                    mainMessage.updateKey('3');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                    mainMessage.updateKey('1');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
                    mainMessage.updateKey('4');
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    mainSounds.clearKey();
                    mainMessage.clearKey();
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    mainMenu.changeSelectionCounter(1);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    mainMenu.changeSelectionCounter(-1);
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                    mainMenu.setClickSpritePosition(localPosition.x, localPosition.y);
                }
            }

            // window display
            window.clear(sf::Color::White);
            mainMenu.draw(window);
            window.display();
        }

        // Credit Screen
        while(menuCounter == 2)
        {
            // Continue music if it stops
            mainSounds.continueMusic();

            // Credits updating
            mainCredits.updateTextCounter();
            mainCredits.updateText();
            mainCredits.updatePugMovement();
            mainCredits.updateExitClock();

            // Event loop
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    window.close();
                    menuCounter = 4;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && mainCredits.returnExitClockTime() > 11.50)
                {
                    mainCredits.reset();
                    menuCounter = 1;
                }
            }

            // window display
            window.clear(sf::Color::White);
            mainCredits.draw(window);
            window.display();
        }

        // Message Screen
        while(menuCounter == 3)
        {
            // Continue music if it stops
            mainSounds.continueMusic();

            mainMessage.updateText();
            mainMessage.updateTextCounter();
            mainMessage.updateMessageAnimations();

            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    window.close();
                    menuCounter = 4;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                {
                    mainMessage.resetTextCounter();
                    menuCounter = 1;
                }
            }

            // Window display
            window.clear(sf::Color::White);
            mainMessage.draw(window);
            window.display();
        }

        // Game Screen
        while(menuCounter == 0)
        {
            // Continue music if it stops
            mainSounds.continueMusic();

            // Game updating
            mainGame.updateScore();
            mainGame.updateMovement();

            if(mainGame.spawnOnBody() == true)
            {
                mainGame.changeLocation();
            }

            // End the game
            if(mainGame.loseConditions() == true)
            {
                // Set screen back to menu
                menuCounter = 1;

                // Update high Ssore
                if(mainGame.returnSize() > mainMenu.returnHighScore())
                {
                    mainMenu.changeHighScore(mainGame.returnSize());
                }

                // Update recent score
                mainMenu.changeRecentScore(mainGame.returnSize());

                // Reset game properties
                mainGame.reset();

                // Play dog whine
                if(mainSounds.isMuted() == false)
                    mainSounds.playWhine();
            }

            // Consume
            if(mainGame.eatConditions() == true)
            {
                mainGame.onEat();

                // Pug woof sound
                if(mainSounds.isMuted() == false)
                    mainSounds.playWoof();
            }

            // Event handling
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    window.close();
                    menuCounter = 4;
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

        // Window display
        window.clear();
        mainGame.draw(window);
        window.display();
        }
    }
    return 0;
}
