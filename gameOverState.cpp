//
// Created by martin on 2019-03-15.
//
#include <sstream>
#include "gameOverState.hpp"
#include "gameState.hpp"
#include "mainMenuState.hpp"


namespace Chauwa
{
    GameOverState::GameOverState(GameDataRef &data)
            : _data(data)
    {
        LOG("GameOverState CTOR");
    }

    GameOverState::~GameOverState()
    {
        LOG("GameOverState DTOR");
    }

    void GameOverState::init()
    {
        this->_data->assets.loadTexture("Retry Button", RETRY_BUTTON);
        this->_data->assets.loadTexture("Home Button", HOME_BUTTON);

        this->_retryButton.setTexture(this->_data->assets.getTexture("Retry Button"));
        this->_homeButton.setTexture(this->_data->assets.getTexture("Home Button"));

        this->_retryButton.setPosition(
                (this->_data->window.getSize().x / 2.f) -
                (this->_retryButton.getLocalBounds().width / 2.f),
                (this->_data->window.getSize().y / 3.f) -
                (this->_retryButton.getLocalBounds().height / 2.f));

        this->_homeButton.setPosition(
                (this->_data->window.getSize().x / 2.f) -
                (this->_homeButton.getLocalBounds().width / 2.f),
                this->_data->window.getSize().y / 3.f * 2 -
                (this->_homeButton.getLocalBounds().height / 2.f));
    }

    void GameOverState::handleInput()
    {
        sf::Event event{};

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            if (this->_data->input.isSpriteClicked(
                    this->_retryButton, sf::Mouse::Left,
                    this->_data->window))
            {
                this->_data->machine.addState(stateRef(new GameState(_data)), true);
            }
            if (this->_data->input.isSpriteClicked(
                    this->_homeButton, sf::Mouse::Left,
                    this->_data->window))
            {
                this->_data->machine.addState(stateRef(new MainMenuState(_data)), true);
            }
        }

    }

    void GameOverState::update(float dt)
    {

    }

    void GameOverState::draw(float dt)
    {
        this->_data->window.clear(sf::Color::Red);

        this->_data->window.draw(this->_retryButton);
        this->_data->window.draw(this->_homeButton);

        this->_data->window.display();
    }

}