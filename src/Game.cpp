#include "Game.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

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

void Game::AddComponent(ComponentType type, std::string name)
{
    switch (type)
    {
    case ComponentType::Ball:
    {
        std::unique_ptr<Ball> ballObject = std::make_unique<Ball>();
        if (ballObject != nullptr)
        {
            objectsMap.insert(std::make_pair(name, ballObject));
        }
    }
    case ComponentType::Paddle:
    {
        std::unique_ptr<Paddle> ballObject = std::make_unique<Paddle>();
        if (ballObject != nullptr)
        {
            objectsMap.insert(std::make_pair(name, ballObject));
        }
    }
    break;

    default:
        break;
    }
}

std::unique_ptr<GameObject> &Game::GetComponent(std::string name)
{
    return objectsMap[name];
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
    for (auto &object : objectsMap)
    {
        if (object.second != nullptr)
            object.second->Update();
    }
}

void Game::HandleRender()
{
    for (auto &object : objectsMap)
    {
        if (object.second != nullptr)
            object.second->Render();
    }
    SDL_RenderPresent(renderer);
}
