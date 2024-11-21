#include "Terrain.h"

#include "Blank Project/ShaderManager.h"

Terrain::Terrain(OGLRenderer &r)
{
    heightMap = new HeightMap(TEXTUREDIR"noise.png"); // TODO: Replace
    mesh = heightMap;
    texture = SOIL_load_OGL_texture(TEXDIR"Rock.jpg", SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
    bumpMap = SOIL_load_OGL_texture(TEXDIR"RockNormal.jpg", SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

    if (!texture || !bumpMap) throw std::runtime_error("Terrain textures failed to load!");

    r.SetTextureRepeating(texture, true);

    shader = ShaderManager::GetBumpShader();
    if (!shader->LoadSuccess()) throw std::runtime_error("Terrain shader failed to load!");
}

Terrain::~Terrain()
{
    delete heightMap;
    glDeleteTextures(1, &texture);
    glDeleteTextures(1, &bumpMap);
}

void Terrain::Draw(OGLRenderer& r)
{
    r.BindShader(shader);
    
    Matrix4 model = GetWorldTransform() * Matrix4::Scale(GetModelScale());
    glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(), "modelMatrix"),
        1, false, model.values);

    glUniform4fv(glGetUniformLocation(shader->GetProgram(), "colour"),
        1, (float*)&GetColour());
    
    glUniform1i(glGetUniformLocation(shader->GetProgram(), "diffuseTex"), 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glUniform1i(glGetUniformLocation(shader->GetProgram(), "bumpTex"), 1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, bumpMap);

    glUniform3fv(glGetUniformLocation(shader->GetProgram(), "cameraPos"),
        1, (float*)&(*camera)->GetPosition());

    r.UpdateShaderMatrices();
    
    SceneNode::Draw(r);
}

