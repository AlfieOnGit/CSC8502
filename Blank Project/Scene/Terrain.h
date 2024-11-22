#pragma once
#include "nclgl/Camera.h"
#include "nclgl/HeightMap.h"
#include "nclgl/SceneNode.h"

class Terrain : public SceneNode
{
public:
    Terrain(OGLRenderer &r);
    ~Terrain();

    void Draw(OGLRenderer& r) override;

    Vector3 GetHeightMapSize() const { return heightMap->GetHeightMapSize(); }

    void SetCamera(Camera *&camera) { this->camera = &camera; }
    Camera *GetCamera() const { return *camera; }

    void Flip() override;
    
protected:
    HeightMap *heightMap;
    GLuint rockyTex, rockyNormal, grassyTex, grassyNormal, *currentNormal;
    Camera **camera; // Pointer to the Renderer member variable (if camera is changed, doesn't need updating here)
};

#define TEXDIR "./Assets/Terrain/"
