#include "Ball.hpp"

Ball::Ball()
{
    collider = std::make_unique<Collider>(ColliderShape::CIRCLE);
    transform = std::make_unique<Transform>();
}

void Ball::Init()
{
}

void Ball::Update()
{
}

void Ball::Render()
{
}

std::unique_ptr<Collider> &Ball::GetCollider()
{
    return collider;
}

std::unique_ptr<Transform> &Ball::GetTransform()
{
    return transform;
}
