#include "Text.h"

Text::Text()
:   _msg("")
,   _size(18)
,   _crop({0, 0, 0, 0})
,   _color({255, 255, 255, 255})
{

}

Text::~Text()
{
    SDL_DestroyTexture(_texture);
}

void Text::update()
{
    if (_texture != nullptr)
        SDL_DestroyTexture(_texture);

    _texture = FontManager::instance()->createTexture(_msg.c_str(), _size, _color);

    if (_texture == nullptr)
        return;

    SDL_QueryTexture(_texture, nullptr, nullptr, &_crop.w, &_crop.h);
    _crop.x = 0;
    _crop.y = 0;

    AbstractObject::setSize(_crop.w, _crop.h);
}

void Text::tick()
{

}

void Text::draw(SDL_Renderer *renderer)
{
    if (renderer == nullptr || _texture == nullptr)
        return;
    SDL_Rect tempRect = getRect();

    SDL_RenderCopy(renderer, _texture, &_crop, &tempRect);
}

uint Text::getSize() const
{
    return _size;
}

void Text::setSize(const uint& size)
{
    _size = size;
    update();
}

std::string Text::getMsg() const
{
    return _msg;
}

void Text::setMsg(const std::string& msg)
{
    _msg = msg;
    update();
}

SDL_Color Text::getColor() const
{
    return _color;
}

void Text::setColor(const SDL_Color& color)
{
    _color = color;
    update();
}
