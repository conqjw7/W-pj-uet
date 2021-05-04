#include "game.h"

GameLoop::GameLoop()
{
    GameState = false;
}

void GameLoop::initSDL()
{   SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN );
    if (window)
        renderer = SDL_CreateRenderer(window, -1,  SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    if (renderer)
    {
            GameState = true;
            background = load_image("image/background.png", renderer);
            game_over= load_image("image/game_over.png",renderer);
    }
}

void GameLoop::render()
 {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, NULL, NULL);
        p.draw(renderer);
        for (auto &tube: tubeList) tube.draw(renderer);
        SDL_RenderPresent(renderer);
 }

bool GameLoop::GetGameState()
{
    return GameState;
}

void GameLoop::quitSDL()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void GameLoop::event()
{
    if (GamePlay)
    { render(); play(); }
    else gameover();
}

void GameLoop::play()
{
   SDL_PollEvent(&e);
   if (e.type == SDL_QUIT) quitSDL();
   else if (e.type==SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_ESCAPE)
               GamePlay = false;
        }
	p.Fly(e); //bird-player event
    SDL_Rect birdRect = p.GetBirdRect();
	if (p.y > ScreenHeight) GamePlay = false;

	//tube event
	if (counter++ % 300 == 0)
        {
        auto y = rand() % (ScreenHeight - 550) + 100;
        tubeList.emplace_back(renderer, y + 350, false);
        tubeList.emplace_back(renderer, y, true);
        }
    //done drawing tubes
    for (auto &tube: tubeList)
    {
        tube.moving();
        SDL_Rect tubeRect;
        if (tube.Up)
        {
            tubeRect = tube.GetTubeRect();;
            if (SDL_HasIntersection(&birdRect, &tubeRect))
            {
                GamePlay = false;
            }
        }
        else
            {
            tubeRect = tube.GetTubeRect();;
                if (SDL_HasIntersection(&birdRect, &tubeRect))
                {
                    GamePlay = false;
                }
                /*if(c+528 > tubeRect.x +tubeRect.w && c+528 < tubeRect.x+ tubeRect.w +1)
                {
                    check=true;
                }
            if(check==true)
                {
                    point++;
                    check=false;
                }
                cout << check <<" ";*/
            }
    }
    for (auto iter = tubeList.begin(); iter != tubeList.end(); )
    {
        if (iter->x < 128)
            iter = tubeList.erase(iter);
        else
            ++iter;
    }
}

void GameLoop::clearscreen()
{
        const SDL_Color BGR_COLOR = {255, 255, 255};
        SDL_SetRenderDrawColor(renderer, BGR_COLOR.r, BGR_COLOR.g, BGR_COLOR.b, 0);
        SDL_RenderClear(renderer);
}
void GameLoop::gameover()
{
        clearscreen();
        SDL_RenderCopy( renderer, background, NULL, NULL);
        SDL_RenderCopy( renderer, game_over, NULL, NULL);
        SDL_RenderPresent( renderer );
        SDL_PollEvent(&e_over);
        if (e_over.type==SDL_QUIT)
        {
            GameState = false;
        }
        else if (e_over.type==SDL_KEYDOWN)
        {
            if (e_over.key.keysym.sym == SDLK_ESCAPE)
               GameState = false;
        }
}


