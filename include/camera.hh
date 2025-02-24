#pragma once
#include "SDL.h"
#include <cstdint>

class Camera {
public:
  Camera(int viewport_width, int viewport_height) : viewport_width(viewport_width), viewport_height(viewport_height), position({0,0}){}
  void set_position(int x, int y);
  void set_position(SDL_Point coordinate);
  /**
   * @param direction -1 for zoom out, +1 for zoom in.
   */
  void zoom(double & delta_time, int8_t direction); 
  SDL_Point* apply_camera_transform(SDL_Point* position);
  double get_zoom();
  SDL_Point* get_position();
private:
  int viewport_width, viewport_height;
  double _zoom = 1;
  SDL_Point position;
};