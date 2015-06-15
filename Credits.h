#ifndef CREDITS_H
#define CREDITS_H

#include <vector>

#include "Background.h"

class Credits
{
	private:
		Background background;
		sf::Clock stringClock;
		sf::Clock spriteClock;
		sf::Clock exitClock;
		sf::Font ubuntu;
		sf::Texture pugTexture;
		sf::Texture exitTexture;
		sf::Sprite exitSprite;
		std::vector<std::string> vecStrings;
		std::vector<sf::Text> vecTexts;
		std::vector<sf::Sprite> vecSprites;
		unsigned counter;
		unsigned animationCounter;

	public:
		Credits();
		void updateCounter();
		void updateText();
		void updatePugMovement();
		void updateExitClock();
		void reset();
		void draw(sf::RenderWindow& w);
		float getExitClockTime();
};

Credits::Credits()
:background(Background()), counter(0), animationCounter(0)
{
	//Load ubuntu
	ubuntu.loadFromFile("Fonts/Ubuntu-L.ttf");

	//Load all texts
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

	//Load firstString
	vecStrings.push_back("This program was made with SFML 2.3 and coded with C++.");
	vecStrings.push_back("Open source code for this project can be found at \"github.com/randyhehe\".");
	vecStrings.push_back("Dedicated for Nina Dionisio and for our first year anniversary.");

	//Load pugTexture
	pugTexture.loadFromFile("Textures/pug.png");
	
	//Set up all pug sprites
	sf::Sprite tempSprite;
	tempSprite.setTexture(pugTexture);
	tempSprite.setTextureRect(sf::IntRect(0, 64, 32, 32));
	tempSprite.setPosition(50, 60);
	vecSprites.push_back(tempSprite);
	tempSprite.setPosition(50, 90);
	vecSprites.push_back(tempSprite);
	tempSprite.setPosition(50, 120);
	vecSprites.push_back(tempSprite);

	//Load exitTexture
	exitTexture.loadFromFile("Textures/exitTexture.png");

	//Load exitSprite
}

void Credits::updatePugMovement()
{
	if(spriteClock.getElapsedTime().asSeconds() > 0.12 && exitClock.getElapsedTime().asSeconds() < 11.50)
	{
		spriteClock.restart();
		
		animationCounter += 32;
		if(animationCounter > 64)
			animationCounter = 0;
		
		for(unsigned i = 0; i < vecSprites.size(); i++)
		{
			vecSprites.at(i).setTextureRect(sf::IntRect(animationCounter, 64, 32, 32));
			vecSprites.at(i).move(9, 0);
		}
	}
}

void Credits::updateCounter()
{
	if(stringClock.getElapsedTime().asSeconds() > 0.10)
    {
        stringClock.restart();
        counter++;
    }
}

void Credits::updateText()
{
	for(unsigned i = 0; i < vecTexts.size(); i++)
	{
		vecTexts.at(i).setString(vecStrings.at(i).substr(0, counter));
	}
}

void Credits::updateExitClock()
{
	if(exitClock.getElapsedTime().asSeconds() < 11.50 || spriteClock.getElapsedTime().asSeconds() < 0.12)
		return;

	spriteClock.restart();

	vecSprites.at(0).setPosition(130, 300);
	vecSprites.at(1).setPosition(570, 300);

	animationCounter += 32;
		if(animationCounter > 64)
			animationCounter = 0;

	for(int i = 0; i < 2; i++)
	{
		vecSprites.at(i).setTextureRect(sf::IntRect(animationCounter, 0, 32, 32));
	}

	exitSprite.setTexture(exitTexture);
	exitSprite.setPosition(150, 300);
}

void Credits::reset()
{
	exitClock.restart();
	stringClock.restart();
	spriteClock.restart();

	counter = 0;
	for(unsigned i = 0, j = 60; i < vecSprites.size(); i++, j += 30)
	{
		vecSprites.at(i).setPosition(50, j);
	}
}

void Credits::draw(sf::RenderWindow& w)
{
	background.draw(w);
	
	if(getExitClockTime() > 11.50)
		w.draw(exitSprite);

	for(unsigned i = 0; i < vecSprites.size(); i++)
	{
		w.draw(vecSprites.at(i));
		w.draw(vecTexts.at(i));
	}
}

float Credits::getExitClockTime()
{
	return exitClock.getElapsedTime().asSeconds();
}

#endif