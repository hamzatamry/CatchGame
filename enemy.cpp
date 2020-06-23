#include <SDL2/SDL.h>
#include <iostream>
#include <bits/stdc++.h>
#include "fenetre.h"
#include "player.h"
#include "enemy.h"


enemy::enemy()
{
    posX = 1358;
}


void enemy::handleEvent(SDL_Event *e)
{
    if (e -> type == SDL_KEYDOWN && e -> key.repeat == 0)
    {
        switch(e -> key.keysym.sym)
        {
            case SDLK_z : velY -= PLAYER_VELOCITY;
                           break;
            case SDLK_d : velX += PLAYER_VELOCITY;
                               break;
            case SDLK_q : velX -= PLAYER_VELOCITY;
                             break;
        }
    }

    else if (e -> type == SDL_KEYUP && e -> key.repeat == 0)
    {
        switch(e -> key.keysym.sym)
        {
            case SDLK_z :  if(player::collision)
                           velY += PLAYER_VELOCITY;
                           break;
            case SDLK_d : velX -= PLAYER_VELOCITY;
                               break;
            case SDLK_q : velX += PLAYER_VELOCITY;
                             break;
        }
    }
}

