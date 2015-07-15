#ifndef CREDITS_H
#define CREDITS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <vector>

#include "Background.hpp"

class Credits
{
	private:
		// Private variables
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

		// Counters
		unsigned textCounter;
		unsigned animationCounter;

	public:
		// Constructor
		Credits();

		// Methods
		void updateTextCounter();
		void updateText();
		void updatePugMovement();
		void updateExitClock();
		void reset();
		void draw(sf::RenderWindow& w);

		// Gets
		float returnExitClockTime();
};

#endif
