#ifndef LABEL_H
#define LABEL_H

#include "Widget.h"

class Label :
public Widget
{
public:
    Label();

    virtual ~Label();

    void update();

    void draw(SDL_Renderer* renderer);

    std::string getMsg() const;

    void setMsg(const std::string& msg);

    void setRect(const SDL_Rect& rect);

    SDL_Rect getRect();

private:
    Text _text;
};

#endif // LABEL_H
