#ifndef TEXT_H
#define TEXT_H

#include "../Intefaces/NonCopyable.h"
#include "../Intefaces/Drawable.h"
#include "../Objects/AbstractObject.h"
#include "../Managers/FontManager.h"

class Text:
public AbstractObject,
public Drawable,
public NonCopyable
{
public:
    Text();

    virtual ~Text();

    void update();

    void tick();

    void draw(SDL_Renderer* renderer);

    uint getSize() const;

    void setSize(const uint& size);

    std::string getMsg() const;

    void setMsg(const std::string& msg);

    SDL_Color getColor() const;

    void setColor(const SDL_Color& color);

private:
    SDL_Texture* _texture;
    std::string _msg;
    uint _size;
    SDL_Rect _crop;
    SDL_Color _color;
};

#endif // TEXT_H
