#include <SDL2/SDL.h>

class Game
{
public:
    void Init(int width, int height, int x, int y, const char *title);

    void Run(int maxFrameRate);

private:
    int height, width;

    const char *title;

    int maxFrameRate;

    int x, y;

    int isGameRunning = true;

    SDL_Window *window;

    SDL_Renderer *renderer;

    void HandleEvent();

    void HandleUpdate();

    void HandleRender();
};