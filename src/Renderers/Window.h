#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_cpuinfo.h>
#include <SDL2/SDL_shape.h>
#include <vector>

#include "../Utils/Log.h"
#include "../Intefaces/NonCopyable.h"
#include "../Intefaces/Drawable.h"
#include "../Entities/InputHandler.h"

class Window :
public NonCopyable
{
public:
    Window(const char* title, int w, int h, bool fullscreen = false);

    ~Window();

    void     addInputHandler(InputHandler* inputHandler);

    bool     isOpen();

    void     begin();

    void     end();

    void     setRect(const SDL_Rect& rect);

    SDL_Rect getRect();

    inline SDL_Renderer* getRenderer() { return _renderer; }

    inline SDL_Event* getEvent() { return _event; }

private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    SDL_Event* _event;
    bool _isOpen;
    std::vector<InputHandler*> _inputs;
};
#endif // WINDOW_H
