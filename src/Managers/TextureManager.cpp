#include "TextureManager.h"

TextureManager* TextureManager::instance()
{
    static TextureManager txrMan;
    return &txrMan;
}

TextureManager::TextureManager()
:   _renderer(nullptr)
{
    LOG_DEBUG("Open TextureManager " << this);
}

TextureManager::~TextureManager()
{
    for (auto it = _textures.begin(); it != _textures.end(); ++it)
    {
        LOG_DEBUG("Destroy Texture " << it->second);
        SDL_DestroyTexture(it->second);
    }

    LOG_DEBUG("Close TextureManager " << this);
}

void TextureManager::init(SDL_Renderer *renderer)
{
    _renderer = renderer;
}

SDL_Texture*  TextureManager::find(const char *fileName)
{
    SDL_Texture* txr = _textures[fileName];

    return txr;
}

SDL_Texture* TextureManager::load(const char* fileName)
{
    if (_renderer == nullptr)
    {
        LOG_ERROR("You need to init TextureManager first!");
        return nullptr;
    }

    SDL_Texture* txr = _textures[fileName];

    // Check if exists
    if (txr != nullptr)
        return txr;

    txr = IMG_LoadTexture(_renderer, fileName);

    LOG_DEBUG("Open Texture " << fileName << " at " << txr);

    if (txr == nullptr)
    {
        LOG_DEBUG("Could not load Texture " << fileName);
        return nullptr;
    }

    _textures[fileName] = txr;

    return txr;
}

void TextureManager::loadList(const char *listFileName)
{
    std::ifstream inStream(listFileName);
    std::string buffer;

    while(std::getline(inStream, buffer))
        load(buffer.c_str());
}
