#pragma once

#include "SDL.h"
#include "SDL_image.h"

class WindowRenderer {
    public:
        WindowRenderer(const char* title, int width, int height);
        ~WindowRenderer();
        void draw();
    private:
        SDL_Renderer* renderer; 
        SDL_Window* window; 
};