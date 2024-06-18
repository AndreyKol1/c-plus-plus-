#include "BaseButton.h"



bool BaseButton::isMouseOverRec(sf::RenderWindow& window, sf::RectangleShape button)
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

bool BaseButton::isMouseOverCirc(sf::RenderWindow& window, sf::CircleShape button)
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
