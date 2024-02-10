#pragma once

#include "Transform.hpp"
#include "Collider.hpp"
#include "memory"

class GameObject
{
public:
    virtual void Init() = 0;

    virtual void Update() = 0;

    virtual void Render(SDL_Renderer *renderer) = 0;

    virtual std::unique_ptr<Collider> &GetCollider() = 0;

    virtual std::unique_ptr<Transform> &GetTransform() = 0;
};
