//
// Created by martin on 2019-03-13.
//

#ifndef STUFFTHING_MAINMENUSTATE_HPP
#define STUFFTHING_MAINMENUSTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "game.hpp"

namespace Chauwa
{
    class MainMenuState : public State
    {
    public:
        explicit MainMenuState(GameDataRef& data);

        void init() override;

        void handleInput() override;
        void update(float dt) override;
        void draw(float dt) override;
    private:
        GameDataRef _data;

        sf::Sprite _background;
        sf::Sprite _playButton;
        sf::Sprite _playButtonOuter;
        sf::Sprite _title;
    };
}

#endif //STUFFTHING_MAINMENUSTATE_HPP
