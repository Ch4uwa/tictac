#include <utility>

/*
 * Created by MartinK on 2019-03-11.
 */
#include <sstream>
#include "splashState.hpp"

#include "Defines.hpp"
#include "mainMenuState.hpp"

namespace Chauwa
{

    SplashState::SplashState(GameDataRef &data)
            : _data(data)
    {
        LOG("SplashState ctor");
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
            this->_data->machine.addState(stateRef(new MainMenuState(_data)), true);
        }
    }
    void SplashState::draw(float dt)
    {
        this->_data->window.clear();
        this->_data->window.draw(this->_background);
        this->_data->window.display();
    }
    SplashState::~SplashState()
    {
        LOG("SplashState dtor");
    }
}