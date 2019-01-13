#include "Sprite.h"

Sprite::Sprite()
:   _color({255, 255, 255, 255})
,   _angle(0)
{

}

Sprite::~Sprite()
{

}

void Sprite::tick()
{

}

void Sprite::load(const char *fileName)
{
    _texture = TextureManager::instance()->load(fileName);

    if (_texture == nullptr)
        return;

    SDL_QueryTexture(_texture, nullptr, nullptr, &_crop.w, &_crop.h);

    _crop.x = 0;
    _crop.y = 0;

    setSize(_crop.w, _crop.h);
}

SDL_Rect Sprite::getCrop() const
{
    return _crop;
}

void Sprite::setCrop(const SDL_Rect& crop)
{
    _crop = crop;
}

double Sprite::getAngle() const
{
    return _angle;
}

void Sprite::setAngle(double angle)
{
    _angle = angle;
}

SDL_Color Sprite::getColor() const
{
    return _color;
}

void Sprite::setColor(const SDL_Color& color)
{
    _color = color;
}

void Sprite::draw(SDL_Renderer *renderer)
{
    if (renderer == nullptr || _texture == nullptr)
        return;
    //    LOG_DEBUG("Draw " << this << " at " << getRect().x << ", " << getRect().y << " size " << getRect().w << ", " << getRect().h);
    SDL_Rect tempRect = getRect();

    SDL_SetTextureColorMod(_texture, _color.r, _color.g, _color.b);
    SDL_SetTextureAlphaMod(_texture, _color.a);

    SDL_RenderCopyEx(renderer, _texture, &_crop, &tempRect, _angle, nullptr, SDL_FLIP_NONE);

    SDL_SetTextureColorMod(_texture, 255, 255, 255);
    SDL_SetTextureAlphaMod(_texture, 255);

}
