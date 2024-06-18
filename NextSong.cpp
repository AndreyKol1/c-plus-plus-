#include "NextSong.h"

void NextSong::SetPosition(sf::Vector2f pos)
{
	
}

void NextSong::drawTo(sf::RenderWindow& window)
{
	
}

bool NextSong::isMouseOver(sf::RenderWindow& window)
{
	float mouseX = sf::Mouse::getPosition(window).x;
	float mouseY = sf::Mouse::getPosition(window).y;

	float btnPosX = button.getPosition().x;
	float btnPosY = button.getPosition().y;

	float btnPosWidth = button.getPosition().x + button.getLocalBounds().width;
	float btnPosHeight = button.getPosition().y + button.getLocalBounds().height;

	if (mouseX < btnPosWidth && mouseX > btnPosX && mouseY < btnPosHeight && mouseY > btnPosY)
		return true;
	else
		return false;
}
