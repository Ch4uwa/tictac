#include <utility>
//
// Created by martin on 2019-03-14.
//

#include "gameState.hpp"
#include "Defines.hpp"
#include "pauseState.hpp"
#include "gameOverState.hpp"

namespace Chauwa
{
    GameState::GameState(GameDataRef data)
            : _data(std::move(data)), turn(0), gameState(0)
    {
        LOG("GameState ctor");
    }
    void GameState::init()
    {
        gameState = STATE_PLAYING;
        turn = PLAYER_PIECE;

        this->ai = new AI(turn, this->_data);

        this->_data->assets.loadTexture("Pause Button", PAUSE_BUTTON);
        this->_data->assets.loadTexture("Game Background", GAME_BACKGROUND_PATH);
        this->_data->assets.loadTexture("Grid Sprite", GRID_SPRITE_PATH);
        this->_data->assets.loadTexture("X Piece", X_PIECE_PATH);
        this->_data->assets.loadTexture("O Piece", O_PIECE_PATH);

        this->_data->assets.loadTexture("X Winning Piece", X_WINNING_PIECE_PATH);
        this->_data->assets.loadTexture("O Winning Piece", O_WINNING_PIECE_PATH);

        _background.setTexture(this->_data->assets.getTexture("Game Background"));
        _pauseButton.setTexture(this->_data->assets.getTexture("Pause Button"));
        _gridSprite.setTexture(this->_data->assets.getTexture("Grid Sprite"));

        _pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getLocalBounds().width,
                _pauseButton.getPosition().y);

        _gridSprite.setPosition(SCREEN_WIDTH / 2.f - (_gridSprite.getGlobalBounds().width / 2),
                SCREEN_HEIGHT / 2.f - (_gridSprite.getGlobalBounds().height / 2));

        initGridPieces();

        for (auto &x : gridArray)
        {
            for (int &y : x)
            {
                y = EMPTY_PIECE;
            }
        }
    }
    void GameState::handleInput()
    {
        sf::Event event{};

        while (this->_data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->_data->window.close();
            }

            if (this->_data->input.isSpriteClicked(
                    this->_pauseButton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->machine.addState(stateRef(new PauseState(_data)), false);
            } else if (this->_data->input.isSpriteClicked(
                    this->_gridSprite, sf::Mouse::Left, this->_data->window))
            {
                if (STATE_PLAYING == gameState)
                {
                    this->CheckAndPlacePiece();
                }
            }
        }
    }
    void GameState::update(float dt)
    {
        if (STATE_DRAW == gameState || STATE_LOSE == gameState || STATE_WON == gameState)
        {
            if (this->_clock.getElapsedTime().asSeconds() > TIME_BEFORE_SHOWING_GAME_OVER)
            {
                this->_data->machine.addState(stateRef(new GameOverState(_data)), true);
            }
        }
    }
    void GameState::draw(float dt)
    {
        this->_data->window.clear();

        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_pauseButton);
        this->_data->window.draw(this->_gridSprite);

        for (auto &_gridPiece : this->_gridPieces)
        {
            for (const auto &y : _gridPiece)
            {
                this->_data->window.draw(y);
            }
        }

        this->_data->window.display();

    }
    GameState::~GameState()
    {
        LOG("GameState dtor");
        delete ai;
    }
    void GameState::initGridPieces()
    {
        sf::Vector2u tempSpriteSize = this->_data->assets.getTexture("X Piece").getSize();

        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                _gridPieces[x][y].setTexture(this->_data->assets.getTexture("X Piece"));
                _gridPieces[x][y].setPosition(
                        _gridSprite.getPosition().x + (tempSpriteSize.x * x) - 7,
                        _gridSprite.getPosition().y + (tempSpriteSize.y * y) - 7);
                _gridPieces[x][y].setColor(sf::Color(255, 255, 255, 0));
            }
        }
    }
    void GameState::CheckAndPlacePiece()
    {
        sf::Vector2i touchPoint = this->_data->input.getMousePosition(this->_data->window);
        sf::FloatRect gridSize = _gridSprite.getGlobalBounds();
        sf::Vector2f gapOutsideOfGrid = sf::Vector2f((SCREEN_WIDTH - gridSize.width) / 2,
                (SCREEN_HEIGHT - gridSize.height) / 2);

        sf::Vector2f gridLocalTouchPos = sf::Vector2f(touchPoint.x - gapOutsideOfGrid.x,
                touchPoint.y - gapOutsideOfGrid.y);
        sf::Vector2f gridSectionSize = sf::Vector2f(gridSize.width / 3, gridSize.height / 3);

        int column{}, row{};

        if (gridLocalTouchPos.x < gridSectionSize.x)
        {
            column = 1;
        } else if (gridLocalTouchPos.x < gridSectionSize.x * 2)
        {
            column = 2;
        } else if (gridLocalTouchPos.x < gridSize.width * 2)
        {
            column = 3;
        }

        if (gridLocalTouchPos.y < gridSectionSize.y)
        {
            row = 1;
        } else if (gridLocalTouchPos.y < gridSectionSize.y * 2)
        {
            row = 2;
        } else if (gridLocalTouchPos.y < gridSize.height)
        {
            row = 3;
        }

        if (gridArray[column - 1][row - 1] == EMPTY_PIECE)
        {
            gridArray[column - 1][row - 1] = turn;

            if (PLAYER_PIECE == turn)
            {
                _gridPieces[column - 1][row - 1].setTexture(this->_data->assets.getTexture("X Piece"));

                this->CheckPlayerHasWon(turn);
            }

            _gridPieces[column - 1][row - 1].setColor(sf::Color(255, 255, 255, 255));
        }
    }
    void GameState::CheckPlayerHasWon(int &player)
    {
        Check3PiecesForMatch(0, 0, 1, 0, 2, 0, player);
        Check3PiecesForMatch(0, 1, 1, 1, 2, 1, player);
        Check3PiecesForMatch(0, 2, 1, 2, 2, 2, player);
        Check3PiecesForMatch(0, 0, 0, 1, 0, 2, player);
        Check3PiecesForMatch(1, 0, 1, 1, 1, 2, player);
        Check3PiecesForMatch(2, 0, 2, 1, 2, 2, player);
        Check3PiecesForMatch(0, 0, 1, 1, 2, 2, player);
        Check3PiecesForMatch(0, 2, 1, 1, 2, 0, player);

        if (STATE_WON != gameState)
        {
            gameState = STATE_AI_PLAYING;

            ai->PlacePiece(&gridArray, _gridPieces, &gameState);

            Check3PiecesForMatch(0, 0, 1, 0, 2, 0, AI_PIECE);
            Check3PiecesForMatch(0, 1, 1, 1, 2, 1, AI_PIECE);
            Check3PiecesForMatch(0, 2, 1, 2, 2, 2, AI_PIECE);
            Check3PiecesForMatch(0, 0, 0, 1, 0, 2, AI_PIECE);
            Check3PiecesForMatch(1, 0, 1, 1, 1, 2, AI_PIECE);
            Check3PiecesForMatch(2, 0, 2, 1, 2, 2, AI_PIECE);
            Check3PiecesForMatch(0, 0, 1, 1, 2, 2, AI_PIECE);
            Check3PiecesForMatch(0, 2, 1, 1, 2, 0, AI_PIECE);
        }

        int emptyNum = 9;

        for (auto &x : gridArray)
        {
            for (int y : x)
            {
                if (EMPTY_PIECE != y)
                {
                    emptyNum--;
                }
            }
        }
        if (0 == emptyNum && (STATE_WON != gameState) && (STATE_LOSE != gameState))
        {
            gameState = STATE_DRAW;
        }

        if (STATE_DRAW == gameState || STATE_LOSE == gameState || STATE_WON == gameState)
        {
            /* Show game over */
            this->_clock.restart();
        }

        std::cout << gameState << std::endl;
    }
    void GameState::Check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck)
    {
        if (pieceToCheck == gridArray[x1][y1] &&
            pieceToCheck == gridArray[x2][y2] &&
            pieceToCheck == gridArray[x3][y3])
        {
            std::string winningPieceStr;

            winningPieceStr = O_PIECE == pieceToCheck ? "O Winning Piece" : "X Winning Piece";

            _gridPieces[x1][y1].setTexture(
                    this->_data->assets.getTexture(winningPieceStr));
            _gridPieces[x2][y2].setTexture(
                    this->_data->assets.getTexture(winningPieceStr));
            _gridPieces[x3][y3].setTexture(
                    this->_data->assets.getTexture(winningPieceStr));

            gameState = PLAYER_PIECE == pieceToCheck ? STATE_WON : STATE_LOSE;
        }
    }
}


















