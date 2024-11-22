#pragma once
#include "nclgl/Camera.h"
#include "nclgl/SceneNode.h"

class Water : public SceneNode
{
public:
    Water(OGLRenderer &r);
    ~Water();

    void Update(float dt) override;
    void Draw(OGLRenderer& r) override;

    void SetCamera(Camera *&camera) { this->camera = &camera; }
    Camera *GetCamera() const { return *camera; }

    void Flip() override { isVisible = !isVisible; }
    
protected:
    bool isVisible = true;
    float waterRotate, waterCycle;
    GLuint cubeMap;
    Camera **camera;
};
