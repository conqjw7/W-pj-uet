#ifndef LOAD_H
#define LOAD_H
#include <SDL.h>
#include <SDL_image.h>
#include <string>
using namespace constants;
using namespace std;

SDL_Texture* loadImage(string path,SDL_Renderer* renderer)  ///loadimage func
{
    SDL_Texture* loadedImage = NULL;

    SDL_Surface* load_surface = IMG_Load(path.c_str());
    Uint32 colorkey = SDL_MapRGB(load_surface->format,73, 203, 58);
    SDL_SetColorKey(load_surface, SDL_TRUE, colorkey);
    loadedImage = SDL_CreateTextureFromSurface(renderer, load_surface);
    if (loadedImage!=NULL)
    {
        SDL_FreeSurface(load_surface);
        return loadedImage;
    }
}
#endif // LOAD_H
