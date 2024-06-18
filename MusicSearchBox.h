#pragma once
#include "SFML/Graphics.hpp"
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class MusicSearchBox
{
public:
	MusicSearchBox() {}
	MusicSearchBox(int size, sf::Color color, bool sel)
	{
		textbox.setCharacterSize(size);
		textbox.setFillColor(color);
		isSelected = sel;
		if (sel)
			textbox.setString("Press ENTER to search!");
		else
			textbox.setString("");
		
	}
	void setFont(sf::Font& font) { textbox.setFont(font); }
	
	void setPosition(sf::Vector2f pos) { textbox.setPosition(pos); }
	
	void setLimit(bool ToF) { hasLimit = ToF; }
	
	void setLimit(bool ToF, int lim);
	
	void setSelected(bool sel);
	
	std::string getText() { return text.str(); }
	
	void drawTo(sf::RenderWindow& window) { window.draw(textbox); }
	
	void typedOn(sf::Event input);
	
		
	

private:
	sf::Text textbox;
	std::ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit;

	void inputLogic(int charTyped);
	
	void deleteLastChar();
	
		
	
};

