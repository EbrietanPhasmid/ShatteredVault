#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"

#include "windowrenderer.cc"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

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

  SDL_Event event;
  bool game_running = true;
  while (game_running) {

    SDL_WaitEvent(&event);

    if (event.type == SDL_QUIT) {
      game_running = false;
    }

    // --------------------------------------- GAME LOOP

    // ----------------------------------------------------------------------------------------

  }
  SDL_Quit();
  return 0;
}
