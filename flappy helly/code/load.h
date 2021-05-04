#ifndef LOAD_H_
#define LOAD_H_
#include "SDL_image.h"
#include "string"
using namespace std;
SDL_Texture* load_image(const string path, SDL_Renderer* renderer);
void apply_texture(SDL_Texture* texture, SDL_Renderer* renderer);
SDL_Rect getRect(SDL_Rect scRect);
#endif // LOAD_H_
