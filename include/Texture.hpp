#include "SDL2/SDL_image.h"
#include "string"

class Texture
{
public:
    static SDL_Texture *loadImage(SDL_Renderer *renderer, std::string filePath);
};