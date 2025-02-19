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

SDL_Texture* WindowRenderer::load_texture(std::string file_path) {
  SDL_Texture *texture{NULL};
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

void WindowRenderer::draw_texture(const DrawCall* const & draw_call) {
  SDL_RenderCopy(renderer, draw_call->texture, NULL, draw_call->rect);
}