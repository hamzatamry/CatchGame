#include <SDL2/SDL.h>
#include "timer.h"

timer::timer()
{
    mStartTicks = 0;
    mPausedTicks = 0;

    mPaused = false;
    mStarted = false;
}

void timer::start()
{
    mStarted = true;
    mPaused = false;

    mStartTicks = SDL_GetTicks();
    mPausedTicks = 0;
}

void timer::stop()
{
    mStarted = false;
    mPaused = true;

    mStartTicks = 0;
    mPausedTicks = 0;
}

void timer::pause()
{
    if(mStarted && !mPaused)
    {
        mPaused = true;
        mPausedTicks = SDL_GetTicks() - mStartTicks;
        mStartTicks = 0;
    }
}

void timer::unpause()
{
    if(mStarted && mPaused)
    {
        mPaused = false;

        mStartTicks = SDL_GetTicks() - mPausedTicks;
        mPausedTicks = 0;
    }
}

Uint32 timer::getTicks()
{
    Uint32 time = 0;
    if( mStarted )
    {
        if( mPaused )
        {

            time = mPausedTicks;
        }
        else
        {
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
}

bool timer::isStarted()
{
    return mStarted;
}

bool timer::isPaused()
{
    return mPaused && mStarted;
}
