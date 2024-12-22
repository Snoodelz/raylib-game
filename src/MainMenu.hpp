#pragma once
#include "GameScreen.hpp"

class MainMenu : public GameScreen
{
public:
    void update() override;
    void draw() override;

    GameState GetState() const { return currentState; }

private:
    GameState currentState = GameState::MENU;
};