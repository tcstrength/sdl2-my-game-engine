#include "Widget.h"

Widget::Widget()
:   _lastState(WidgetState::Focused)
,   _currentState(WidgetState::Leave)
{

}

Widget::~Widget()
{

}

void Widget::setPos(int x, int y)
{
    SDL_Rect rect = getRect();
    rect.x = x;
    rect.y = y;
    setRect(rect);
}

void Widget::setSize(int w, int h)
{
    SDL_Rect rect = getRect();
    rect.w = w;
    rect.h = h;
    setRect(rect);
}

Widget::WidgetState Widget::getState()
{
    return _currentState;
}

bool Widget::hit(int mx, int my)
{
    SDL_Rect rect = getRect();
    return mx > rect.x &&
           my > rect.y &&
           mx < rect.x + rect.w &&
           my < rect.y + rect.h;
}

void Widget::update()
{

}

void Widget::tick()
{

}
void Widget::keyPressEvent(SDL_KeyboardEvent& e)
{
    LOG_DEBUG("Widget " << this << " got " << e.keysym.sym);
}

void Widget::keyReleaseEvent(SDL_KeyboardEvent& e)
{
    LOG_DEBUG("Widget " << this << " got " << e.keysym.sym);
}

void Widget::mousePressEvent(SDL_MouseButtonEvent& e)
{

    _lastState = _currentState;

    if (hit(e.x, e.y))
        _currentState = WidgetState::Selected;

    if (_lastState != _currentState)
        update();
}

void Widget::mouseReleaseEvent(SDL_MouseButtonEvent& e)
{
    _lastState = _currentState;

    if (hit(e.x, e.y))
        _currentState = WidgetState::Unselected;

    if (_lastState != _currentState)
        update();
}

void Widget::mouseMoveEvent(SDL_MouseButtonEvent& e)
{
    _lastState = _currentState;

    if (hit(e.x, e.y))
        _currentState = WidgetState::Hover;
    else
        _currentState = WidgetState::Leave;

    if (_lastState != _currentState)
        update();
}













