#pragma once

#include "GameObject.hpp"

class Paddle : public GameObject
{
public:
    Paddle();

    void Init() override;

    void Update() override;

    void Render(SDL_Renderer *renderer) override;

    std::unique_ptr<Collider> &GetCollider() override;

    std::unique_ptr<Transform> &GetTransform() override;

private:
    std::unique_ptr<Transform> transform;
    std::unique_ptr<Collider> collider;
};