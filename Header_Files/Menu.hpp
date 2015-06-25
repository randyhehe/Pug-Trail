#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

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
		sf::Texture soundTexture;
		sf::Texture mutedsoundTexture;
		sf::Texture clickTexture;

		//Sprites
		sf::Sprite backgroundSprite;
		sf::Sprite titleSprite;
		sf::Sprite playSprite;
		sf::Sprite creditsSprite;
		sf::Sprite pugSprite;
		sf::Sprite selectionSprite;
		sf::Sprite soundSprite;
		sf::Sprite clickSprite;

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
		void setClickSpritePosition(int x, int y);
		void resetClickSpriteLocation();
		bool clicksoundCollison();
		void switchSoundIcon(bool b);

		//Gets
		unsigned returnHighScore();
		unsigned returnSelectionCounter();

};

#endif
