#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL.h>
#include "constants.h"

void logSDLError(std::ostream& os, const std::string &msg, bool fatal = false);

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void waitUntilKeyPressed();

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

#endif // WINDOW_H
