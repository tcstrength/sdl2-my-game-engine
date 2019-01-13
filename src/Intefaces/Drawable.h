#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL2/SDL.h>

#include "../Utils/Log.h"

class Drawable
{
public:
    Drawable();

    virtual ~Drawable();

    virtual void tick();

    virtual void draw(SDL_Renderer* renderer);

};

#endif // DRAWABLE_H
