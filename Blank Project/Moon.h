#pragma once
#include "nclgl/SceneNode.h"

class Moon : public SceneNode
{
public:
    Moon(float radius, Vector3 const &pos = Vector3(0, 0, 0));
    ~Moon();

    float GetRadius() const { return GetModelScale().x; }
};
