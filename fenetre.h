#ifndef FENETRE_H
#define FENETRE_H

class fenetre
{

public:
    static const int FENETRE_WIDTH = 1366;
    static const int FENETRE_HEIGHT = 768;
    static SDL_Window *window;
    static SDL_Renderer *renderer;


    fenetre();
    ~fenetre();

    friend class map;
    friend class player;
};


#endif
