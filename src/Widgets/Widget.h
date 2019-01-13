#ifndef WIDGET_H
#define WIDGET_H

#include "../Renderers/Text.h"
#include "../Renderers/ElasticSprite.h"
#include "../Renderers/Sprite.h"

class Widget :
public Drawable,
public NonCopyable
{
public:
    enum WidgetState
    {
        Leave,
        Hover,
        Selected,
        Unselected,
        Focused,
    };

    Widget();

    virtual ~Widget();

    virtual void update();

    virtual void tick();

    virtual void draw(SDL_Renderer* renderer) = 0;

    virtual void keyPressEvent(SDL_KeyboardEvent& e);

    virtual void keyReleaseEvent(SDL_KeyboardEvent& e);

    virtual void mousePressEvent(SDL_MouseButtonEvent& e);

    virtual void mouseReleaseEvent(SDL_MouseButtonEvent& e);

    virtual void mouseMoveEvent(SDL_MouseButtonEvent& e);

            bool hit(int mx, int my);

            void setPos(int x, int y);

            void setSize(int w, int h);

            WidgetState getState();

    virtual void setRect(const SDL_Rect& rect) = 0;

    virtual SDL_Rect getRect() = 0;
protected:
    WidgetState _lastState;
    WidgetState _currentState;
    bool _hidden;
};

#endif // WIDGET_H
