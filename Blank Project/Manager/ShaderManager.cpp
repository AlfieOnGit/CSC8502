#include "ShaderManager.h"

Shader *ShaderManager::combine, *ShaderManager::light, *ShaderManager::pointLight, *ShaderManager::reflect,
    *ShaderManager::scene, *ShaderManager::skyBox = nullptr;

Shader* ShaderManager::GetCombineShader()
{
    if (!combine) combine = new Shader("combinevert.glsl", "combinefrag.glsl");
    return combine;
}

Shader* ShaderManager::GetLightShader()
{
    if (!light) light = new Shader("PerPixelVertex.glsl", "PerPixelFragment.glsl");
    return light;
}

Shader* ShaderManager::GetPointLightShader()
{
    if (!pointLight) pointLight = new Shader("pointlightvert.glsl", "pointlightfrag.glsl");
    return pointLight;
}

Shader* ShaderManager::GetReflectShader()
{
    if (!reflect) reflect = new Shader("reflectVertex.glsl", "reflectFragment.glsl");
    return reflect;
}


Shader* ShaderManager::GetSceneShader()
{
    if (!scene) scene = new Shader("BumpVertex.glsl", "bufferFragment.glsl");
    return scene;
}


Shader* ShaderManager::GetSkyBoxShader()
{
    if (!skyBox) skyBox = new Shader("skyboxVertex.glsl", "skyboxFragment.glsl");
    return skyBox;
}

void ShaderManager::ForceLoad()
{
    GetCombineShader();
    GetLightShader();
    GetPointLightShader();
    GetReflectShader();
    GetSceneShader();
    GetSkyBoxShader();
}
