#pragma once
#include "nclgl/Camera.h"
#include "nclgl/HeightMap.h"
#include "nclgl/OGLRenderer.h"

class Renderer : public OGLRenderer
{
public:
    Renderer(Window &parent);
    ~Renderer();

    void RenderScene() override;
    void UpdateScene(float dt) override;

protected:
    void PresentScene();
    void DrawPostProcess();
    void DrawScene();

    Shader *sceneShader;
    Shader *processShader;

    Camera *camera;
    Mesh *quad;
    HeightMap *heightMap;
    GLuint heightTexture;
    GLuint bufferFBO;
    GLuint processFBO;
    GLuint bufferColourTex[2];
    GLuint bufferDepthTex;
};
