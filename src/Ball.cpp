#include "Ball.hpp"
#include "SDL2/SDL_image.h"
#include "Texture.hpp"

Ball::Ball()
{
    collider = std::make_unique<Collider>(ColliderShape::CIRCLE);
    transform = std::make_unique<Transform>();
}

void Ball::Init()
{
    transform->SetDimension(50, 50);
    transform->SetPositionX(0);
    transform->SetPositionX(0);
    CircleCollider *circleCollider = (CircleCollider *)collider.get();
    circleCollider->SetR(10);
    circleCollider->SetX(0);
    circleCollider->SetY(0);
}

void Ball::Update()
{
}

void Ball::Render(SDL_Renderer *renderer)
{
    if (ballTexure == nullptr)
        ballTexure = Texture::loadImage(renderer, "./assets/images/plain-circle.png");
    SDL_Rect src = {.x = 0, .y = 0, .w = 128, .h = 128};
    SDL_Rect dest = transform->ToSDL_Rect();
    SDL_RenderCopy(renderer, ballTexure, &src, &dest);
}

std::unique_ptr<Collider> &Ball::GetCollider()
{
    return collider;
}

std::unique_ptr<Transform> &Ball::GetTransform()
{
    return transform;
}

SDL_Texture *Ball::ballTexure = nullptr;
