#pragma once
#include "Terrain.h"
#include "nclgl/SceneNode.h"

class Scene : public SceneNode
{
public:
    Scene(OGLRenderer &r, Camera *&camera);
    ~Scene();

    void SetIsRocky(bool isRocky);

protected:
    bool isRocky = true;
    Terrain *terrain;
};
