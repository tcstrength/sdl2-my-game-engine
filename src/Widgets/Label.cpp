#include "Label.h"

Label::Label()
{
    _text.setMsg("Label");
}

Label::~Label()
{

}

void Label::update()
{
    Uint8 r = rand() % 128 + 128;
    Uint8 g = rand() % 128 + 128;
    Uint8 b = rand() % 128 + 128;
    _text.setColor({r, g, b, 255});
}

void Label::draw(SDL_Renderer *renderer)
{
    _text.draw(renderer);
}

std::string Label::getMsg() const
{
    return _text.getMsg();
}

void Label::setMsg(const std::string& msg)
{
    _text.setMsg(msg);
}

void Label::setRect(const SDL_Rect& rect)
{
    _text.setRect(rect);
}

SDL_Rect Label::getRect()
{
    return _text.getRect();
}
