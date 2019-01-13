#include "Drawable.h"

Drawable::Drawable()
{

}

Drawable::~Drawable()
{
}

void Drawable::tick()
{
    LOG_DEBUG("Drawable " << this << " is missing tick!");
}

void Drawable::draw(SDL_Renderer *renderer)
{
    LOG_DEBUG("Drawable " << this << " is missing draw!");
}
