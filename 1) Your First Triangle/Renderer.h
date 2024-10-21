#pragma once
#include "NCLGL/OGLRenderer.h"

class Renderer : public OGLRenderer
{
public:
    Renderer(Window &parent);
    virtual ~Renderer();
    virtual void RenderScene();
protected:
    Mesh *triangles[2];
    Shader* basicShader;
};
