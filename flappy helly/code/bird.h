#ifndef BIRD_H_
#define BIRD_H_
#include "load.h"

class Bird
{
public:
    int y = 80;
    const int x = 80;
    void draw(SDL_Renderer* renderer);
    void Gravity();
    void Jump();
    bool JumpState();
    void Fly(SDL_Event e);
    SDL_Rect GetBirdRect();

private:
    SDL_Rect BirdRect ;
    SDL_Texture* bird1 = NULL;
    SDL_Texture* bird2 = NULL;
    double accel = 0;
    bool jumping = false;
    double jumpHeight = -6;
    double jumpTimer;
    double lastJump = 0;
    double gravity = 0.2;
    float a = 0.0f;
};

#endif // BIRD_H_
