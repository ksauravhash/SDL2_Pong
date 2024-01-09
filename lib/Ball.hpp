#include "GameObject.hpp"

class Ball : public GameObject
{
public:
    void Update() override;

    void Render() override;

    Collider &GetCollider() override;

    Transform &GetTransform() override;

private:
    Transform *transform;
    Collider *collider;
};