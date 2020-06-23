#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "fenetre.h"
#include "collision.h"

float player::gravity = 0.005;
float player::PLAYER_VELOCITY = 1;

player::player()
{
    this -> posX = 0;
    this -> posY = 0;
    velX = 0;
    velY = 0;
    collider.w = PLAYER_WIDTH;
    collider.h = PLAYER_HEIGHT;
    collision = false;

}




float player::getPosX() const
{
    return posX;
}

float player::getPosY() const
{
    return posY;
}

void player::handleEvent(SDL_Event *e) 
{
    if (e -> type == SDL_KEYDOWN && e -> key.repeat == 0)
    {
        switch(e -> key.keysym.sym)
        {
            case SDLK_UP : velY -= PLAYER_VELOCITY;
                           break;
            case SDLK_RIGHT : velX += PLAYER_VELOCITY;
                               break;
            case SDLK_LEFT : velX -= PLAYER_VELOCITY;
                             break;
                             
        }
    }
    else if (e -> type == SDL_KEYUP)
    {
        switch(e -> key.keysym.sym)
        {
            case SDLK_UP : if(player::collision)
                           velY += PLAYER_VELOCITY;
                           break;
            case SDLK_RIGHT : velX -= PLAYER_VELOCITY;
                               break;
            case SDLK_LEFT : velX += PLAYER_VELOCITY;
                             break;
        }
    }
}


void player::move(SDL_FRect obstacles[42])
{
    posX += velX;
    collider.x = posX;

    if(posX < 0 || posX + PLAYER_WIDTH > fenetre::FENETRE_WIDTH ||  (collision = checkCollisionWithMap(collider, obstacles)))
    {

        posX -= velX;
        collider.x = posX;
    }

    velY += gravity;
    posY += velY;
    collider.y = posY;

    if(posY < 0 || posY + PLAYER_HEIGHT > fenetre::FENETRE_HEIGHT || (collision = checkCollisionWithMap(collider, obstacles)))
    {
        posY -= velY;
        collider.y = posY;
        velY = 0;
    }
}

void player::render() const
{
    SDL_FRect player = {posX, posY, PLAYER_WIDTH, PLAYER_HEIGHT};
    SDL_RenderFillRectF(fenetre::renderer, &player);
}





