#include "ShaderManager.h"

#include "SkyBox.h"

Shader *ShaderManager::combine, *ShaderManager::pointLight, *ShaderManager::scene, *ShaderManager::skyBox = nullptr;

Shader* ShaderManager::GetCombineShader()
{
    if (!combine)
    {
        combine = new Shader("combinevert.glsl", "combinefrag.glsl");
        std::cout << "Combine made at: " << combine->GetProgram() << "!\n";
    }
    return combine;
}

Shader* ShaderManager::GetPointLightShader()
{
    if (!pointLight)
    {
        pointLight = new Shader("pointlightvert.glsl", "pointlightfrag.glsl");
        std::cout << "Point light made at: " << pointLight->GetProgram() << "!\n";
    }
    return pointLight;
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
    GetPointLightShader();
    GetSceneShader();
    GetSkyBoxShader();
}
