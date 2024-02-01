#pragma once
#include "ColliderGeometry.hpp"

class CircleCollider : public ColliderGeometry
{
public:
    CircleCollider();

    int GetX();

    void SetX(int x);

    int GetY();

    void SetY(int y);

    int GetR();

    void SetR(int r);

    ColliderShape GetColliderShape() override;

private:
    int r;
    int x, y;
};