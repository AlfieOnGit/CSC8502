#include "ShaderManager.h"

#include "SkyBox.h"

Shader *ShaderManager::skyBox, *ShaderManager::bump = nullptr;

Shader* ShaderManager::GetBumpShader()
{
    if (!bump) bump = new Shader("BumpVertex.glsl", "BumpFragment.glsl");
    return bump;
}

Shader* ShaderManager::GetSkyBoxShader()
{
    if (!skyBox) skyBox = new Shader("skyboxVertex.glsl", "skyboxFragment.glsl");
    return skyBox;
}