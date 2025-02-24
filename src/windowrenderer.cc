#include "SDL.h"
#include "SDL_image.h"

#include <iostream>

#include "windowrenderer.hh"

WindowRenderer::WindowRenderer(const char *title, int width, int height)
    : renderer(NULL), window(NULL) {

  // CREATE WINDOW
  window =
      SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                       width, height, SDL_WINDOW_FULLSCREEN);

  if (!window) {
    std::cout << "Window could not be created.\n"
              << "SDL ERROR: " << SDL_GetError() << std::endl;
  }

  // CREATE RENDERER
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!renderer) {
    std::cout << "Renderer could not be created.\n"
              << "SDL_ERROR: " << SDL_GetError() << std::endl;
  }
}

WindowRenderer::~WindowRenderer() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void WindowRenderer::draw() {
  SDL_RenderPresent(renderer);
}

SDL_Texture* WindowRenderer::load_texture(std::string _file_path) {
  SDL_Texture *texture{NULL};
  std::string file_path = SDL_GetBasePath() + std::string("../assets/textures/") + _file_path;
  texture = IMG_LoadTexture(renderer, file_path.c_str());
  if (texture == NULL) {
    std::cout << "Texture could not be loaded. No texture found at path "
              << file_path << "\n"
              << "ERROR: " << SDL_GetError() << std::endl;
  }
  return texture;
}

void WindowRenderer::clear() {
  SDL_RenderClear(renderer);
}

void WindowRenderer::draw_texture(SDL_Texture* const & texture, int & x, int & y, int scale = 1) {
  int width, height;
  SDL_QueryTexture(texture, NULL, NULL, &width, &height);
  width *= scale;
  height *= scale;
  SDL_Rect rect{x,y,width,height};
  SDL_RenderCopy(renderer, texture, NULL,&rect); 
}

void WindowRenderer::draw_texture(SDL_Texture* const & texture, int && x, int && y, int scale = 1) {
  int width, height;
  SDL_QueryTexture(texture, NULL, NULL, &width, &height);
  width *= scale;
  height *= scale;
  SDL_Rect rect{x,y,width,height};
  SDL_RenderCopy(renderer, texture, NULL,&rect); 
}
  
void WindowRenderer::draw_texture(SDL_Texture* const & texture, SDL_Point* position, int scale) {
  int width, height;
  SDL_QueryTexture(texture, NULL, NULL, &width, &height);
  width *= scale;
  height *= scale;
  SDL_Rect rect{position->x,position->y,width,height};
  SDL_RenderCopy(renderer, texture, NULL,&rect); 

}