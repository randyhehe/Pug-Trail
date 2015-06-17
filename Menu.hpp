#ifndef MENU_H
#define MENU_H

#include <queue>
#include <fstream>
#include <sstream>

class Menu
{
	private:
		//Fonts and Texts
		sf::Font ubuntu;
		sf::Text highScore;
		sf::Text recentScore;
		unsigned recentScoreVal;
		unsigned highScoreVal;

		//Textures
		sf::Texture backgroundTexture;
		sf::Texture titleTexture;
		sf::Texture playTexture;
		sf::Texture creditsTexture;
		sf::Texture pugTexture;
		sf::Texture selectionTexture;

		//Sprites
		sf::Sprite backgroundSprite;
		sf::Sprite titleSprite;
		sf::Sprite playSprite;
		sf::Sprite creditsSprite;
		sf::Sprite pugSprite;
		sf::Sprite selectionSprite;

		//Counters
		unsigned selectionCounter;
		unsigned animationCounter;
		bool secretCounter;

		//Clock
		sf::Clock clock;

	public:
		//Constructor
		Menu();

		//Methods
		void updateHighScore();
		void updateRecentScore();
		void updateSelectionLocation();
		void updateSelectionAnimation();
		void changeHighScore(unsigned i);
		void changeRecentScore(unsigned i);
		void changeSelectionCounter(int i);
		void draw(sf::RenderWindow& w);

		//Gets
		unsigned returnHighScore();
		unsigned returnSelectionCounter();

};

Menu::Menu()
:recentScoreVal(0), selectionCounter(0), animationCounter(0)
{
	//Load ubuntu font
	ubuntu.loadFromFile("Fonts/Ubuntu-L.ttf");

	//Load title texture and sprite
	titleTexture.loadFromFile("Textures/pug_trail.png");
	titleSprite.setTexture(titleTexture);
	titleSprite.setPosition(250, 330);

	//Load background texture and sprite
	backgroundTexture.loadFromFile("Textures/grass_menu.jpg");
	backgroundSprite.setTexture(backgroundTexture);

	//Load play texture and sprite
	playTexture.loadFromFile("Textures/play.png");
	playSprite.setTexture(playTexture);
	playSprite.setPosition(303, 405);

	//Load credits texture and sprite
	creditsTexture.loadFromFile("Textures/credits.png");
	creditsSprite.setTexture(creditsTexture);
	creditsSprite.setPosition(303, 440);

	//Load pug texture and sprite
    pugTexture.loadFromFile("Textures/pugScreen.png");
    pugSprite.setTexture(pugTexture);
    pugSprite.setPosition(170, 0);

    //Load selection texture and sprite
    selectionTexture.loadFromFile("Textures/pug.png");
    selectionSprite.setTexture(selectionTexture);
    selectionSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    selectionSprite.setPosition(280, 408);

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

    //Initialize clock
    srand(time(0));
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

void Menu::updateSelectionLocation()
{
	if(selectionCounter == 0)
	{
		selectionSprite.setPosition(280, 410);
	}
	else if(selectionCounter == 1)
	{
		selectionSprite.setPosition(280, 445);
	}
}

void Menu::updateSelectionAnimation()
{
	//Normalize animation speed
    if(clock.getElapsedTime().asSeconds() > 0.10)
    {
        clock.restart();

        //Sprite movement
        animationCounter += 32;
        if(animationCounter > 64)
            animationCounter = 0;

        selectionSprite.setTextureRect(sf::IntRect(animationCounter, 0, 32, 32));
    }

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

void Menu::changeSelectionCounter(int i)
{
	if(i < 0 && selectionCounter > 0)
		selectionCounter--;
	else if(i > 0 && selectionCounter < 1)
		selectionCounter++;
}

void Menu::draw(sf::RenderWindow& w)
{
	//Draw all properties
	w.draw(backgroundSprite);
	w.draw(playSprite);
	w.draw(creditsSprite);
	w.draw(highScore);
	w.draw(recentScore);
	w.draw(pugSprite);
	w.draw(titleSprite);
	w.draw(selectionSprite);
}

unsigned Menu::returnHighScore()
{
	return highScoreVal;
}

unsigned Menu::returnSelectionCounter()
{
	return selectionCounter;
}

#endif