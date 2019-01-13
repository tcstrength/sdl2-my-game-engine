#include "AbstractObject.h"

AbstractObject::AbstractObject()
:   _rect({0, 0, 0, 0})
{

}

AbstractObject::~AbstractObject()
{
}

void AbstractObject::setPos(int x, int y)
{
    _rect.x = x;
    _rect.y = y;
}

void AbstractObject::setSize(int w, int h)
{
    _rect.w = w;
    _rect.h = h;
}

void AbstractObject::setRect(SDL_Rect rect)
{
    _rect = rect;
}

SDL_Rect AbstractObject::getRect()
{
    return _rect;
}
