#pragma once
#include "nclgl/Camera.h"
#include "nclgl/SceneNode.h"
#include "nclgl/Light.h"

class Water : public SceneNode
{
public:
    Water(OGLRenderer &r);
    ~Water();

    void Update(float dt) override;
    void Draw(OGLRenderer& r) override;

    void SetCamera(Camera *&camera) { this->camera = &camera; }
    Camera *GetCamera() const { return *camera; }
    
protected:
    float waterRotate, waterCycle;
    //Light *light;
    GLuint cubeMap;
    Camera **camera;
};
