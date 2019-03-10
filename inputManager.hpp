/*
 * Created by MartinK on 2019-03-10.
 */

#ifndef STUFFTHING_INPUTMANAGER_HPP
#define STUFFTHING_INPUTMANAGER_HPP

#include <SFML/Graphics.hpp>

namespace Chauwa
{

    class InputManager
    {
    public:
        InputManager(){}
        ~InputManager(){}

        bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button,
                sf::RenderWindow& window);

        sf::Vector2i getMousePosition(sf::RenderWindow& window);
    };
}

#endif //STUFFTHING_INPUTMANAGER_HPP
