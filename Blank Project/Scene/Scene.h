#pragma once
#include "Terrain.h"
#include "nclgl/SceneNode.h"

class Scene : public SceneNode
{
public:
    Scene(OGLRenderer &r, Camera *&camera);
    ~Scene();

protected:
    Terrain *terrain;
};
