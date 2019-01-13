#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <map>
#include "../Utils/Log.h"

class TextureManager
{
public:
    static TextureManager* instance();

    void init(SDL_Renderer* renderer);

    SDL_Texture* find(const char* fileName);

    SDL_Texture* load(const char* fileName);

    void loadList(const char* listFileName);
private:
    TextureManager();

    ~TextureManager();

    std::map<const char*, SDL_Texture*> _textures;

    SDL_Renderer* _renderer;
};

#endif // TEXTUREMANAGER_H
