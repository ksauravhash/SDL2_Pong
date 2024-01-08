#include "Transform.hpp"

int Transform::GetPositionX()
{
    return x;
}

int Transform::GetPositionY()
{
    return y;
}

void Transform::SetPositionX(int x)
{
    this->x = x;
}

void Transform::SetPositionY(int y)
{
    this->y = y;
}

void Transform::SetVelocityX(int vx)
{
    this->velocityX = vx;
}

void Transform::SetVelocityY(int vy)
{
    this->velocityY = vy;
}

void Transform::Update()
{

    this->x += velocityX;
    this->y += velocityY;
}

void Transform::SetDimension(int w, int h)
{
    this->w = w;
    this->h = h;
}

int Transform::GetWidth()
{
    return w;
}

int Transform::GetHeight()
{
    return h;
}
