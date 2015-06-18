#include "Credits.hpp"

Credits::Credits()
:background(Background()), textCounter(0), animationCounter(0)
{
	//Load ubuntu
	ubuntu.loadFromFile("Fonts/Ubuntu-L.ttf");

	//Load all texts and set their positions
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

	//Load all string contents
	vecStrings.push_back("This program was made with SFML 2.3 and coded with C++.");
	vecStrings.push_back("Open source code for this project can be found at \"github.com/randyhehe\".");
	vecStrings.push_back("Dedicated for Nina Dionisio and for our first year anniversary.");

	//Load pugTexture
	pugTexture.loadFromFile("Textures/pug.png");

	//Set up all pug sprites and their positions
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
}

void Credits::updatePugMovement()
{
	//Normalize animation speed
	if(spriteClock.getElapsedTime().asSeconds() < 0.12 || exitClock.getElapsedTime().asSeconds() > 11.50)
		return;
	spriteClock.restart();

	//update animation counter
	animationCounter += 32;
	if(animationCounter > 64)
		animationCounter = 0;

	//update all sprites distance and animation
	for(unsigned i = 0; i < vecSprites.size(); i++)
	{
		vecSprites.at(i).setTextureRect(sf::IntRect(animationCounter, 64, 32, 32));
		vecSprites.at(i).move(9, 0);
	}
}

void Credits::updateTextCounter()
{
	if(stringClock.getElapsedTime().asSeconds() < 0.10)
		return;
	stringClock.restart();

	textCounter++;
}

void Credits::updateText()
{
	for(unsigned i = 0; i < vecTexts.size(); i++)
		vecTexts.at(i).setString(vecStrings.at(i).substr(0, textCounter));
}

void Credits::updateExitClock()
{
	//Set the time when exit option is available
	if(exitClock.getElapsedTime().asSeconds() < 11.50 || spriteClock.getElapsedTime().asSeconds() < 0.12)
		return;
	spriteClock.restart();

	//Set the position of two previous sprites to be next to the text
	vecSprites.at(0).setPosition(130, 300);
	vecSprites.at(1).setPosition(570, 300);

	//Normalize animation speed for the sprites
	animationCounter += 32;
		if(animationCounter > 64)
			animationCounter = 0;

	for(int i = 0; i < 2; i++)
	{
		vecSprites.at(i).setTextureRect(sf::IntRect(animationCounter, 0, 32, 32));
	}

	//Set the exit sprite
	exitSprite.setTexture(exitTexture);
	exitSprite.setPosition(150, 300);
}

void Credits::reset()
{
	//Reset all clocks
	exitClock.restart();
	stringClock.restart();
	spriteClock.restart();

	//Reset text counter
	textCounter = 0;

	//Reset positions of sprites
	for(unsigned i = 0, j = 60; i < vecSprites.size(); i++, j += 30)
	{
		vecSprites.at(i).setPosition(50, j);
	}
}

void Credits::draw(sf::RenderWindow& w)
{
	//Draw background
	background.draw(w);

	//Draw exit
	if(returnExitClockTime() > 11.50)
		w.draw(exitSprite);

	//Draw sprites and text
	for(unsigned i = 0; i < vecSprites.size(); i++)
	{
		w.draw(vecSprites.at(i));
		w.draw(vecTexts.at(i));
	}
}

float Credits::returnExitClockTime()
{
	return exitClock.getElapsedTime().asSeconds();
}
