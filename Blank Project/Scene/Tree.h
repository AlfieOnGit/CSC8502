#pragma once
#include "nclgl/SceneNode.h"
#include "nclgl/Camera.h"

class Tree : public SceneNode
{
public:
    Tree(Camera *&camera);
    ~Tree();

    void Draw(OGLRenderer& r) override;

protected:
    Camera** camera;
};
