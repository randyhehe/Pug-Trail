#ifndef SOUNDS_H
#define SOUNDS_H	

#include <cstdlib>
#include <ctime>
#include <vector>

class Sounds
{
	private:
		//Private variables
		sf::Music backgroundMusic;
		sf::Music secret;
		std::vector<std::string> secretMusic;
		sf::SoundBuffer dogWoof;
		sf::SoundBuffer dogWhine;
		sf::Sound sound;

	public:
		//Constructor
		Sounds();

		//Methods
		void playWoof();
		void playWhine();
		void playBackground();
};

Sounds::Sounds()
{
	srand(time(0));

	//Set background music
	backgroundMusic.openFromFile("Sounds/relaxing_music.ogg");
    backgroundMusic.play();	

    //Set dog sounds
    dogWoof.loadFromFile("Sounds/pug_woof.wav");
    dogWhine.loadFromFile("Sounds/dog_whine.ogg");
}

void Sounds::playWoof()
{
	sound.setBuffer(dogWoof);
	sound.play();
}

void Sounds::playWhine()
{
	sound.setBuffer(dogWhine);
	sound.play();
}

void Sounds::playBackground()
{
	backgroundMusic.openFromFile("Sounds/relaxing_music.ogg");
	backgroundMusic.play();
}

#endif