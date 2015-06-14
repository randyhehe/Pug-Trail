#ifndef SOUNDS_H
#define SOUNDS_H	

class Sounds
{
	private:
		//Private variables
		sf::Music backgroundMusic;
		sf::SoundBuffer dogWoof;
		sf::SoundBuffer dogWhine;
		sf::Sound sound;

	public:
		//Constructor
		Sounds();

		//Methods
		void playWoof();
		void playWhine();
};

Sounds::Sounds()
{
	//Set Background Music
	backgroundMusic.openFromFile("Sounds/relaxing_music.ogg");
    backgroundMusic.play();

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

#endif