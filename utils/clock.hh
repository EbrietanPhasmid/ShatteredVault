#pragma once
#include "SDL.h"

struct Clock {
  uint64_t last_tick, current_tick = 0;
  double delta_time;
void tick() {
  constexpr double MIN_DELTA_TIME = 1.0 / 1000.0;
  current_tick = (uint64_t) SDL_GetPerformanceCounter();
  delta_time = (double)((current_tick-last_tick) / (double) SDL_GetPerformanceFrequency()); 
  last_tick = current_tick;
  delta_time = std::max(delta_time,MIN_DELTA_TIME);
}  
};