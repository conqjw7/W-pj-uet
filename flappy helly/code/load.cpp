#include "load.h"

SDL_Texture* load_image(const string path, SDL_Renderer* renderer)
{
  SDL_Surface* surface = IMG_Load(path.c_str());
  SDL_Texture* texture = NULL;
  if (surface)
  {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
  }
  return texture;
};

void apply_texture(SDL_Texture* texture, SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
};


SDL_Rect getRect(SDL_Rect scRect)
{
    return scRect;
};
