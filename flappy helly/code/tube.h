#ifndef TUBE_H_
#define TUBE_H_
#include "load.h"

class Tube
{
private:
        SDL_Rect TubeRect ;
        SDL_Texture* tubtex = NULL;
        int speed = 1;
public:
        bool check;
        int x=800;
        int y;
        bool Up ;
        void draw(SDL_Renderer* renderer);
        Tube(SDL_Renderer* renderer, int y, bool Up);
        void moving();
        SDL_Rect  GetTubeRect();
        void check_point(double a,int& Point);
};
#endif // TUBE_H
