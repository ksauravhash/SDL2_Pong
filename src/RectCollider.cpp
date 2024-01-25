#include "RectCollider.hpp"

RectCollider::RectCollider()
{
}

int RectCollider::GetX()
{
    return x;
}

int RectCollider::GetY()
{
    return y;
}

int RectCollider::GetWidth()
{
    return w;
}

int RectCollider::GetHeight()
{
    return h;
}

void RectCollider::SetX(int x)
{
    this->x = x;
}

void RectCollider::SetY(int y)
{
    this->y = y;
}

void RectCollider::SetWidth(int width)
{
    w = width;
}

void RectCollider::SetHeight(int height)
{
    h = height;
}

ColliderShape RectCollider::GetColliderShape()
{
    return ColliderShape::RECTANGE;
}
