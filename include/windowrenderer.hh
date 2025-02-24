#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <string>

#include "drawcall.h"

class WindowRenderer {
public:
  WindowRenderer(const char *title, int width, int height);
  ~WindowRenderer();

  SDL_Texture* load_texture(std::string file_path);
  void draw_texture(SDL_Texture* const & texture, int & x, int & y, int scale);
  void draw_texture(SDL_Texture* const & texture, int && x, int && y, int scale);
  void clear();
  void draw();

private:
  SDL_Renderer *renderer;
  SDL_Window *window;
};