#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "map.h"
#include "fenetre.h"

map::map()
{

    mapObstacles[0] = {70, 34 + 66, 219 - 70, 52 - 34};
    mapObstacles[1] = {342, 42 + 66, 390 - 342, 81 - 42};
    mapObstacles[2] = {424, 20 + 66, 532 - 424, 41 - 20};
    mapObstacles[3] = {632, 26 + 66, 883 - 632, 55 - 26};
    mapObstacles[4] = {1309, 16 + 66, 1366 - 1309, 41 - 16};
    mapObstacles[5] = {0, 99 + 66, 103, 123 - 99};
    mapObstacles[6] = {342, 117 + 66, 388 - 342, 199 - 117};
    mapObstacles[7] = {198, 198 + 66, 1166 - 198, 223 - 198};
    mapObstacles[8] = {468, 162 + 66, 678 - 468, 178 - 162};
    mapObstacles[9] = {799, 117 + 66, 1063 - 799, 152 - 117};
    mapObstacles[10] = {1115, 70 + 66, 1141 - 1115, 197 - 70};
    mapObstacles[11] = {1142, 122 + 66, 1218 - 1142, 148 - 122};
    mapObstacles[12] = {1264, 99 + 66, 1366 - 1264, 123 - 99};
    mapObstacles[13] = {35, 204 + 66, 78 - 35, 291 - 204};
    mapObstacles[14] = {78, 240 + 66, 166 - 78, 276 - 240};
    mapObstacles[15] = {0, 301 + 66, 308, 325 - 307};
    mapObstacles[16] = {378, 296 + 66, 405 - 378, 403 - 296};
    mapObstacles[17] = {405, 356 + 66, 506 - 405, 375 - 356};
    mapObstacles[18] = {503, 303 + 66, 874 - 503, 327 - 303};
    mapObstacles[19] = {960, 274 + 66, 987 - 960, 383 - 274};
    mapObstacles[20] = {987, 326 + 66, 1097 - 987, 348 - 326};
    mapObstacles[21] = {1191, 303 + 66, 1366 - 1191, 327 - 303};
    mapObstacles[22] = {0, 403 + 66, 251, 429 - 403};
    mapObstacles[23] = {359, 403 + 66, 467 - 359, 703 - 403};
    mapObstacles[24] = {35, 503 + 66, 95 - 35, 703 - 503};
    mapObstacles[25] = {108, 663 + 66, 169 - 108, 679 - 663};
    mapObstacles[26] = {206, 503 + 66, 359 - 206, 550 - 503};
    mapObstacles[27] = {201, 603 + 66, 278 - 201, 620 - 603};
    mapObstacles[28] = {311, 587 + 66, 359 - 311, 606 - 587};
    mapObstacles[29] = {256, 654 + 66, 342 - 256, 675 - 654};
    mapObstacles[30] = {500, 447 + 66, 551 - 500, 668 - 447};
    mapObstacles[31] = {500, 667 + 66, 653 - 500, 703 - 667};
    mapObstacles[32] = {613, 403 + 66, 825 - 613, 424 - 403};
    mapObstacles[33] = {603, 501 + 66, 903 - 603, 558 - 501};
    mapObstacles[34] = {664, 597 + 66, 805 - 664, 622 - 597};
    mapObstacles[35] = {726, 678 + 66, 903 - 726, 703 - 678};
    mapObstacles[36] = {903, 383 + 66, 1168 - 903, 703 - 383};
    mapObstacles[37] = {1168, 471 + 66, 1257 - 1168, 506 - 471};
    mapObstacles[38] = {1168, 667 + 66, 1314 - 1168, 690 - 667};
    mapObstacles[39] = {1266, 592 + 66, 1366 - 1266, 648 - 592};
    mapObstacles[40] = {1301, 363 + 66, 1331 - 1301, 458 - 363};
    mapObstacles[41] = {1302, 510 + 66, 1366 - 1302, 566 - 510};
}

map::~map()
{
    delete this;
}

SDL_FRect *map::getmapObstacles()
{
    return mapObstacles;
}

void map::renderMap()
{
    IMG_Init(IMG_INIT_JPG);

    SDL_Surface* mapSurface = IMG_Load("utilities/img/map.jpg");

    if(mapSurface == NULL)
    {
        printf("map loaded incorrectly");
        return;
    }

    mapTexture = SDL_CreateTextureFromSurface(fenetre::renderer, mapSurface);
    SDL_FreeSurface(mapSurface);
    
    for(int i = 0; i < 43; i++)
        SDL_RenderCopyF(fenetre::renderer, mapTexture, NULL, &mapObstacles[i]);
    
    IMG_Quit();
}




