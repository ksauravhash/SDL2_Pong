#include "Game.hpp"

int main()
{
    Game g;
    g.Init(200, 200, 0, 0, "Title");
    g.AddComponent(ComponentType::Ball, "ball");
    g.AddComponent(ComponentType::Paddle, "paddle1");
    g.Run(60);
    return 0;
}