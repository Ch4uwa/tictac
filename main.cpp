/*
 * Martin Karlsson 2019-03-10
 */
#include "game.hpp"
#include "Defines.hpp"

int main()
{
    LOG("Program is running!");
    Chauwa::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Tic-Tac-Toe");
}