//
// Created by martin on 2019-03-14.
//

#ifndef STUFFTHING_PAUSESTATE_HPP
#define STUFFTHING_PAUSESTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "game.hpp"

namespace Chauwa
{
    class PauseState : public State
    {
    public:
        explicit PauseState(GameDataRef &data);
        ~PauseState() override;

        void init() override;

        void handleInput() override;
        void update(float dt) override;
        void draw(float dt) override;

    private:
        GameDataRef _data;

        sf::Sprite _background;
        sf::Sprite _resumeButton;
        sf::Sprite _homeButton;
    };
}

#endif //STUFFTHING_PAUSESTATE_HPP
