#ifndef MAP_H
#define MAP_H

class map
{
    public:
        /*Dimension of the map*/
        static const int MAP_WIDTH = 1366;
        static const int MAP_HEIGHT = 786;

        /*map constructor's*/
        map();

        /*map destructor's*/
        ~map();

        /*getters*/
        SDL_FRect *getmapObstacles();

        /*rendering obstacles and map texture*/
        void renderMap();

    private:
        /*map obstacles*/
        SDL_FRect mapObstacles[42];
        SDL_Texture* mapTexture;
};


#endif
