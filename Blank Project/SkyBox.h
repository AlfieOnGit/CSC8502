#pragma once
#include "nclgl/SceneNode.h"

class SkyBox : public SceneNode
{
public:
    SkyBox();
    ~SkyBox();
    
    void Draw(OGLRenderer& r) override;
};

#define TEXDIR "Assets/SkyBox/Texture/"
