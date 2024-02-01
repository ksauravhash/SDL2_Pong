#include "CircleCollider.hpp"

#include "RectCollider.hpp"

CircleCollider::CircleCollider() : r(0)
{
}

ColliderShape CircleCollider::GetColliderShape()
{
    return ColliderShape::CIRCLE;
}

int CircleCollider::GetR()
{
    return r;
}

void CircleCollider::SetR(int r)
{
    this->r = r;
}

int CircleCollider::GetX()
{
    return x;
}

void CircleCollider::SetX(int x)
{
    this->x = x;
}

int CircleCollider::GetY()
{
    return x;
}

void CircleCollider::SetY(int y)
{
    this->y = y;
}
