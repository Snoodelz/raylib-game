#pragma once
#include "GameScreen.hpp"

class GamePlay : public GameScreen
{
private:
    GameState currentState = GameState::GAMEPLAY;

public:
    void update() override
    {
        if (IsKeyPressed(KEY_ESCAPE))
        {
            currentState = GameState::MENU;
        }
    }

    void draw() override
    {
        DrawText("GAMEPLAY SCREEN", 300, 180, 40, DARKGRAY);
        DrawText("Press ESC to return to menu", 270, 250, 20, GRAY);
    }

    GameState GetState() const { return currentState; }
};