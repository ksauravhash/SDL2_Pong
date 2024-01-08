
class GameObject
{
public:
    GameObject();

    virtual void Init() = 0;

    virtual void Update() = 0;

    virtual void Render() = 0;

    virtual void GetCollider() = 0;

    virtual void GetTransform() = 0;
};
