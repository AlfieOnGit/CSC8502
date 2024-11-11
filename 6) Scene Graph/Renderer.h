#pragma once
#include "SceneNode.h"
#include "nclgl/OGLRenderer.h"
#include "nclgl/Camera.h"

class Renderer : public OGLRenderer
{
public:
    Renderer(Window &parent);
    ~Renderer();

    void UpdateScene(float dt) override;
    void RenderScene() override;

protected:
    void DrawNode(SceneNode *n);

    SceneNode* root;
    Camera* camera;
    Mesh* cube;
    Shader* shader;
};
