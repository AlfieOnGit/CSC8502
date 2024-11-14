#pragma once
#include "nclgl/OGLRenderer.h"

class Camera;
class Mesh;

class Renderer : public OGLRenderer
{
public:
    Renderer(Window &parent);
    ~Renderer();

    void UpdateScene(float dt) override;
    void RenderScene() override;
    
protected:
    void DrawShadowScene();
    void DrawMainScene();

    GLuint shadowTex, shadowFBO;

    GLuint sceneDiffuse, sceneBump;
    float sceneTime;

    Shader *sceneShader, *shadowShader;

    vector<Mesh*> sceneMeshes;
    vector<Matrix4> sceneTransforms;

    Camera *camera;
    Light *light;
};
