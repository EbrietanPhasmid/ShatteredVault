#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#include <thread>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"

#include "clock.hh"

#include "windowrenderer.cc"
#include "camera.cc"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define WORLD_WIDTH 640
#define WORLD_HEIGHT 360

constexpr int SCALE_VALUE = SCREEN_WIDTH/WORLD_WIDTH;

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

  WindowRenderer window =
      WindowRenderer("Shattered Vault", SCREEN_WIDTH, SCREEN_HEIGHT);

  bool game_running = true;

  Clock clock;
  Camera camera = Camera(SCREEN_WIDTH,SCREEN_HEIGHT);
  //double* delta_time = &(clock.delta_time);

  while (game_running) {
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
      game_running = false;
    }

    window.clear();
    clock.tick();
    // --------------------------------------- GAME LOOP --------------------------------------
    
    SDL_Texture* texture = window.load_texture("enemy.png");
    SDL_Point origin{0,0};
    window.draw_texture(texture,camera.apply_camera_transform(&origin),SCALE_VALUE*camera.get_zoom());

    // ----------------------------------------------------------------------------------------
    window.draw();
  }
  SDL_Quit();
  return 0;
}
