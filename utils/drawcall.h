#pragma once
#include "SDL.h"
#include "SDL_image.h"

#include "size.h"

struct DrawCall {
SDL_Texture* texture;
SDL_Rect* rect;
};