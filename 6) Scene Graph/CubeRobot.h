#pragma once
#include "nclgl/Mesh.h"
#include "nclgl/SceneNode.h"

class CubeRobot : public SceneNode
{
public:
    CubeRobot(Mesh* cube);
    ~CubeRobot() {}
    void Update(float dt) override;

protected:
    SceneNode *head, *leftArm, *rightArm;
};
