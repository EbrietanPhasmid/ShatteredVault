#include "SDL.h"
#include "SDL_image.h"

#include "windowrenderer.cc"

int main() {
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
      WindowRenderer("Shattered Vault", 1920, 1080);

  SDL_Event event;
  bool game_running = true;
  while (game_running) {

    SDL_WaitEvent(&event);

    if (event.type == SDL_QUIT) {
      game_running = false;
    }
    window_renderer.clear();
    SDL_Texture* texture = window_renderer.load_texture("assets/textures/crate.png");
    int width = 0;
    int height = 0;
    SDL_QueryTexture(texture,NULL,NULL,&width,&height);
    SDL_Rect rect = {0,0,width,height};
    const DrawCall draw_call = {texture,&rect};     
    window_renderer.draw_texture(&draw_call);
    window_renderer.draw();
  }
  SDL_Quit();
  return 0;
}