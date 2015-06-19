#include "Menu.hpp"

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

	//Load sound texture and sprite
	soundTexture.loadFromFile("Textures/sound.png");
	soundSprite.setTexture(soundTexture);
	soundSprite.setPosition(740, 550);

	//Load muted sound texture
	mutedsoundTexture.loadFromFile("Textures/soundmute.png");

	//Load click texture and sprite
	clickTexture.loadFromFile("Textures/starcraft.png");
	clickSprite.setTexture(clickTexture);
	clickSprite.setTextureRect(sf::IntRect(0, 0, 1, 1));

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

//Checks for the highest score and updates it.
void Menu::updateHighScore()
{
	std::stringstream sSS;
	sSS << highScoreVal;
	std::string highScoreString = sSS.str();

	highScore.setString("Most Pugs Captured: " + highScoreString);
}

//Checks for the recent score and updates it.
void Menu::updateRecentScore()
{
	std::stringstream sSS;
	sSS << recentScoreVal;
	std::string recentScoreString = sSS.str();

	recentScore.setString("Latest Capture: " + recentScoreString);
}

//Updates the Sprite position based of selectionCunter.
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

//Updates the Sprite animaation based on animationCounter.
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

//Opens the scores.txt file and writes into it the high score.
void Menu::changeHighScore(unsigned i)
{
	std::ofstream oSS;
    oSS.open("scores.txt");
    oSS << i;
    oSS.close();

    //Update High Score Variable
    highScoreVal = i;
}

//Changes the recentscoreVal to i.
void Menu::changeRecentScore(unsigned i)
{
	recentScoreVal = i;
}

//Changes the selectionCounter based on the integer i.
void Menu::changeSelectionCounter(int i)
{
	if(i < 0 && selectionCounter > 0)
		selectionCounter--;
	else if(i > 0 && selectionCounter < 1)
		selectionCounter++;
}

//Draw all properties.
void Menu::draw(sf::RenderWindow& w)
{
	w.draw(backgroundSprite);
	w.draw(playSprite);
	w.draw(creditsSprite);
	w.draw(highScore);
	w.draw(recentScore);
	w.draw(pugSprite);
	w.draw(titleSprite);
	w.draw(selectionSprite);
	w.draw(clickSprite);
	w.draw(soundSprite);
}

//Manages the location of the user's cursor when clicked.
void Menu::setClickSpritePosition(int x, int y)
{
	clickSprite.setPosition(x, y);
}

//Resets the location of the last click's sprite.
void Menu::resetClickSpriteLocation()
{
	clickSprite.setPosition(0, 0);
}

//Manages the texture of the sound icon based on mute/unmute.
void Menu::switchSoundIcon(bool b)
{
	if (b == true)
	{
		soundSprite.setTexture(soundTexture);
	}
	if (b == false)
	{
		soundSprite.setTexture(mutedsoundTexture);
	}
}

//Returns true if user clicks on the sound icon.
bool Menu::clicksoundCollison()
{
	sf::FloatRect soundBox = soundSprite.getGlobalBounds();
	sf::FloatRect clickBox = clickSprite.getGlobalBounds();

	if(soundBox.intersects(clickBox))
		return true;

	return false;
}

//Returns the high score.
unsigned Menu::returnHighScore()
{
	return highScoreVal;
}

//Returns the selectionCounter;
unsigned Menu::returnSelectionCounter()
{
	return selectionCounter;
}
