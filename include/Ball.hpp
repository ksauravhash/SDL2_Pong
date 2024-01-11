#pragma once

#include "GameObject.hpp"

class Ball : public GameObject
{
public:
    Ball();

    void Update() override;

    void Render() override;

    std::unique_ptr<Collider> &GetCollider() override;

    std::unique_ptr<Transform> &GetTransform() override;

private:
    std::unique_ptr<Transform> transform;
    std::unique_ptr<Collider> collider;
};