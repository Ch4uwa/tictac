/*
 * Created by MartinK on 2019-03-11.
 */

#ifndef STUFFTHING_SPLASHSTATE_HPP
#define STUFFTHING_SPLASHSTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "game.hpp"

namespace Chauwa
{
    class SplashState : public State
    {
    public:
        explicit SplashState(GameDataRef data);

        void init() override;
        void handleInput() override;
        void update(float dt) override;
        void draw(float dt) override;

    private:
        GameDataRef _data;

        sf::Clock _clock;

        sf::Sprite _background;
    };
}

#endif //STUFFTHING_SPLASHSTATE_HPP
