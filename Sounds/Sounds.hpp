#ifndef SOUNDS_H
#define SOUNDS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <cstdlib>
#include <ctime>
#include <vector>

class Sounds
{
	private:
		//Private variables
		sf::Clock clock;
		sf::Music backgroundMusic;
		sf::SoundBuffer dogWoof;
		sf::SoundBuffer dogWhine;
		sf::Sound sound;

		//Counters
		unsigned backgroundCounter;

		//Secret variables
		std::vector<std::string> secretMusic;
		std::string key;

	public:
		//Constructor
		Sounds();

		//Methods
		void playWoof();
		void playWhine();
		void playDefault();
		void playSecret();
		void continueMusic();
		void stopMusic();
		void muteMusic();
		void unmuteMusic();
		void updateKey(char x);
		void clearKey();
		bool checkSecretCondition();
		bool checkDefaultCondition();
		bool isMuted();

};

#endif
