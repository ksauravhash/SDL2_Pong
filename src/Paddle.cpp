#include "Paddle.hpp"

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
