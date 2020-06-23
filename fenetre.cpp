#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <assert.h>
#include "fenetre.h"

SDL_Window *fenetre::window = NULL;
SDL_Renderer *fenetre::renderer = NULL;

fenetre::fenetre()
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("CatchMe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, FENETRE_WIDTH, FENETRE_HEIGHT, SDL_WINDOW_SHOWN);

    assert(!(window == NULL));

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    assert(!(renderer == NULL));
}

fenetre::~fenetre()
{
    if(renderer != NULL)
        SDL_DestroyRenderer(renderer);
    if(window != NULL)
        SDL_DestroyWindow(window);
    SDL_Quit();
}
