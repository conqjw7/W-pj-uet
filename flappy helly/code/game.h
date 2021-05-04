#ifndef GAME_H_
#define GAME_H_
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_mixer.h>
#include "bird.h"
#include "tube.h"
#include "load.h"

using namespace std;

class GameLoop{
private:
        static const int ScreenHeight = 600;
        static const int ScreenWidth = 800;
        const string WINDOW_TITLE = "Budget Flappy Bird lamo";
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        bool GameState;
        bool GamePlay= true;
        SDL_Event e;
        SDL_Event e_over;
        Bird p;
        vector <Tube> tubeList;
        SDL_Texture* background = NULL;
        SDL_Texture* game_over = NULL;
        int c = 0;
        int point = 0;
        int counter =0;
        bool check;
        bool check_point = false;

public:
        GameLoop();
        void initSDL();
        void quitSDL();
        bool GetGameState();
        void event();
        void render();
        void clearscreen();
        void gameover();
        void play();
};
#endif // GAME_H_
