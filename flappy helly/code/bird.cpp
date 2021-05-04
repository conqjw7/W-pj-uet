#include "bird.h"

void Bird::draw(SDL_Renderer* renderer)
{
    bird1 = load_image("image/bird1.png", renderer);
    bird2 = load_image("image/bird2.png", renderer);
    BirdRect.x = x ;
    BirdRect.y = y ;
    BirdRect.w = 90;
    BirdRect.h = 80;
    SDL_RenderCopyEx(renderer, SDL_GetTicks() % 300 > 150 ? bird1 : bird2 , NULL, &BirdRect, 0 , NULL, SDL_FLIP_NONE);
}

void Bird::Fly(SDL_Event e)
{
    jumpTimer = SDL_GetTicks();
    if (e.type==SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_SPACE)
		{
			if (!JumpState())
			{
				Jump();
			}
			else
			{
				Gravity();
			}
		}
	}
	else
	{
		Gravity();
	}
}

void Bird::Gravity()
{
	if (JumpState())
	{
		accel += 0.035;
		jumpHeight = jumpHeight + gravity;
		y = y + gravity + accel * 2 + jumpHeight;
		if (jumpHeight > 0)
		{
			jumping = false;
			jumpHeight = -6;
		}
	}
	else
	{
		accel += 0.035;
		y = y + gravity + accel * 2;
	}

}

void Bird::Jump()
{
	if (jumpTimer - lastJump > 180)
	{
		accel = 0;
		jumping = true;
		lastJump = jumpTimer;

	}
	else
	{
		Gravity();
	}
}


bool Bird::JumpState()
{
	return jumping;
}

SDL_Rect Bird::GetBirdRect()
{
    return getRect(BirdRect);
}

