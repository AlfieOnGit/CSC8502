#pragma once
#include "nclgl/Shader.h"

class ShaderManager
{
public:
    static Shader *GetCombineShader();
    static Shader *GetPointLightShader();
    static Shader *GetSceneShader();
    static Shader *GetSkyBoxShader();

    static void ForceLoad();
    
private:
    static Shader *combine, *pointLight, *scene, *skyBox;
};