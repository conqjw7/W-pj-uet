#include "tube.h"
#include "game.h"

Tube::Tube(SDL_Renderer* renderer, int y, bool Up):
    y(y),
    Up(Up)
{
    tubtex = load_image("image/tube.png",renderer);
    check = false;
}

void Tube::draw(SDL_Renderer* renderer)
{

    if(!Up)
    {
        TubeRect.x = x -128;
        TubeRect.y = y;
        TubeRect.w = 128;
        TubeRect.h = 720;
        SDL_RenderCopyEx(renderer, tubtex , NULL, &TubeRect, 0, NULL, SDL_FLIP_NONE);
    }
    else
    {

        TubeRect.x = x -128;
        TubeRect.y = y-600;
        TubeRect.w = 128;
        TubeRect.h = 720;
        SDL_RenderCopyEx(renderer, tubtex , NULL, &TubeRect, 0, NULL, SDL_FLIP_VERTICAL);
    }
}

void Tube::moving()
{
   x -= speed;
}
void Tube::check_point(double a,int& Point){
}
SDL_Rect Tube::GetTubeRect()
{
    return getRect(TubeRect);
}
