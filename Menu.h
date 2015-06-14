#ifndef MENU_H
#define MENU_H

#include <fstream>
#include <sstream>

class Menu
{
	private:
		//Fonts and Texts
		sf::Font ubuntu;
		sf::Text title;
		sf::Text play;
		sf::Text credits;
		sf::Text highScore;
		sf::Text recentScore;
		unsigned recentScoreVal;
		unsigned highScoreVal;

		//Graphics
		sf::Texture pugTexture;
		sf::Sprite 	pugSprite;

	public:
		//Constructor
		Menu();

		//Methods
		void updateHighScore();
		void updateRecentScore();
		void changeHighScore(unsigned i);
		void changeRecentScore(unsigned i);
		void draw(sf::RenderWindow& w);
		
		//Gets
		unsigned returnHighScore();

};

Menu::Menu()
:recentScoreVal(0)
{
	//Load ubuntu font
	ubuntu.loadFromFile("Fonts/Ubuntu-L.ttf");

	//Load title text
	title.setFont(ubuntu);
    title.setString("Pug Trail");
    title.setCharacterSize(48);
    title.setColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);
    title.setPosition(300, 350);

    //Load play text
    play.setFont(ubuntu);
    play.setString("Press P to Play");
    play.setCharacterSize(24);
    play.setColor(sf::Color::Black);
    play.setPosition(303, 405);

    //Load credit text
    credits.setFont(ubuntu);
    credits.setString("Press C for Credits");
    credits.setCharacterSize(24);
    credits.setColor(sf::Color::Black);
    credits.setPosition(303, 428);

    //Load high score text
    highScore.setFont(ubuntu);
    highScore.setCharacterSize(15);
    highScore.setColor(sf::Color::Black);
    highScore.setStyle(sf::Text::Bold);
    highScore.setPosition(0, 0);

    //Load recent score text
    recentScore.setFont(ubuntu);
    recentScore.setCharacterSize(15);
    recentScore.setColor(sf::Color::Black);
    recentScore.setStyle(sf::Text::Bold);
    recentScore.move(0, 20);

    //Load high score value
    std::ifstream iSS;
    iSS.open("scores.txt");
    iSS >> highScoreVal;
    iSS.close();

    //Load pug texture
    pugTexture.loadFromFile("Textures/pugScreen.png");
    
    //Load pug sprite
    pugSprite.setTexture(pugTexture);
    pugSprite.setPosition(170, 0);
}

void Menu::updateHighScore()
{
	std::stringstream sSS;
	sSS << highScoreVal;
	std::string highScoreString = sSS.str();

	highScore.setString("Most Pugs Captured: " + highScoreString);
}

void Menu::updateRecentScore()
{
	std::stringstream sSS;
	sSS << recentScoreVal;
	std::string recentScoreString = sSS.str();

	recentScore.setString("Latest Capture: " + recentScoreString);
}

void Menu::changeHighScore(unsigned i)
{
	std::ofstream oSS;
    oSS.open("scores.txt");
    oSS << i;
    oSS.close();
    
    //Update High Score Variable
    highScoreVal = i;
}

void Menu::changeRecentScore(unsigned i)
{
	recentScoreVal = i;
}

void Menu::draw(sf::RenderWindow& w)
{
	//Draw all properties
	w.draw(title);
	w.draw(play);
	w.draw(credits);
	w.draw(highScore);
	w.draw(recentScore);
	w.draw(pugSprite);
}

unsigned Menu::returnHighScore()
{
	return highScoreVal;
}

#endif