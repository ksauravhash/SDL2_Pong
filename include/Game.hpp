#pragma once

#include <SDL2/SDL.h>
#include <unordered_map>
#include <string>
#include <memory>
#include "GameObject.hpp"
#include "ComponentType.hpp"

class Game
{
public:
    void Init(int width, int height, int x, int y, const char *title);

    void Run(int maxFrameRate);

    void AddComponent(ComponentType type, std::string name);

    std::unique_ptr<GameObject> &GetComponent(std::string name);

private:
    std::unordered_map<std::string, std::unique_ptr<GameObject>> objectsMap;
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
