#include "ElasticSprite.h"

ElasticSprite::ElasticSprite()
{

}

ElasticSprite::~ElasticSprite()
{

}

void ElasticSprite::load(const char* fileName, int borderSize)
{
    Sprite::load(fileName);
    _borderSize = borderSize;
}

void ElasticSprite::tick()
{

}

void ElasticSprite::draw(SDL_Renderer* renderer)
{
    int borderSizeX2 = 2 * _borderSize;
    SDL_Rect crop = getCrop();
    SDL_Rect crops[9] = {
        {crop.x                       , crop.y                       , _borderSize          , _borderSize},
        {crop.x + _borderSize         , crop.y                       , crop.w - borderSizeX2, _borderSize},
        {crop.x + crop.w - _borderSize, crop.y                       , _borderSize          , _borderSize},

        {crop.x                       , crop.y + _borderSize         , _borderSize          , crop.h - borderSizeX2},
        {crop.x + _borderSize         , crop.y + _borderSize         , crop.w - borderSizeX2, crop.h - borderSizeX2},
        {crop.x + crop.w - _borderSize, crop.y + _borderSize         , _borderSize          , crop.h - borderSizeX2},

        {crop.x                       , crop.y + crop.h - _borderSize, _borderSize          , _borderSize},
        {crop.x + _borderSize         , crop.y + crop.h - _borderSize, crop.w - borderSizeX2, _borderSize},
        {crop.x + crop.w - _borderSize, crop.y + crop.h - _borderSize, _borderSize          , _borderSize}
    };

    SDL_Rect rect = getRect();
    SDL_Rect rects[9] = {
        {rect.x                       , rect.y                        , _borderSize          , _borderSize},
        {rect.x + _borderSize         , rect.y                        , rect.w - borderSizeX2, _borderSize},
        {rect.x + rect.w - _borderSize, rect.y                        , _borderSize          , _borderSize},

        {rect.x                       , rect.y + _borderSize          , _borderSize          , rect.h - borderSizeX2},
        {rect.x + _borderSize         , rect.y + _borderSize          , rect.w - borderSizeX2, rect.h - borderSizeX2},
        {rect.x + rect.w - _borderSize, rect.y + _borderSize          , _borderSize          , rect.h - borderSizeX2},

        {rect.x                       , rect. y + rect.h - _borderSize, _borderSize          , _borderSize},
        {rect.x + _borderSize         , rect. y + rect.h - _borderSize, rect.w - borderSizeX2, _borderSize},
        {rect.x + rect.w - _borderSize, rect. y + rect.h - _borderSize, _borderSize          , _borderSize},
    };

    for (int i = 0; i < 9; ++i)
    {
        setRect(rects[i]);
        setCrop(crops[i]);
        Sprite::draw(renderer);
    }

    setRect(rect);
    setCrop(crop);
}


