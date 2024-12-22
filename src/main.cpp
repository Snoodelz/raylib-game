#include <iostream>
#include <memory>
#include <raylib-cpp.hpp>

#include "Gameplay.hpp"
#include "MainMenu.hpp"

class GameManager {
 public:
  GameManager()
      : window(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib C++ Starter Kit Example"),
        isRunning(true) {
    SetTargetFPS(TARGET_FPS);
    activeScreen = std::make_unique<MainMenu>();
  }

  void run() {
    while (isRunning) {
      update();
      render();
    }
  }

 private:
  static constexpr int SCREEN_WIDTH = 800;
  static constexpr int SCREEN_HEIGHT = 450;
  static constexpr int TARGET_FPS = 60;

  raylib::Window window;
  std::unique_ptr<GameScreen> activeScreen;
  bool isRunning;

  void update() { activeScreen->update(); }

  void render() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    activeScreen->draw();
    EndDrawing();
  }

  void handleStateTransitions() {
    if (auto menu = dynamic_cast<MainMenu *>(activeScreen.get())) {
      switch (menu->GetState()) {
        case GameState::GAMEPLAY:
          activeScreen = std::make_unique<GamePlay>();
          break;
        case GameState::EXIT:
          isRunning = false;
          break;
        default:
          break;
      }
    }
  }
};

int main() {
  // Initialization
  int screenWidth = 800;
  int screenHeight = 450;

  raylib::Color textColor(LIGHTGRAY);
  raylib::Window w(screenWidth, screenHeight, "Raylib C++ Starter Kit Example");

  SetTargetFPS(60);
  GameState currentState = GameState::MENU;
  std::unique_ptr<GameScreen> currentScreen = std::make_unique<MainMenu>();

  // Main game loop
  while (true)  // Detect window close button or ESC key
  {
    // Update
    // TODO: Update your variables here
    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);
    currentScreen->update();
    currentScreen->draw();

    // Handle state changes
    if (auto menu = dynamic_cast<MainMenu *>(currentScreen.get())) {
      if (menu->GetState() == GameState::GAMEPLAY) {
        currentScreen = std::make_unique<GamePlay>();
      } else if (menu->GetState() == GameState::EXIT) {
        break;
      }
    } else if (auto gameplay = dynamic_cast<GamePlay *>(currentScreen.get())) {
      if (gameplay->GetState() == GameState::MENU) {
        currentScreen = std::make_unique<MainMenu>();
      }
    }

    EndDrawing();
  }

  return 0;
}