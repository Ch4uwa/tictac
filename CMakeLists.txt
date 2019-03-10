cmake_minimum_required(VERSION 3.13)
project(StuffThing)

set(CMAKE_CXX_STANDARD 11)

set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS REQUIRED graphics window system network audio)

add_executable(
        StuffThing
        main.cpp
        State.hpp
        stateMachine.cpp stateMachine.hpp
        assetManager.cpp assetManager.hpp
        inputManager.cpp inputManager.hpp)

target_link_libraries(StuffThing sfml-graphics sfml-window)