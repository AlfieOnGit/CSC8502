#pragma once
#include "../nclgl/OGLRenderer.h"

class Camera;
class HeightMap;

class Renderer: public OGLRenderer
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
    GLuint terrainTex;
};
