#pragma once
#include <glad/glad.h>

class TextureManager
{
public:
    static GLuint GetSkyBoxTexture();
    
private:
    static GLuint skyBox;
};

#define SKYBOXDIR "./Assets/SkyBox/Texture/"
