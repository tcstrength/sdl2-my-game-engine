#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL2/SDL.h>

class InputHandler
{
public:
    virtual void keyPressEvent(SDL_KeyboardEvent& e);

    virtual void keyReleaseEvent(SDL_KeyboardEvent& e);

    virtual void mousePressEvent(SDL_MouseButtonEvent& e);

    virtual void mouseReleaseEvent(SDL_MouseButtonEvent& e);

    virtual void mouseMoveEvent(SDL_MouseButtonEvent& e);
};

#endif // INPUTHANDLER_H
