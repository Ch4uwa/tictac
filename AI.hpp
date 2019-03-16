//
// Created by martin on 2019-03-15.
//

#ifndef STUFFTHING_AI_HPP
#define STUFFTHING_AI_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include "game.hpp"

namespace Chauwa
{
    class AI
    {
    public:
        AI(int playerPiece, GameDataRef &data);

        void PlacePiece(int(*girdArray)[3][3],
                sf::Sprite gridPieces[3][3], int *gameState);
    private:
        void CheckSection(int x1, int y1, int x2, int y2, int X, int Y,
                int pieceToCheck, int(*gridArray)[3][3], sf::Sprite gridPieces[3][3]);

        void CheckIfPieceIsEmpty(int X, int Y,
                int(*gridArray)[3][3], sf::Sprite gridPieces[3][3]);

        int aiPiece;
        int playerPiece;

        std::vector<std::array<int, 6>> checkMatchVector;

        GameDataRef _data;
    };
}

#endif //STUFFTHING_AI_HPP
