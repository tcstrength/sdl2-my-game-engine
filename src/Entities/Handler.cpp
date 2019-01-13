#include "Handler.h"

Handler::Handler()
{

}

Handler::~Handler()
{
    _widgets.clear();
}

void Handler::draw(SDL_Renderer* renderer)
{
    for (auto wd : _widgets)
        wd->draw(renderer);
}

void Handler::tick()
{
    for (auto wd : _widgets)
        wd->tick();
}

Widget* Handler::addWidget(Widget* widget)
{
    if (widget != nullptr)
        _widgets.push_back(widget);

    return widget;
}

void Handler::delWidget(Widget *widget)
{
    _widgets.remove(widget);
}

void Handler::keyPressEvent(SDL_KeyboardEvent& e)
{
    for (auto wd : _widgets)
        wd->keyPressEvent(e);
}

void Handler::keyReleaseEvent(SDL_KeyboardEvent& e)
{
    for (auto wd : _widgets)
        wd->keyReleaseEvent(e);
}

void Handler::mousePressEvent(SDL_MouseButtonEvent& e)
{
    for (auto wd : _widgets)
        wd->mousePressEvent(e);
}

void Handler::mouseReleaseEvent(SDL_MouseButtonEvent& e)
{
    for (auto wd : _widgets)
        wd->mouseReleaseEvent(e);
}

void Handler::mouseMoveEvent(SDL_MouseButtonEvent& e)
{
    for (auto wd : _widgets)
        wd->mouseMoveEvent(e);
}
