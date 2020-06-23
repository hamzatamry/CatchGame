#include <SDL2/SDL.h>
#include "collision.h"


bool checkCollisionWithMap( SDL_FRect a, SDL_FRect obstacles[42])
{
    //The sides of the rectangles
    float leftA, leftB;
    float rightA, rightB;
    float topA, topB;
    float bottomA, bottomB;


    for(int i = 0; i < 42; i++)
    {
        //Calculate the sides of rect A
        leftA = a.x;
        rightA = a.x + a.w;
        topA = a.y;
        bottomA = a.y + a.h;

        //Calculate the sides of rect B
        leftB = obstacles[i].x;
        rightB = obstacles[i].x + obstacles[i].w;
        topB = obstacles[i].y;
        bottomB = obstacles[i].y + obstacles[i].h;

        if( (( bottomA <= topB ) || ( topA >= bottomB ) || ( rightA <= leftB ) || ( leftA >= rightB ) ) == false )
        {
                return true;
        }
    }

    return false;

}

bool checkCollisionWithPlayer(SDL_FRect a, SDL_FRect b)
{
    if(a.x >= b.x + b.w)
        return false;
    if(a.x + a.w <= b.x)
        return false;
    if(a.y >= b.y + b.h)
        return false;
    if(a.y + a.h <= b.y)
        return false;
    return true;
}
