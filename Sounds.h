#ifndef SOUNDS_H
#define SOUNDS_H	

#include <cstdlib>
#include <ctime>
#include <vector>

class Sounds
{
	private:
		//Private variables
		sf::Clock clock;
		sf::Music backgroundMusic;
		std::vector<std::string> secretMusic;
		sf::SoundBuffer dogWoof;
		sf::SoundBuffer dogWhine;
		sf::Sound sound;

		std::string key;

		unsigned backgroundCounter;

	public:
		//Constructor
		Sounds();

		//Methods
		void playWoof();
		void playWhine();
		void playDefault();
		void stop();
		void playSecret();
		void updateKey(char x);
		void clearKey();
		void continueMusic();
		bool checkSecretCondition();
		bool checkDefaultCondition();
		
};

Sounds::Sounds()
:key("")
{
	//Randomization
	srand(time(0));

	//Set background music
	playDefault();

    //Set dog sounds
    dogWoof.loadFromFile("Sounds/pug_woof.wav");
    dogWhine.loadFromFile("Sounds/dog_whine.ogg");

    secretMusic.push_back("Sounds/bad_boy.ogg");
    secretMusic.push_back("Sounds/bang_bang_bang.ogg");
    secretMusic.push_back("Sounds/black.ogg");
    secretMusic.push_back("Sounds/dont_go_home.ogg");
    secretMusic.push_back("Sounds/fantastic_baby.ogg");
    secretMusic.push_back("Sounds/good_boy.ogg");
    secretMusic.push_back("Sounds/haru_haru.ogg");
    secretMusic.push_back("Sounds/lies.ogg");
    secretMusic.push_back("Sounds/that_xx.ogg");
    secretMusic.push_back("Sounds/we_like_2_party.ogg");

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

void Sounds::playDefault()
{
	backgroundMusic.openFromFile("Sounds/relaxing_music.ogg");
	backgroundMusic.play();
	backgroundCounter = 0;
}

void Sounds::stop()
{
	backgroundMusic.stop();
}

void Sounds::playSecret()
{
	std::string randomSecret = secretMusic.at(rand() % 10);
	backgroundMusic.openFromFile(randomSecret);
	backgroundMusic.play();
	backgroundMusic.setVolume(50);
	backgroundCounter = 1;
}

void Sounds::updateKey(char x)
{
	key += x;
}

void Sounds::clearKey()
{
	key = "";
}

bool Sounds::checkDefaultCondition()
{
	if(key == "ddeeffaauulltt")
		return true;
	return false;
}

bool Sounds::checkSecretCondition()
{
	if(key == "bbiiggbbaanngg")
		return true;
	return false;
}

void Sounds::continueMusic()
{
	if(backgroundMusic.getStatus() == sf::SoundSource::Stopped)
	{
		if(backgroundCounter == 0)
			playDefault();
		else if(backgroundCounter == 1)
			playSecret();
	}
}

#endif