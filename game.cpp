/*
 * Created by MartinK on 2019-03-11.
 */

#include "game.hpp"
#include "splashState.hpp"

namespace Chauwa
{
    Game::Game(unsigned int width, unsigned int height, std::string title)
    {
        LOG("Game ctor");
        _data->window.create(sf::VideoMode(width, height),
                             title, sf::Style::Close | sf::Style::Titlebar);
        _data->machine.addState(stateRef(new SplashState(this->_data)));

        this->run();
    }

    void Game::run()
    {
        float newTime, frameTime, interpolation;

        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (this->_data->window.isOpen())
        {
            this->_data->machine.processStateChanges();

            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if (frameTime > 0.25f)
            {
                frameTime = 0.25f;
            }

            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= dt)
            {
                this->_data->machine.getActiveState()->handleInput();
                this->_data->machine.getActiveState()->update(dt);

                accumulator -= dt;
            }

            interpolation = accumulator / dt;
            this->_data->machine.getActiveState()->draw(interpolation);
        }
    }
    Game::~Game()
    {
        LOG("Game dtor");
    }

}