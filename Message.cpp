#include "Message.hpp"

Message::Message()
:key("")
{
    //Set up vecStrings
    vecStrings.push_back("To my love:");
    vecStrings.push_back("Hi my princess! Thank you so much for giving me the chance to be a part of your life.");
    vecStrings.push_back("This past year has been incredible for me and I don't regret it a single bit. I can't");
    vecStrings.push_back("believe that it's only been a year. I can still vividly remember each and every single");
    vecStrings.push_back("day I had with you and all the adventures we had together. I will forever hold these");
    vecStrings.push_back("special memories close to me. Thank you for being patient with me every step of the way");
    vecStrings.push_back("and showing me how great a relationship with you could be. I'm so grateful to have found");
    vecStrings.push_back("someone that loves and cares for me so much. Now I know everything that I missed out");
    vecStrings.push_back("on. There's just something so unique about growing with someone and knowing they will ");
    vecStrings.push_back("support you every inch of the way. Thank you for that, and I hope I make you feel the");
    vecStrings.push_back("same way. I can't wait to see what unfolds for us in the future. I am very excited for");
    vecStrings.push_back("us and I know that even more amazing things are waiting for us. Happy anniversary!!");
    vecStrings.push_back("With love, your Pug Prince");

    //Set up ubuntu font
    ubuntu.loadFromFile("Fonts/Ubuntu-L.ttf");

    //Load text properties
    sf::Text tempText;
	tempText.setFont(ubuntu);
	tempText.setCharacterSize(15);
	tempText.setColor(sf::Color::Black);
	tempText.setStyle(sf::Text::Bold);
    tempText.setPosition(50, 70);
	vecTexts.push_back(tempText);
	tempText.setPosition(50, 100);
	vecTexts.push_back(tempText);
	tempText.setPosition(50, 130);
	vecTexts.push_back(tempText);
    tempText.setPosition(50, 190);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 220);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 250);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 280);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 310);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 340);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 370);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 400);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 430);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 460);
    vecTexts.push_back(tempText);
}

void Message::updateText()
{

}

void Message::updateKey(char x)
{
    key += x;
}

void Message::clearKey()
{
    key = "";
}

void Message::draw(sf::RenderWindow& w)
{
    background.draw(w);
}

bool Message::correctKey()
{
    if(key == "006633001144")
        return true;

    return false;
}
