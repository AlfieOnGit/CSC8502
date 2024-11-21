#pragma once
#include "nclgl/Shader.h"

class ShaderManager
{
public:
    static Shader *GetBumpShader();
    static Shader *GetSkyBoxShader();
    
private:
    static Shader *bump, *skyBox;
};