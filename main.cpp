#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include "collision.h"
#include "player.h"
#include "enemy.h"
#include "fenetre.h"
#include "timer.h"
#include "map.h"


void TTF_Initialisation(TTF_Font** font)
{
    TTF_Init();
    *font = TTF_OpenFont("arial.ttf", 60);
}


void showTime(int time, SDL_Renderer* renderer, TTF_Font* font)
{
    SDL_Color red = {255, 0, 0, 150};
    SDL_Rect barreTime = {633, 0, 100, 100};
    SDL_Surface *timeSurface = NULL;
    SDL_Texture *timeTexture = NULL;
    char timeString[3];
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    sprintf(timeString, "%d", time / 1000);
    timeSurface = TTF_RenderText_Solid(font, timeString, red);
    timeTexture = SDL_CreateTextureFromSurface(renderer, timeSurface);
    SDL_RenderCopy(fenetre::renderer, timeTexture, NULL, &barreTime);
    SDL_FreeSurface(timeSurface);
}


int main(int argc, char *argv[])
{
    SDL_bool programLaunched = SDL_TRUE;
    fenetre f = fenetre();
    map* m = new map();
    player* p = new player();
    player* p2 = new enemy();

    TTF_Font* font = NULL;
    TTF_Initialisation(&font);

    timer chronoTimer;
    timer capTimer;
    int FPS = 300;
    int frameTicks = 1000 / FPS;


    chronoTimer.start();
    while(programLaunched)
    {
        capTimer.start();
        SDL_Event Event;
        while(SDL_PollEvent(&Event))
        {
            p -> handleEvent(&Event);
            p2 -> handleEvent(&Event);
            if(Event.type == SDL_QUIT)
            {
                programLaunched = SDL_FALSE;
                break;
            }

        }

        p -> move(m -> getmapObstacles());
        p2 -> move(m -> getmapObstacles());


        SDL_SetRenderDrawColor(fenetre::renderer, 255, 255, 255, 255);
        SDL_RenderClear(fenetre::renderer);

        SDL_SetRenderDrawColor(fenetre::renderer, 0, 0, 0, 255);
        m -> renderMap();
        SDL_SetRenderDrawColor(fenetre::renderer, 0, 0, 255, 255);
        p -> render();
        SDL_SetRenderDrawColor(fenetre::renderer, 255, 0, 0, 255);
        p2 -> render();
        int time = chronoTimer.getTicks();

        showTime(time, fenetre::renderer, font);

        SDL_RenderPresent(fenetre::renderer);
        int timeTicks = capTimer.getTicks();

        if(timeTicks < frameTicks)
        {
            SDL_Delay(frameTicks - timeTicks);
        }

        if(checkCollisionWithPlayer(p -> collider, p2 -> collider))
        {
            programLaunched = SDL_FALSE;
            SDL_Delay(3000);
            break;
        }
    }

    return 0;
}
