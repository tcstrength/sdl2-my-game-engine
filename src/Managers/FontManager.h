#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <SDL2/SDL_ttf.h>
#include <vector>
#include "../Utils/Log.h"

class FontManager
{
public:
    static FontManager* instance();

    void init(SDL_Renderer* renderer, std::string fontPath);

    TTF_Font* font(uint size);

    SDL_Texture* createTexture(const char* msg, uint size, const SDL_Color& color);

private:
    FontManager();

    ~FontManager();

    SDL_Renderer* _renderer;
    std::string _fontPath;
    std::vector<TTF_Font*> _fonts;
};

#endif // FONTMANAGER_H
