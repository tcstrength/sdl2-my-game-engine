#include "Button.h"

Button::Button()
{
    _background.load("widgets/button.png", 16);
    setSize(300, 48);
    setMsg("Push Button");
    update();
}

Button::~Button()
{

}

void Button::update()
{
    switch(_currentState)
    {
    case WidgetState::Selected:
        _background.setColor({51, 153, 255, 255});
        _foreground.setColor({255, 255, 255, 255});
        break;
    case WidgetState::Unselected:
    case WidgetState::Hover:
        _background.setColor({75, 75, 75, 255});
        _foreground.setColor({155, 220, 255, 255});
        break;
    default:
        _background.setColor({75, 75, 75, 255});
        _foreground.setColor({140, 205, 255, 255});
        break;
    }
}

void Button::draw(SDL_Renderer* renderer)
{
    _background.draw(renderer);
    _foreground.draw(renderer);
}

std::string Button::getMsg() const
{
    return _foreground.getMsg();
}

void Button::setMsg(const std::string& msg)
{
    _foreground.setMsg(msg);

    SDL_Rect rect = _background.getRect();
    setRect(rect);
}

void Button::setRect(const SDL_Rect& rect)
{
    _background.setRect(rect);

    SDL_Rect fgRect = _foreground.getRect();
    fgRect.x = rect.x + rect.w / 2 - fgRect.w / 2;
    fgRect.y = rect.y + rect.h / 2 - fgRect.h / 2;
    _foreground.setRect(fgRect);
}

SDL_Rect Button::getRect()
{
    return _background.getRect();
}


