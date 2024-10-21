#include "Renderer.h"

Renderer::Renderer(Window& parent): OGLRenderer(parent)
{
    triangles[0] = Mesh::GenerateTriangle(
        Vector3(0.5f, 0.5f, 0.0f),
        Vector3(0.5f, -0.5f, 0.0f),
        Vector3(-0.5f, -0.5f, 0.0f));
    triangles[1] = Mesh::GenerateTriangle(
        Vector3(0.5f, 0.5f, 0.0f),
        Vector3(-0.5f, 0.5f, 0.0f),
        Vector3(-0.5f, -0.5f, 0.0f));

    basicShader = new Shader("basicVertex.glsl", "colourFragment.glsl");

    if (!basicShader->LoadSuccess())
    {
        return;
    }
    init = true;
}

Renderer::~Renderer()
{
    delete[] triangles;
    delete basicShader;
}

void Renderer::RenderScene()
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    BindShader(basicShader);
    for (Mesh *t : triangles)
    {
        t->Draw();
    }
}


