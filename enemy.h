#ifndef ENEMY_H
#define ENEMY_H

class enemy final : public player
{

    public:
        enemy();
        void handleEvent(SDL_Event *e) override;
};


#endif // ENEMY_H
