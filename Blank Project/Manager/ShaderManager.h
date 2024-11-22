#pragma once
#include "nclgl/Shader.h"

class ShaderManager
{
public:
    static Shader *GetCombineShader();
    static Shader *GetLightShader();
    static Shader *GetPointLightShader();
    static Shader *GetReflectShader();
    static Shader *GetSceneShader();
    static Shader *GetSkyBoxShader();

    static void ForceLoad();
    
private:
    static Shader *combine, *light, *pointLight, *reflect, *scene, *skyBox;
};