#include "Transform.hpp"
#include "Collider.hpp"

class GameObject
{
public:
    GameObject();

    virtual void Init() = 0;

    virtual void Update() = 0;

    virtual void Render() = 0;

    virtual Collider &GetCollider() = 0;

    virtual Transform &GetTransform() = 0;
};
