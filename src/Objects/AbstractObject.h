#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include "../Utils/Log.h"
#include <SDL2/SDL.h>

class AbstractObject
{
public:
    AbstractObject();

    virtual ~AbstractObject();

    void setPos(int x, int y);

    void setSize(int w, int h);

    void setRect(SDL_Rect rect);

    SDL_Rect getRect();
private:
    SDL_Rect _rect;
};

#endif // ABSTRACTOBJECT_H
