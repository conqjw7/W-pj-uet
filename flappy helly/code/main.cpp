#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "window.h"
#include "variables.h"

using namespace std;

int main(int argc, char* argv[])
{
    initSDL(screen,renderer);

    waitUntilKeyPressed();
    quitSDL(screen, renderer);

    return 0;
}
