#include <utility>

/*
 * Created by MartinK on 2019-03-11.
 */
#include <sstream>
#include "splashState.hpp"

#include "Defines.hpp"

namespace Chauwa
{

    SplashState::SplashState(GameDataRef data)
            : _data(std::move(data))
    {

    }
    void SplashState::init()
    {
        this->_data->assets.loadTexture("Splash State Background",
                                        SPLASH_SCENE_BACKGROUND_PATH);

        _background.setTexture(this->_data->assets.getTexture("Splash State Background"));
    }
    void SplashState::handleInput()
    {
        sf::Event event{};
        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
        }
    }
    void SplashState::update(float dt)
    {
        if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            std::cout << "Go to Main Menu\n";
        }
    }
    void SplashState::draw(float dt)
    {
        this->_data->window.clear(sf::Color::Red);
        this->_data->window.draw(this->_background);
        this->_data->window.display();
    }
}