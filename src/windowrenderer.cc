#include "SDL.h"
#include "SDL_image.h"

#include "windowrenderer.hh"

WindowRenderer::WindowRenderer(
    const char* title, 
    int width, 
    int height) 
    : renderer(NULL), window(NULL) {
        
    // CREATE WINDOW
    window = SDL_CreateWindow(title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width, height,
        SDL_WINDOW_FULLSCREEN);

    if (!window) {
    std::cout   << "Window could not be created.\n" 
    << "SDL Error: " << SDL_GetError() << std::endl;
    }

    // CREATE RENDERER
    renderer = SDL_CreateRenderer(
        window, 
        -1, 
        SDL_RENDERER_ACCELERATED);

    if (!renderer) {
    std::cout   << "Renderer could not be created.\n" 
    << "SDL_Error: " << SDL_GetError() << std::endl;
    }
}

WindowRenderer::~WindowRenderer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void WindowRenderer::draw() {
    SDL_SetRenderDrawColor(renderer, 0x00,0x00,0x00,0xFF);
    SDL_RenderClear(renderer);
    // [draw textures here]
    SDL_RenderPresent(renderer);
}