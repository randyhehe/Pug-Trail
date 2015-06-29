#include "../Header_Files/Message.hpp"

Message::Message()
:key("")
{
    //Set up vecStrings
    vecStrings.push_back("To my love:");
    vecStrings.push_back("Hi my princess! Thank you so much for giving me the chance to be a part of your life.");
    vecStrings.push_back("This past year has been incredible for me and I don't regret it a single bit. I can't");
    vecStrings.push_back("believe that it's only been a year. I can still vividly remember each and every single");
    vecStrings.push_back("day I had with you and all the adventures we had together. I will forever hold these");
    vecStrings.push_back("special memories close to me. Thank you for being patient with me every step of the way");
    vecStrings.push_back("and showing me how great a relationship with you could be. I'm so grateful to have found");
    vecStrings.push_back("someone that loves and cares for me so much. Now I know everything that I missed out");
    vecStrings.push_back("on. There's just something so unique about growing with someone and knowing they will ");
    vecStrings.push_back("support you every inch of the way. Thank you for that, and I hope I make you feel the");
    vecStrings.push_back("same way. I can't wait to see what unfolds for us in the future. I am very excited for");
    vecStrings.push_back("us and I know that even more amazing things are waiting for us. Happy anniversary!!");
    vecStrings.push_back("                                                                                  With love, your Pug Prince");
    vecStrings.push_back("                                                                                  (Press Enter to Return to the Menu)");

    //Set up ubuntu font
    ubuntu.loadFromFile("../Fonts/Ubuntu-L.ttf");

    //Load text properties
    sf::Text tempText;
	tempText.setFont(ubuntu);
    tempText.setCharacterSize(15);
	tempText.setColor(sf::Color::Black);
	tempText.setStyle(sf::Text::Bold);
    tempText.setPosition(50, 70);
	vecTexts.push_back(tempText);
	tempText.setPosition(50, 100);
	vecTexts.push_back(tempText);
    tempText.setPosition(50, 130);
	vecTexts.push_back(tempText);
    tempText.setPosition(50, 160);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 190);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 220);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 250);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 280);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 310);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 340);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 370);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 400);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 450);
    vecTexts.push_back(tempText);
    tempText.setPosition(50, 470);
    vecTexts.push_back(tempText);

    //Load messageAnimations top
    MessageAnimation temp;
    temp.changeDirection(2);
    temp.setPosition(40, 5);
    messageAnimations.push_back(temp);
    temp.setPosition(140, 5);
    messageAnimations.push_back(temp);
    temp.setPosition(240, 5);
    messageAnimations.push_back(temp);
    temp.setPosition(340, 5);
    messageAnimations.push_back(temp);
    temp.setPosition(440, 5);
    messageAnimations.push_back(temp);
    temp.setPosition(540, 5);
    messageAnimations.push_back(temp);
    temp.setPosition(640, 5);
    messageAnimations.push_back(temp);
    // temp.setPosition(740, 5);
    // messageAnimations.push_back(temp);

    //Load messageAnimations bottom
    temp.changeDirection(0);
    temp.setPosition(740, 540);
    messageAnimations.push_back(temp);
    temp.setPosition(640, 540);
    messageAnimations.push_back(temp);
    temp.setPosition(540, 540);
    messageAnimations.push_back(temp);
    temp.setPosition(440, 540);
    messageAnimations.push_back(temp);
    temp.setPosition(340, 540);
    messageAnimations.push_back(temp);
    temp.setPosition(240, 540);
    messageAnimations.push_back(temp);
    temp.setPosition(140, 540);
    messageAnimations.push_back(temp);
    temp.setPosition(40, 540);
    messageAnimations.push_back(temp);


    //Load messageAnimations right
    temp.changeDirection(3);
    temp.setPosition(744, 30);
    messageAnimations.push_back(temp);
    temp.setPosition(744, 150);
    messageAnimations.push_back(temp);
    temp.setPosition(744, 250);
    messageAnimations.push_back(temp);
    temp.setPosition(744, 350);
    messageAnimations.push_back(temp);
    temp.setPosition(744, 450);
    messageAnimations.push_back(temp);

    //Load messageAnimations left
    temp.changeDirection(1);
    temp.setPosition(5, 450);
    messageAnimations.push_back(temp);
    temp.setPosition(5, 350);
    messageAnimations.push_back(temp);
    temp.setPosition(5, 250);
    messageAnimations.push_back(temp);
    temp.setPosition(5, 150);
    messageAnimations.push_back(temp);
    temp.setPosition(5, 50);
    messageAnimations.push_back(temp);

}

//Updates the textCounter based on textClock.
void Message::updateTextCounter()
{
	if(textClock.getElapsedTime().asSeconds() < 0.10)
		return;
	textClock.restart();

	textCounter++;
}

//Updates the text of all lines based on textCounter.
void Message::updateText()
{
    for(unsigned i = 0; i < vecStrings.size(); i++)
    {
        if(vecStrings.at(i).substr(0, textCounter) != vecStrings.at(i))
            vecTexts.at(i).setString(vecStrings.at(i).substr(0, textCounter + 1));
    }
}

//Resets the textCounter.
void Message::resetTextCounter()
{
    textCounter = 0;
}

//Updates the messageAnimations movement and direction.
void Message::updateMessageAnimations()
{
    for(unsigned i = 0; i < messageAnimations.size(); i++)
    {
        messageAnimations.at(i).updateMovement();
        messageAnimations.at(i).updateTouchCorner();
    }
}

//Registers the keys pressed by the user.
void Message::updateKey(char x)
{
    key += x;
}

//Clears the key.
void Message::clearKey()
{
    key = "";
}

//Draw all properties.
void Message::draw(sf::RenderWindow& w)
{
    background.draw(w);

    for(unsigned i = 0; i < messageAnimations.size(); i++)
        messageAnimations.at(i).draw(w);

    for(unsigned i = 0; i < vecTexts.size(); i++)
        w.draw(vecTexts.at(i));
}

//If the key is correct, return true.
bool Message::correctKey()
{
    if(key == "006633001144")
        return true;

    return false;
}
