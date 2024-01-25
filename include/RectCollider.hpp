#pragma once
#include "ColliderGeometry.hpp"

class RectCollider : public ColliderGeometry
{
public:
    RectCollider();

    int GetX();

    int GetY();

    int GetWidth();

    int GetHeight();

    void SetX(int x);

    void SetY(int y);

    void SetWidth(int width);

    void SetHeight(int height);

    ColliderShape GetColliderShape() override;

private:
    int x, y;
    int w, h;
};