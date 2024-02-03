#include "Paddle.hpp"

Paddle::Paddle()
{
    collider = std::make_unique<Collider>(ColliderShape::RECTANGE);
    transform = std::make_unique<Transform>();
}

void Paddle::Init()
{
}

void Paddle::Update()
{
}

void Paddle::Render()
{
}

std::unique_ptr<Collider> &Paddle::GetCollider()
{
    return collider;
}

std::unique_ptr<Transform> &Paddle::GetTransform()
{
    return transform;
}