#include "Scene.h"

#include "Tree.h"
#include "Water.h"

Scene::Scene(OGLRenderer &r, Camera *&camera)
{
    terrain = new Terrain(r);
    
    terrain->SetCamera(camera);
    AddChild(terrain);

    Water *water = new Water(r);
    water->SetCamera(camera);
    AddChild(water);

    //SceneNode *tree = new Tree();
    //AddChild(tree);
}

Scene::~Scene()
{
    delete terrain;
}

