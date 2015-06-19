all:
	g++ main.cpp Sounds.cpp Credits.cpp Background.cpp Animal.cpp Pug.cpp Game.cpp Menu.cpp Message.cpp MessageAnimation.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
