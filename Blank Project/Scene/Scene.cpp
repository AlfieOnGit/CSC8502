#include "Scene.h"

Scene::Scene(OGLRenderer &r, Camera *&camera)
{
    terrain = new Terrain(r);
    terrain->SetCamera(camera);
    AddChild(terrain);
}

Scene::~Scene()
{
    delete terrain;
}

