#include "Scene.h"

#include "Water.h"

Scene::Scene(OGLRenderer &r, Camera *&camera)
{
    terrain = new Terrain(r);
    
    terrain->SetCamera(camera);
    AddChild(terrain);

    Water *water = new Water(r);
    water->SetCamera(camera);
    AddChild(water);

    light = new Light(terrain->GetSize() * Vector3(0.0f, 1.5f, 1.0f),
    Vector4(1, 0, 1, 1), terrain->GetSize().x * 5);
}

Scene::~Scene()
{
    delete terrain;
}

