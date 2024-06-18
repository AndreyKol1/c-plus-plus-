#pragma once
#include <SFML/Graphics.hpp>
class BaseButton
{
public:
	bool isMouseOverRec(sf::RenderWindow& window, sf::RectangleShape button);
	bool isMouseOverCirc(sf::RenderWindow& window, sf::CircleShape button);
};

