#pragma once
#include "nclgl/Camera.h"
#include "nclgl/HeightMap.h"
#include "nclgl/SceneNode.h"

class Terrain : public SceneNode
{
public:
    Terrain();
    ~Terrain();

    void Draw(OGLRenderer& r) override;

    Vector3 GetHeightMapSize() const { return heightMap->GetHeightMapSize(); }

    void SetCamera(Camera *&camera) { this->camera = &camera; }
    Camera *GetCamera() const { return *camera; }
    
protected:
    HeightMap *heightMap;
    GLuint bumpMap;
    Camera **camera; // Pointer to the Renderer member variable (if camera is changed, doesn't need updating here)
};
