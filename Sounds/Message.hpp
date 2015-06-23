#ifndef MESSAGE_H
#define MESSAGE_H

#include "Background.hpp"
#include "MessageAnimation.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <vector>

class Message
{
    private:
        Background background;
        std::string key;
        std::vector<std::string> vecStrings;
        sf::Font ubuntu;
        std::vector<sf::Text> vecTexts;
        sf::Clock textClock;
        unsigned textCounter;
        unsigned lineCounter;
        std::vector<MessageAnimation> messageAnimations;

    public:
        Message();
        void updateKey(char x);
        void clearKey();
        void updateText();
        void updateTextCounter();
        void resetTextCounter();
        void updateMessageAnimations();
        void draw(sf::RenderWindow& w);
        bool correctKey();
};

#endif
