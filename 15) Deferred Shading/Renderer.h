﻿#pragma once
#include "nclgl/OGLRenderer.h"

class Camera;
class Mesh;
class HeightMap;

class Renderer : public OGLRenderer
{
public:
    Renderer(Window &parent);
    ~Renderer();

    void RenderScene() override;
    void UpdateScene(float dt) override;

protected:
    void FillBuffers();
    void DrawPointLights();
    void CombineBuffers();

    void GenerateScreenTexture(GLuint &into, bool depth = false);

    Shader *sceneShader, *pointLightShader, *combineShader;

    GLuint bufferFBO, bufferColourTex, bufferNormalTex, bufferDepthTex;

    GLuint pointLightFBO, lightDiffuseTex, lightSpecularTex;

    HeightMap *heightMap;
    Light *pointLights;
    Mesh *sphere, *quad;
    Camera *camera;
    GLuint earthTex, earthBump;
};
