#include "MainMenu.hpp"

void MainMenu::update()
{
    if (IsKeyPressed(KEY_ENTER))
    {
        currentState = GameState::GAMEPLAY;
    }
    if (IsKeyPressed(KEY_ESCAPE))
    {
        currentState = GameState::EXIT;
    }
}

void MainMenu::draw()
{
    DrawText("Main Menu", 10, 10, 20, BLACK);
    DrawText("Press Enter to start", 10, 30, 20, BLACK);
    DrawText("Press ESC to exit", 10, 50, 20, BLACK);
}