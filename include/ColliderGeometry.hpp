#pragma once

enum class ColliderShape
{
    RECTANGE,
    CIRCLE
};

// Simply an interface for the types of Collider Geometry
class ColliderGeometry
{
public:
    virtual ColliderShape GetColliderShape() = 0;
};