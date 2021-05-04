#include <iostream>
#include "game.h"
using namespace std;

int main(int argc, char* argv[])
{
    GameLoop g;
    double ini;
	double fin = 0;
	int fps =60;
    g.initSDL();

    do {
        g.event();
        ini = SDL_GetTicks();
        if (ini - fin < 1000/fps)
		{
			SDL_Delay(1000/fps - (ini - fin));
		}
		fin = ini;
    }
    while (g.GetGameState());
    g.quitSDL();
    return 0;
}
