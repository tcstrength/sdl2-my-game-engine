#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "AbstractObject.h"
#include "../Intefaces/Drawable.h"
#include "../Intefaces/NonCopyable.h"

class GameObject:
public AbstractObject,
public Drawable,
public NonCopyable
{
public:
    GameObject();

    ~GameObject();

    void tick();

    void draw(SDL_Renderer* renderer);
private:
};

#endif // GAMEOBJECT_H
