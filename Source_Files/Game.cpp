#include "../Header_Files/Game.hpp"

Game::Game()
:pug(Pug()), animal(Animal()), background(Background())
{
	//Load Ubuntu Font
	ubuntu.loadFromFile("../Fonts/Ubuntu-L.ttf");

	//Load Score Text w/ no setString
    score.setFont(ubuntu);
    score.setCharacterSize(15);
    score.setColor(sf::Color::White);
    score.setStyle(sf::Text::Bold);
    score.setPosition(0, 0);
}

//Updates the score and sets the score while in game.
void Game::updateScore()
{
	std::stringstream sSS;
    sSS << pug.getSize();
    std::string scoreString = sSS.str();

	score.setString("Pugs Captured: " + scoreString);
}

//Updates the movement of the mainPug.
void Game::updateMovement()
{
	pug.setMovement();
}

//Resets the game.
void Game::reset()
{
	pug.reset();
}

//Used for when the mainPug hits a stray piece. Adds the piece into its vector and sets a new location for the animal.
void Game::onEat()
{
	animal.setRandomLocation();
	pug.addDog();
}

//Changes the location of the animal to a random area.
void Game::changeLocation()
{
	animal.setRandomLocation();
}

//Updates the direction of the mainPug.
void Game::updateDirection(unsigned i)
{
	pug.setDirection(i);
}

//Draw all properties.
void Game::draw(sf::RenderWindow& w)
{
	background.draw(w);
	w.draw(score);
    animal.draw(w);
    pug.draw(w);
}

//Return true when pug touches a stray piece.
bool Game::eatConditions()
{
	if(pug.eatAnimal(animal) == true)
		return true;

	return false;
}

//Return true when pug hits a wall or hits its own body.
bool Game::loseConditions()
{
	if(pug.hitBody() || pug.hitWall() == true)
		return true;

	return false;
}

//Returns true if animal has same location as the body of the pugs, excluding the mainPug.
bool Game::spawnOnBody()
{
	if(pug.spawnOnBody(animal) == true)
		return true;

	return false;
}

//Returns the size of pug's body.
unsigned Game::returnSize()
{
	return pug.getSize();
}
