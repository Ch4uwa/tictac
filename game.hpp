/*
 * Created by MartinK on 2019-03-11.
 */

#ifndef STUFFTHING_GAME_HPP
#define STUFFTHING_GAME_HPP

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "stateMachine.hpp"
#include "assetManager.hpp"
#include "inputManager.hpp"

namespace Chauwa
{
    struct GameData
    {
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game
    {
    public:
        Game(unsigned int width, unsigned int height, std::string title);
        ~Game() = default;

    private:
        const float dt = 1.0f / 60.0f;
        sf::Clock _clock;

        GameDataRef _data = std::make_shared<GameData>();

        void run();
    };
}

#endif //STUFFTHING_GAME_HPP
