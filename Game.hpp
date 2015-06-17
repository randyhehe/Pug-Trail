#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "Pug.hpp"
#include "Animal.hpp"
#include "Background.hpp"

class Game
{
	private:
		//Private variables
		Pug	pug;
		Animal animal;
		Background background;
		sf::Font ubuntu;
		sf::Text score;

	public:
		//Constructor
		Game();

		//Methods
		void updateScore();
		void updateMovement();
		void reset();
		void onEat();
		void updateDirection(unsigned i);
		void draw(sf::RenderWindow& w);
		bool eatConditions();
		bool loseConditions();

		//Gets
		unsigned returnSize();
};

#endif
