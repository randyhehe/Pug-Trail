#ifndef GAME_H
#define GAME_H

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

Game::Game()
:pug(Pug()), animal(Animal()), background(Background())
{
	//Load Ubuntu Font
	ubuntu.loadFromFile("Fonts/Ubuntu-L.ttf");

	//Load Score Text w/ no setString
	score.setFont(ubuntu);
    score.setCharacterSize(15);
    score.setColor(sf::Color::White);
    score.setStyle(sf::Text::Bold);
    score.setPosition(0, 0);
}

void Game::updateScore()
{
	std::stringstream sSS;
    sSS << pug.getSize();
    std::string scoreString = sSS.str();

	score.setString("Pugs Captured: " + scoreString);
}

void Game::updateMovement()
{
	pug.setMovement();
}

void Game::reset()
{
	pug.reset();
}

void Game::onEat()
{
	animal.setRandomLocation();
	pug.addDog();
}

void Game::updateDirection(unsigned i)
{
	pug.setDirection(i);
}

void Game::draw(sf::RenderWindow& w)
{
	background.draw(w);
	w.draw(score);
    animal.draw(w);
    pug.draw(w);

}

bool Game::eatConditions()
{
	if(pug.eatAnimal(animal) == true)
		return true;

	return false;
}

bool Game::loseConditions()
{
	if(pug.hitBody() || pug.hitWall() == true)
		return true;

	return false;
}

unsigned Game::returnSize()
{
	return pug.getSize();
}

#endif
