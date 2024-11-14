#pragma once
#include "nclgl/OGLRenderer.h"

class HeightMap;
class Camera;

class Renderer : public OGLRenderer
{
public:
    Renderer(Window &parent);
    ~Renderer();
    void RenderScene() override;
    void UpdateScene(float dt) override;
protected:
    void DrawHeightMap();
    void DrawWater();
    void DrawSkybox();

    Shader *lightShader, *reflectShader, *skyboxShader;
    HeightMap *heightMap;
    Mesh *quad;

    Light *light;
    Camera *camera;

    GLuint cubeMap, waterTex, earthTex, earthBump;

    float waterRotate, waterCycle;
};
