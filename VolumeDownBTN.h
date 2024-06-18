#pragma once
#include <SFML/Graphics.hpp>
#include "BaseButton.h"


class VolumeDownBTN : public BaseButton
{
private:
	sf::CircleShape button;
public:
	VolumeDownBTN() {}
	VolumeDownBTN(int radius, sf::Color bgC)
	{
		button.setRadius(radius);
		button.setFillColor(bgC);
	}
	
	void SetBackColor(sf::Color color) { button.setFillColor(color); }

	void SetPosition(sf::Vector2f pos) { button.setPosition(pos); };

	void drawTo(sf::RenderWindow& window) { window.draw(button); };

	void SetRadius(int val) { button.setRadius(val); };

	bool isMouseOver(sf::RenderWindow& window) { return BaseButton::isMouseOverCirc(window, button); };
};

