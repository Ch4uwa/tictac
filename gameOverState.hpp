//
// Created by martin on 2019-03-13.
//

#ifndef STUFFTHING_GAMEOVERSTATE_HPP
#define STUFFTHING_GAMEOVERSTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "game.hpp"

namespace Chauwa
{
    class GameOverState : public State
    {
    public:
        explicit GameOverState(GameDataRef &data);
        ~GameOverState() override;

        void init() override;

        void handleInput() override;
        void update(float dt) override;
        void draw(float dt) override;
    private:
        GameDataRef _data;

        sf::Sprite _retryButton;
        sf::Sprite _homeButton;
    };
}

#endif //STUFFTHING_GAMEOVERSTATE_HPP
