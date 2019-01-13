#include "Window.h"

Window::Window(const char* title, int w, int h, bool fullscreen)
:   _isOpen(false)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    TTF_Init();

    if (fullscreen)
    {
        SDL_DisplayMode displayMode;
        if (SDL_GetCurrentDisplayMode(0, &displayMode))
        {
            LOG_DEBUG("Could not get current display mode for video display 0 " << SDL_GetError());
            return;
        }

        _window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, displayMode.w, displayMode.h, SDL_WINDOW_FULLSCREEN);
    }
    else
    {
        _window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_OPENGL);
    }


    if (_window == nullptr)
    {
        LOG_DEBUG("Could not create Window " << SDL_GetError());
        return;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    if (_renderer == nullptr)
    {
        LOG_DEBUG("Could not create Renderer " << SDL_GetError());
        return;
    }

    _event = new SDL_Event;
    _isOpen = true;
}

Window::~Window()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Window::addInputHandler(InputHandler* inputHandler)
{
    if (inputHandler != nullptr)
        _inputs.push_back(inputHandler);
}

void Window::setRect(const SDL_Rect &rect)
{
    SDL_SetWindowSize(_window, rect.w, rect.h);
    SDL_SetWindowPosition(_window, rect.x, rect.y);
}

SDL_Rect Window::getRect()
{
    SDL_Rect rect;
    SDL_GetWindowSize(_window, &rect.w, &rect.h);
    SDL_GetWindowPosition(_window, &rect.x, &rect.y);
    return rect;
}

bool Window::isOpen()
{
    return _isOpen;
}

void Window::begin()
{
    while (SDL_PollEvent(_event))
    {
        if (_event->type == SDL_QUIT)
        {
            _isOpen = false;
            break;
        }
        else if (_inputs.empty() == false)
        {
            switch(_event->type)
            {
            case SDL_KEYDOWN:
                for (auto inp : _inputs)
                    inp->keyPressEvent(_event->key);
                break;

            case SDL_KEYUP:
                for (auto inp : _inputs)
                    inp->keyReleaseEvent(_event->key);
                break;

            case SDL_MOUSEBUTTONDOWN:
                for (auto inp : _inputs)
                    inp->mousePressEvent(_event->button);
                break;

            case SDL_MOUSEBUTTONUP:
                for (auto inp : _inputs)
                    inp->mouseReleaseEvent(_event->button);
                break;

            case SDL_MOUSEMOTION:
                for (auto inp : _inputs)
                    inp->mouseMoveEvent(_event->button);
                break;

            default:
                break;
            }
        }
    }

    SDL_RenderClear(_renderer);
}

void Window::end()
{
    SDL_RenderPresent(_renderer);
}
