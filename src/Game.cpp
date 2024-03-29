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
    Uint64 minDelay = 1 / maxFrameRate;
    Uint64 endCounter, elapsedTime;
    Uint64 perfFreq = SDL_GetPerformanceFrequency();
    Uint64 perfCounter = SDL_GetPerformanceCounter();

    while (isGameRunning)
    {
        HandleUpdate();
        HandleEvent();
        HandleRender();
        endCounter = SDL_GetPerformanceCounter();
        elapsedTime = endCounter - perfCounter;
        perfCounter = endCounter;
        if (minDelay > elapsedTime)
        {
            SDL_Delay(minDelay - elapsedTime);
        }
    }
}

void Game::AddComponent(ComponentType type, std::string name)
{
    switch (type)
    {
    case ComponentType::Ball:
    {
        std::unique_ptr<GameObject> ballObject = std::make_unique<Ball>();
        ballObject->Init();
        if (ballObject != nullptr)
        {
            objectsMap.emplace(name, std::move(ballObject));
        }
    }
    case ComponentType::Paddle:
    {
        std::unique_ptr<Paddle> paddleObject = std::make_unique<Paddle>();
        paddleObject->Init();
        if (paddleObject != nullptr)
        {
            objectsMap.emplace(name, std::move(paddleObject));
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
            isGameRunning = false;
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
            object.second->Render(renderer);
    }
    SDL_RenderPresent(renderer);
}
