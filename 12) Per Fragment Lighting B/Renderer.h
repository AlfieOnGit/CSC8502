﻿#pragma once
#include "nclgl/OGLRenderer.h"
#include "../nclgl/Shader.h"

class HeightMap;
class Camera;
class Light;
class Shader;

class Renderer : public OGLRenderer
{
public:
    Renderer(Window &parent);
    ~Renderer();

    void RenderScene() override;
    void UpdateScene(float dt) override;

protected:
    HeightMap *heightMap;
    Shader *shader;
    Camera *camera;
    Light *light;
    GLuint texture;
    GLuint bumpMap;
};
