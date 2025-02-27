#pragma once
#include "camera.hh"

void Camera::set_position(int x, int y) { position = {x,y}; }
void Camera::set_position(SDL_Point coordinate) { position = coordinate; }
void Camera::zoom(double & delta_time, int8_t direction) {
  #define MAX_ZOOM 5
  #define MIN_ZOOM 0.5
  float zoom_speed = 0.1;
  if (direction == 1) {_zoom += zoom_speed * delta_time / 100000;}
  if (direction == -1) {_zoom -= zoom_speed * delta_time / 100000;}
  if (_zoom > MAX_ZOOM ) {_zoom = MAX_ZOOM;}
  if (_zoom < MIN_ZOOM ) {_zoom = MIN_ZOOM;}
}
SDL_Point* Camera::apply_camera_transform(SDL_Point* position) {
  position->x += viewport_width/2 - this->position.x;
  position->y += viewport_height/2 - this->position.y;
  return position;
}
double Camera::get_zoom() { return _zoom;}
SDL_Point* Camera::get_position() {return &position;} 
void Camera::move(int & x, int & y) {
  SDL_Point* position = get_position();
  int _x {position->x};
  int _y {position->y};
  set_position(_x + x, _y + y);
}
void Camera::move(int && x, int && y) {
  SDL_Point* position = get_position();
  int _x {position->x};
  int _y {position->y};
  set_position(_x + x, _y + y);
}