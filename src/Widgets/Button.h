#ifndef BUTTON_H
#define BUTTON_H

#include "Widget.h"

class Button : public Widget
{
public:
    Button();

    ~Button();

    void update();

    void draw(SDL_Renderer* renderer);

    std::string getMsg() const;

    void setMsg(const std::string& msg);

    void setRect(const SDL_Rect& rect);

    SDL_Rect getRect();

private:
    ElasticSprite _background;
    Text _foreground;
};

#endif // BUTTON_H
