#pragma once
#include <raylib-cpp.hpp>

enum class GameState
{
    MENU,
    GAMEPLAY,
    EXIT
};

class GameScreen
{
public:
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual ~GameScreen() = default;
};