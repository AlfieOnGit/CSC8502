#include "Terrain.h"

#include "Scene.h"
#include "Blank Project/Manager/ShaderManager.h"

Vector3 Terrain::size = Vector3(0, 0, 0);


Terrain::Terrain(OGLRenderer &r)
{
    heightMap = new HeightMap(TEXTUREDIR"noise.png"); // TODO: Replace
    mesh = heightMap;
    rockyTex = SOIL_load_OGL_texture(SKYBOXDIR"Rock.jpg", SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
    rockyNormal = SOIL_load_OGL_texture(SKYBOXDIR"RockNormal.jpg", SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
    grassyTex = SOIL_load_OGL_texture(SKYBOXDIR"Grassy.jpg", SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
    grassyNormal = SOIL_load_OGL_texture(SKYBOXDIR"GrassyNormal.jpg", SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

    if (!rockyTex || !rockyNormal || !grassyTex || !grassyNormal)
        throw std::runtime_error("Terrain textures failed to load!");

    texture = rockyTex;
    currentNormal = &rockyNormal;
    r.SetTextureRepeating(texture, true);
    r.SetTextureRepeating(rockyNormal, true);
    r.SetTextureRepeating(grassyTex, true);
    r.SetTextureRepeating(grassyNormal, true);

    shader = ShaderManager::GetLightShader();
    if (!shader->LoadSuccess()) throw std::runtime_error("Terrain shader failed to load!");

    this->size = heightMap->GetHeightMapSize();
}

Terrain::~Terrain()
{
    delete heightMap;
    glDeleteTextures(1, &texture);
    glDeleteTextures(1, &rockyNormal);
    glDeleteTextures(1, &grassyTex);
    glDeleteTextures(1, &grassyNormal);
}

void Terrain::Draw(OGLRenderer& r)
{
    r.BindShader(shader);
    r.SetShaderLight(*static_cast<Scene*>(parent)->GetLight());
    glUniform3fv(glGetUniformLocation(shader->GetProgram(), "cameraPos"),
        1, (float*)&(*camera)->GetPosition());

    glUniform1i(glGetUniformLocation(shader->GetProgram(), "diffuseTex"), 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glUniform1i(glGetUniformLocation(shader->GetProgram(), "bumpTex"), 1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, *currentNormal);

    Matrix4 identity = Matrix4();
    identity.ToIdentity();
    r.SetModelMatrix(identity);
    r.SetTextureMatrix(identity);

    r.UpdateShaderMatrices();

    mesh->Draw();
}


// void Terrain::Draw(OGLRenderer& r)
// {
//     r.BindShader(shader);
//     
//     Matrix4 model = GetWorldTransform() * Matrix4::Scale(GetModelScale());
//     glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(), "modelMatrix"),
//         1, false, model.values);
//
//     glUniform4fv(glGetUniformLocation(shader->GetProgram(), "colour"),
//         1, (float*)&GetColour());
//     
//     glUniform1i(glGetUniformLocation(shader->GetProgram(), "diffuseTex"), 0);
//     glActiveTexture(GL_TEXTURE0);
//     glBindTexture(GL_TEXTURE_2D, texture);
//     
//     glUniform1i(glGetUniformLocation(shader->GetProgram(), "bumpTex"), 1);
//     glActiveTexture(GL_TEXTURE1);
//     glBindTexture(GL_TEXTURE_2D, *currentNormal);
//
//     glUniform3fv(glGetUniformLocation(shader->GetProgram(), "cameraPos"),
//         1, (float*)&(*camera)->GetPosition());
//
//     Matrix4 identity = Matrix4();
//     identity.ToIdentity();
//     r.SetModelMatrix(identity);
//     r.SetTextureMatrix(identity);
//
//     r.UpdateShaderMatrices();
//     
//     SceneNode::Draw(r);
// }

void Terrain::Flip()
{
    bool isRocky = texture == rockyTex;
    texture = isRocky ? grassyTex : rockyTex;
    currentNormal = isRocky ? &grassyNormal : &rockyTex;
}
