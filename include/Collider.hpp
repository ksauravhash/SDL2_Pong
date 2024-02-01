#pragma once
#include "ColliderGeometry.hpp"
#include "RectCollider.hpp"
#include "CircleCollider.hpp"

class Collider
{
public:
    Collider(ColliderShape shape);

    bool isColliding(const Collider collider);

private:
    ColliderGeometry *geomtry;
};