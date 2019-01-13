#ifndef HANDLER_H
#define HANDLER_H

#include "InputHandler.h"
#include "../Widgets/Label.h"
#include <list>

class Handler : public InputHandler
{
public:
    Handler();

    ~Handler();

    void tick();

    void draw(SDL_Renderer* renderer);

    Widget* addWidget(Widget* widget);

    void delWidget(Widget* widget);

    void keyPressEvent(SDL_KeyboardEvent& e);

    void keyReleaseEvent(SDL_KeyboardEvent& e);

    void mousePressEvent(SDL_MouseButtonEvent& e);

    void mouseReleaseEvent(SDL_MouseButtonEvent& e);

    void mouseMoveEvent(SDL_MouseButtonEvent& e);
private:
    std::list<Widget*> _widgets;
};

#endif // HANDLER_H
