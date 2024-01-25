#pragma once
#include "ColliderGeometry.hpp"
#include "RectCollider.hpp"

class Collider
{
public:
    Collider(ColliderShape shape)
    {
        switch (shape)
        {
        case ColliderShape::RECTANGE:
            geomtry = new RectCollider();
            break;

        default:
            break;
        }
    }

    bool isColliding(const Collider collider);

private:
    ColliderGeometry *geomtry;
};