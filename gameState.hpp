//
// Created by martin on 2019-03-14.
//

#ifndef STUFFTHING_GAMESTATE_HPP
#define STUFFTHING_GAMESTATE_HPP

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "game.hpp"

#include "AI.hpp"

namespace Chauwa
{
    class GameState : public State
    {
    public:
        explicit GameState(GameDataRef data);
        ~GameState() override;

        void init() override;
        void handleInput() override;
        void update(float dt) override;
        void draw(float dt) override;

    private:
        void initGridPieces();
        void CheckAndPlacePiece();
        void CheckPlayerHasWon(int &turn);
        void Check3PiecesForMatch(
                int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck);

        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _pauseButton;
        sf::Sprite _gridSprite;

        sf::Sprite _gridPieces[3][3];
        int gridArray[3][3];

        int turn;
        int gameState;

        AI *ai;

        sf::Clock _clock;

    };
}

#endif //STUFFTHING_GAMESTATE_HPP
