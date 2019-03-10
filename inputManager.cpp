/*
 * Created by MartinK on 2019-03-10.
 */

#include "inputManager.hpp"

namespace Chauwa
{
    bool InputManager::isSpriteClicked(
            sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
    {
        if (sf::Mouse::isButtonPressed(button))
        {
            sf::IntRect playRect(object.getPosition().x,
                                 object.getPosition().y,
                                 object.getGlobalBounds().width, object.getGlobalBounds().height);
            if (playRect.contains(sf::Mouse::getPosition(window)))
            {
                return true;
            }
        }
        return false;
    }
    sf::Vector2i InputManager::getMousePosition(sf::RenderWindow &window)
    {
        return sf::Mouse::getPosition(window);
    }
}