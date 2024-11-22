#pragma once
#include "nclgl/SceneNode.h"

class Orb : public SceneNode
{
public:
    Orb(float radius, Vector3 pos);
    ~Orb();
};
