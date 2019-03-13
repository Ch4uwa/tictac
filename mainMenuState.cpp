//
// Created by martin on 2019-03-13.
//

#include <sstream>
#include "Defines.hpp"
#include "mainMenuState.hpp"

#include <iostream>

namespace Chauwa
{
    MainMenuState::MainMenuState(GameDataRef &data)
            : _data(data)
    {

    }
    void MainMenuState::init()
    {
        this->_data->assets.loadTexture("Background", MAIN_MENU_BACKGROUND_PATH);
        this->_data->assets.loadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
        this->_data->assets.loadTexture("Play Button Outer", MAIN_MENU_PLAY_BUTTON_OUTER);
        this->_data->assets.loadTexture("Game Title", MAIN_MENU_TITLE_PATH);

        this->_background.setTexture(this->_data->assets.getTexture("Background"));
        this->_playButton.setTexture(this->_data->assets.getTexture("Play Button"));
        this->_playButtonOuter.setTexture(this->_data->assets.getTexture("Play Button Outer"));
        this->_title.setTexture(this->_data->assets.getTexture("Game Title"));

        this->_playButton.setPosition(sf::Vector2f(
                SCREEN_WIDTH / 2.f - (this->_playButton.getGlobalBounds().width / 2),
                SCREEN_HEIGHT / 2.f - (this->_playButton.getGlobalBounds().height / 2)));
        this->_playButtonOuter.setPosition(sf::Vector2f(
                SCREEN_WIDTH / 2.f - (this->_playButtonOuter.getGlobalBounds().width / 2),
                SCREEN_HEIGHT / 2.f - (this->_playButtonOuter.getGlobalBounds().height / 2)));

        this->_title.setPosition(sf::Vector2f(
                SCREEN_WIDTH / 2.f - (this->_title.getGlobalBounds().width / 2),
                SCREEN_HEIGHT / 2.f - (this->_title.getGlobalBounds().height * 0.1f)));
    }
    void MainMenuState::handleInput()
    {
        sf::Event event{};

        while (this->_data->window.pollEvent(event))
        {
            
        }
    }
    void MainMenuState::update(float dt)
    {

    }
    void MainMenuState::draw(float dt)
    {

    }
}