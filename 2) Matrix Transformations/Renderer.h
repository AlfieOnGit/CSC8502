#pragma once
#include "Camera.h"
#include "NCLGL/OGLRenderer.h"

class Renderer : public OGLRenderer
{
public:
    Renderer(Window &parent);
    virtual ~Renderer();

    virtual void RenderScene();
    virtual void UpdateScene(float dt);

    void SwitchToPerspective();
    void SwitchToOrthographic();

    void SetScale(float s) { scale = s; }
    void SetRotation(float r) { rotation = r; }
    void SetPosition(Vector3 p) { position = p; }

protected:
    Mesh* triangle;
    Shader* matrixShader;
    float scale;
    float rotation;
    Vector3 position;
    Camera* camera;
};