#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include<string>
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Console";

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void logSDLError(std::ostream& os, const std::string &msg, bool fatal = false);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();



#endif
