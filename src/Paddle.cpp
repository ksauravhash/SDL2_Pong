#include "Paddle.hpp"

Paddle::Paddle()
{
    collider = std::make_unique<Collider>(ColliderShape::RECTANGE);
    transform = std::make_unique<Transform>();
}

void Paddle::Init()
{
    transform->SetDimension(10, 100);
    transform->SetPositionX(0);
    transform->SetPositionX(0);
    RectCollider *rectCollider = (RectCollider *)collider.get();
    rectCollider->SetWidth(10);
    rectCollider->SetHeight(100);
    rectCollider->SetX(0);
    rectCollider->SetY(0);
}

void Paddle::Update()
{
    transform->Update();
    RectCollider *rectCollider = (RectCollider *)collider.get();
    rectCollider->SetX(transform->GetPositionX());
    rectCollider->SetY(transform->GetPositionY());
    rectCollider->SetWidth(transform->GetWidth());
    rectCollider->SetHeight(transform->GetHeight());
}

void Paddle::Render(SDL_Renderer *renderer)
{
    SDL_Rect rect = transform->ToSDL_Rect();
    printf("%d %d %d %d\n", rect.x, rect.y, rect.w, rect.h);
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderFillRect(renderer, &rect);
}

std::unique_ptr<Collider> &Paddle::GetCollider()
{
    return collider;
}

std::unique_ptr<Transform> &Paddle::GetTransform()
{
    return transform;
}