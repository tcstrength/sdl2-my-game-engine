#ifndef SPRITE_H
#define SPRITE_H

#include "../Intefaces/NonCopyable.h"
#include "../Intefaces/Drawable.h"
#include "../Objects/AbstractObject.h"
#include "../Managers/TextureManager.h"

class Sprite :
public AbstractObject,
public Drawable,
public NonCopyable
{
public:
    Sprite();

    virtual ~Sprite();

    virtual void tick();

    virtual void draw(SDL_Renderer* renderer);

    void load(const char* fileName);

    SDL_Rect getCrop() const;

    void setCrop(const SDL_Rect& crop);

    double getAngle() const;

    void setAngle(double angle);

    SDL_Color getColor() const;

    void setColor(const SDL_Color& color);

private:
    SDL_Texture* _texture;
    SDL_Rect _crop;
    SDL_Color _color;
    double _angle;
};

#endif // SPRITE_H
