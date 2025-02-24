#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#include <thread>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"

#include "windowrenderer.cc"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define SPRITE_SIZE 32
// constexpr int SCALE_VALUE = SCREEN_WIDTH/SPRITE_SIZE;

int main() {

  // ========== DO NOT TOUCH =======================================

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialise.\n"
              << "SDL ERROR: " << SDL_GetError() << std::endl;
    return 0;
  }
  if (!(IMG_Init(IMG_INIT_PNG))) {
    std::cout << "SDL_image could not initialise.\n"
              << "SDL ERROR: " << SDL_GetError() << std::endl;
  }

  WindowRenderer window_renderer =
      WindowRenderer("Shattered Vault", SCREEN_WIDTH, SCREEN_HEIGHT);

  bool game_running = true;
  while (game_running) {
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
      game_running = false;
    }

    // --------------------------------------- GAME LOOP
    window_renderer.clear();
    SDL_Texture* texture = window_renderer.load_texture("enemy.png");
    window_renderer.draw_texture(texture,0,0,3);
    window_renderer.draw();
    // ----------------------------------------------------------------------------------------

  }
  SDL_Quit();
  return 0;
}
