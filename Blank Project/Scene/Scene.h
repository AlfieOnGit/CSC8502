#pragma once
#include "Terrain.h"
#include "nclgl/SceneNode.h"
#include "nclgl/Light.h"

class Scene : public SceneNode
{
public:
    Scene(OGLRenderer &r, Camera *&camera);
    ~Scene();

    void SetIsRocky(bool isRocky);

    Light* GetLight() const { return light; }

protected:
    bool isRocky = true;
    Terrain *terrain;
    Light *light;
};
