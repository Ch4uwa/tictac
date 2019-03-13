//
// Created by MartinK on 2019-03-11.
//

#ifndef STUFFTHING_DEFINES_HPP
#define STUFFTHING_DEFINES_HPP

// Includes
#include <iostream>


// FilePath


// Macros
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1136

#define SPLASH_STATE_SHOW_TIME 3
#define SPLASH_SCENE_BACKGROUND_PATH "Resources/res/Splash Background.png"
#define MAIN_MENU_BACKGROUND_PATH "Resources/res/Main Menu Background.png"
#define MAIN_MENU_TITLE_PATH "Resources/res/Game Title.png"
#define MAIN_MENU_PLAY_BUTTON "Resources/res/Play Button.png"
#define MAIN_MENU_PLAY_BUTTON_OUTER "Resources/res/Play Button Outer.png"


#if 1
#define LOG(x) std::cerr<<(x)<<"\n"
#else
#define LOG(x)
#endif // LOG(x)

#endif //STUFFTHING_DEFINES_HPP
