#include "Collider.hpp"
#include <cmath>

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
    bool colliding = false;
    if (this->geomtry->GetColliderShape() == ColliderShape::RECTANGE && collider.geomtry->GetColliderShape() == ColliderShape::RECTANGE)
    {
        RectCollider *rect1 = (RectCollider *)this->geomtry;
        RectCollider *rect2 = (RectCollider *)collider.geomtry;

        if ((rect1->GetX() >= rect2->GetX() + rect2->GetWidth() && rect1->GetY() >= rect2->GetY() + rect2->GetHeight()) && (rect2->GetX() >= rect1->GetX() + rect1->GetWidth() && rect2->GetY() >= rect1->GetY() + rect1->GetHeight()))
            colliding = true;
    }
    else if (this->geomtry->GetColliderShape() == ColliderShape::CIRCLE && collider.geomtry->GetColliderShape() == ColliderShape::CIRCLE)
    {
        CircleCollider *c1 = (CircleCollider *)this->geomtry;
        CircleCollider *c2 = (CircleCollider *)collider.geomtry;
        double distance = std::sqrt(std::pow(c1->GetX() - c2->GetX(), 2) + std::pow(c1->GetY() - c2->GetY(), 2));
        if (distance < c1->GetR() + c2->GetR())
            colliding = true;
    }
    else if (this->geomtry->GetColliderShape() == ColliderShape::CIRCLE && collider.geomtry->GetColliderShape() == ColliderShape::RECTANGE)
    {
        CircleCollider *c1 = (CircleCollider *)this->geomtry;
        RectCollider *r2 = (RectCollider *)collider.geomtry;
        int testX = c1->GetX();
        int testY = c1->GetY();

        // which edge is closest?
        if (c1->GetX() < r2->GetX())
            testX = r2->GetX(); // test left edge
        else if (c1->GetX() > r2->GetX() + r2->GetWidth())
            testX = r2->GetX() + r2->GetWidth(); // right edge
        if (c1->GetY() < r2->GetY())
            testY = r2->GetY(); // top edge
        else if (c1->GetY() > r2->GetY() + r2->GetHeight())
            testY = r2->GetY() + r2->GetHeight(); // bottom edge

        double distance = sqrt(pow(testX - c1->GetX(), 2) + pow(testY - c1->GetY(), 2));
        if (distance <= c1->GetR())
            colliding = true;
    }
    else if (this->geomtry->GetColliderShape() == ColliderShape::CIRCLE && collider.geomtry->GetColliderShape() == ColliderShape::RECTANGE)
    {
        CircleCollider *c1 = (CircleCollider *)collider.geomtry;
        RectCollider *r2 = (RectCollider *)this->geomtry;
        int testX = c1->GetX();
        int testY = c1->GetY();

        // which edge is closest?
        if (c1->GetX() < r2->GetX())
            testX = r2->GetX(); // test left edge
        else if (c1->GetX() > r2->GetX() + r2->GetWidth())
            testX = r2->GetX() + r2->GetWidth(); // right edge
        if (c1->GetY() < r2->GetY())
            testY = r2->GetY(); // top edge
        else if (c1->GetY() > r2->GetY() + r2->GetHeight())
            testY = r2->GetY() + r2->GetHeight(); // bottom edge

        double distance = sqrt(pow(testX - c1->GetX(), 2) + pow(testY - c1->GetY(), 2));
        if (distance <= c1->GetR())
            colliding = true;
    }

    return colliding;
}