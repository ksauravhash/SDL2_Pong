#include "Collider.hpp"

Collider::Collider(ColliderShape shape)
{
    switch (shape)
    {
    case ColliderShape::RECTANGE:
        geomtry = new RectCollider();
        shape = ColliderShape::RECTANGE;
        break;
    case ColliderShape::CIRCLE:
        geomtry = new CircleCollider();
        shape = ColliderShape::CIRCLE;
        break;

    default:
        break;
    }
}

bool Collider::isColliding(const Collider collider)
{
    bool colling = false;
    if (this->geomtry->GetColliderShape() == ColliderShape::RECTANGE && collider.geomtry->GetColliderShape() == ColliderShape::RECTANGE)
    {
        RectCollider *rect1 = (RectCollider *)this->geomtry;
        RectCollider *rect2 = (RectCollider *)collider.geomtry;

        if ((rect1->GetX() >= rect2->GetX() + rect2->GetWidth() && rect1->GetY() >= rect2->GetY() + rect2->GetHeight()) && (rect2->GetX() >= rect1->GetX() + rect1->GetWidth() && rect2->GetY() >= rect1->GetY() + rect1->GetHeight()))
            colling = true;
    }

    return colling;
}