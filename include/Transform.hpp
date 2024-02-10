#pragma once

#include <SDL2/SDL.h>

class Transform
{
public:
    int GetPositionX();

    int GetPositionY();

    void SetPositionX(int x);

    void SetPositionY(int y);

    void SetVelocityX(int vx);

    void SetVelocityY(int vy);

    void Update();

    void SetDimension(int w, int h);

    int GetWidth();

    int GetHeight();

    SDL_Rect ToSDL_Rect();

private:
    int x, y;
    int w, h;
    int velocityX, velocityY;
};