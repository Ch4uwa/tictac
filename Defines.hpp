//
// Created by MartinK on 2019-03-11.
//

#ifndef STUFFTHING_DEFINES_HPP
#define STUFFTHING_DEFINES_HPP

// Includes
#include <iostream>

// FilePath
#define SPLASH_SCENE_BACKGROUND_PATH "Resources/res/Splash Background.png"
#define MAIN_MENU_BACKGROUND_PATH "Resources/res/Main Menu Background.png"
#define GAME_BACKGROUND_PATH "Resources/res/Main Menu Background.png"
#define PAUSE_BACKGROUND_PATH "Resources/res/Main Menu Background.png"

#define MAIN_MENU_TITLE_PATH "Resources/res/Game Title.png"

#define MAIN_MENU_PLAY_BUTTON "Resources/res/Play Button.png"
#define MAIN_MENU_PLAY_BUTTON_OUTER "Resources/res/Play Button Outer.png"
#define PAUSE_BUTTON "Resources/res/Pause Button.png"
#define RESUME_BUTTON "Resources/res/Resume Button.png"
#define HOME_BUTTON "Resources/res/Home Button.png"
#define RETRY_BUTTON "Resources/res/Retry Button.png"

#define X_PIECE_PATH "Resources/res/X.png"
#define O_PIECE_PATH "Resources/res/O.png"
#define X_WINNING_PIECE_PATH "Resources/res/X Win.png"
#define O_WINNING_PIECE_PATH "Resources/res/O Win.png"

#define GRID_SPRITE_PATH "Resources/res/Grid.png"

// Macros
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1136

#define SPLASH_STATE_SHOW_TIME 3

#define X_PIECE 8
#define O_PIECE 0
#define EMPTY_PIECE (-1)
#define PLAYER_PIECE X_PIECE
#define AI_PIECE O_PIECE

#define STATE_PLAYING 98
#define STATE_PAUSED 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94
#define STATE_AI_PLAYING 93
#define STATE_DRAW 92

#define TIME_BEFORE_SHOWING_GAME_OVER 3

#if 1
#define LOG(x) std::cerr<<(x)<<"\n"
#else
#define LOG(x)
#endif // LOG(x)

#endif //STUFFTHING_DEFINES_HPP
