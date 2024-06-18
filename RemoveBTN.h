#pragma once
#include <SFML/Graphics.hpp>
#include "BaseButton.h"
class RemoveBTN : public BaseButton
{
private:
	sf::RectangleShape button;
public:
	RemoveBTN() {}
	RemoveBTN(sf::Vector2f size, sf::Color bgC)
	{
		button.setSize(size);
		button.setFillColor(bgC);
	}

	void SetBackColor(sf::Color color) { button.setFillColor(color); }

	void SetPosition(sf::Vector2f pos) { button.setPosition(pos); };

	void drawTo(sf::RenderWindow& window) { window.draw(button); };

	bool isMouseOver(sf::RenderWindow& window) { return BaseButton::isMouseOverRec(window, button); };
};

