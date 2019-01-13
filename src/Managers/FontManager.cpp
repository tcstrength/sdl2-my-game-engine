#include "FontManager.h"

FontManager::FontManager()
{
    LOG_DEBUG("Open FontManager " << this);
}

FontManager::~FontManager()
{
    LOG_DEBUG("Close FontManager " << this);

    for (auto f : _fonts)
        TTF_CloseFont(f);
}

FontManager* FontManager::instance()
{
    static FontManager fm;

    return &fm;
}

void FontManager::init(SDL_Renderer *renderer, std::string fontPath)
{
    _renderer = renderer;
    _fontPath = fontPath;

    for (int i = 0; i < 48; ++i)
    {
        _fonts.push_back(TTF_OpenFont(_fontPath.c_str(), i + 1));
        if (_fonts.back() == nullptr)
        {
            LOG_DEBUG("Could not open font " << fontPath);
            return;
        }
    }
}

TTF_Font* FontManager::font(uint size)
{
    if (_renderer == nullptr)
    {
        LOG_DEBUG("You need to initialize FontManager first");
        return nullptr;
    }

    if (size <= 0)
        return _fonts[0];

    if (size > _fonts.size())
        return _fonts[47];

    return _fonts[size - 1];
}

SDL_Texture*FontManager::createTexture(const char* msg, uint size, const SDL_Color& color)
{
    SDL_Surface* surf = TTF_RenderUTF8_Blended(font(size), msg, color);

    if (surf == nullptr)
    {
        LOG_ERROR("TTF could not render utf8 " << msg << " size " << size);
        return nullptr;
    }

    SDL_Texture* txr = SDL_CreateTextureFromSurface(_renderer, surf);

    SDL_FreeSurface(surf);

    return txr;
}






















