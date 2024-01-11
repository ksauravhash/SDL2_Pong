#include "Ball.hpp"

Ball::Ball()
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
