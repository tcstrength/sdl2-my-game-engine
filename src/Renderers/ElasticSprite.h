#ifndef ELASTICSPRITE_H
#define ELASTICSPRITE_H

#include "Sprite.h"

/*
 * ------------------------------
 * . . ---------------------- . .
 * . .                        . .
 * . . ---------------------- . .
 * ------------------------------
 * Rect ở trong sẽ kéo theo rect ở ngoài
 * Và rect ở trong sẽ bằng rect ở ngoài - border
 * Lưu ý là nó sẽ kéo cả các góc ra, nên không làm ảnh hưởng đến việc bị nhòe
 * Riêng phần rect nhỏ thì sẽ bị nhòe
 */

class ElasticSprite :
public Sprite
{
public:
    ElasticSprite();

    virtual ~ElasticSprite();

    void load(const char* fileName, int borderSize);

    virtual void tick();

    virtual void draw(SDL_Renderer* renderer);
private:
    int _borderSize;
};

#endif // ELASTICSPRITE_H
