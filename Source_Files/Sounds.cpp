#include "../Header_Files/Sounds.hpp"

Sounds::Sounds()
:key("")
{
	// Randomization
	srand((unsigned)time(0));

	// Set background music
	playDefault();

    // Set dog sounds
    dogWoof.loadFromFile("../Sounds/pug_woof.wav");
    dogWhine.loadFromFile("../Sounds/dog_whine.ogg");

	// Set secretMusic strings
    secretMusic.push_back("../Sounds/bad_boy.ogg");
    secretMusic.push_back("../Sounds/bang_bang_bang.ogg");
    secretMusic.push_back("../Sounds/black.ogg");
    secretMusic.push_back("../Sounds/dont_go_home.ogg");
    secretMusic.push_back("../Sounds/fantastic_baby.ogg");
    secretMusic.push_back("../Sounds/good_boy.ogg");
    secretMusic.push_back("../Sounds/haru_haru.ogg");
    secretMusic.push_back("../Sounds/lies.ogg");
    secretMusic.push_back("../Sounds/that_xx.ogg");
    secretMusic.push_back("../Sounds/we_like_2_party.ogg");

}

// Play dog woof sound.
void Sounds::playWoof()
{
	sound.setBuffer(dogWoof);
	sound.play();
}

// Play dog whine sound.
void Sounds::playWhine()
{
	sound.setBuffer(dogWhine);
	sound.play();
}

// Play default soundtrack.
void Sounds::playDefault()
{
	backgroundMusic.openFromFile("../Sounds/relaxing_music.ogg");
	backgroundMusic.play();
	backgroundCounter = 0;
}

// Play secret soundtrack.
void Sounds::playSecret()
{
	std::string randomSecret = secretMusic.at(rand() % 10);
	backgroundMusic.openFromFile(randomSecret);
	backgroundMusic.play();
	backgroundMusic.setVolume(50);
	backgroundCounter = 1;
}

// Used to continue the music once it stops.
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

// Stops the music.
void Sounds::stopMusic()
{
	backgroundMusic.stop();
}

// Mutes the music.
void Sounds::muteMusic()
{
	backgroundMusic.setVolume(0);
}

// Unmutes the music.
void Sounds::unmuteMusic()
{
	if(backgroundCounter == 0)
		backgroundMusic.setVolume(100);
	else if(backgroundCounter == 1)
		backgroundMusic.setVolume(50);
}

// Registers user input.
void Sounds::updateKey(char x)
{
	key += x;
}

// Clears the key.
void Sounds::clearKey()
{
	key = "";
}

// Return true if the user inputted "default".
bool Sounds::checkDefaultCondition()
{
	if(key == "ddeeffaauulltt")
		return true;

	return false;
}

// Return true if the user inputted "bigbang".
bool Sounds::checkSecretCondition()
{
	if(key == "bbiiggbbaanngg")
		return true;

	return false;
}

// Return true if soundtrack is muted.
bool Sounds::isMuted()
{
	if(backgroundMusic.getVolume() == 0)
		return true;

	return false;
}
