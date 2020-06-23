#ifndef PLAYER_H
#define PLAYER_H



class player
{
    public:
        
        static const int PLAYER_WIDTH = 8;
        static const int PLAYER_HEIGHT = 8;
        static float PLAYER_VELOCITY;
        static float gravity;
        bool collision;
        SDL_FRect collider;

        player();

        float getPosX() const; float getPosY() const;
        virtual void handleEvent(SDL_Event *e);
        void move(SDL_FRect Obstacles[42]);
        void render() const;

    protected:
        float posX, posY;
        float velX, velY;
        SDL_Texture* playerTexture;

};




#endif
