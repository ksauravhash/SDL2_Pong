#include "Game.hpp"

void Game::Init(int width, int height, int x, int y, const char *title)
{
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Game::Run(int maxFrameRate)
{
    this->maxFrameRate = maxFrameRate;

    while (isGameRunning)
    {
        HandleUpdate();
        HandleEvent();
        HandleRender();
    }
}

void Game::HandleEvent()
{

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            isGameRunning = true;
    }
}

void Game::HandleUpdate()
{
}

void Game::HandleRender()
{
    SDL_RenderPresent(renderer);
}
