#include "Water.h"

#include "Terrain.h"
#include "Blank Project/Manager/ShaderManager.h"
#include "Blank Project/Manager/TextureManager.h"

Water::Water(OGLRenderer &r) : SceneNode(Mesh::GenerateQuad())
{
    texture = SOIL_load_OGL_texture(TEXTUREDIR"water.TGA", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS);
    cubeMap = TextureManager::GetSkyBoxTexture();
    if (!texture || !cubeMap) throw std::runtime_error("Water texture failed to load!");

    shader = ShaderManager::GetReflectShader();
    if (!shader->LoadSuccess()) throw std::runtime_error("Water shader failed to load!");

    //light = new Light(Terrain::GetSize() * Vector3(0.5f, 1.5f, 0.5f), Vector4(1, 1, 1, 1),
    //    Terrain::GetSize().x);

    r.SetTextureRepeating(texture, true);

    waterCycle = 0.0f;
    waterRotate = 0.0f;
}

Water::~Water()
{
    glDeleteTextures(1, &texture);
}

void Water::Update(float dt)
{
    waterRotate += dt * 2.0f;
    waterCycle += dt * 0.25f;
}

void Water::Draw(OGLRenderer& r)
{
    r.BindShader(shader);

    glUniform3fv(glGetUniformLocation(shader->GetProgram(), "cameraPos"), 1,
        (float*)&(*camera)->GetPosition());

    glUniform1i(glGetUniformLocation(shader->GetProgram(), "diffuseTex"), 0);
    glUniform1i(glGetUniformLocation(shader->GetProgram(), "cubeTex"), 2);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMap);
    glDisable(GL_CULL_FACE);

    Vector3 hSize = Terrain::GetSize();

    r.SetModelMatrix(Matrix4::Translation(hSize * 0.5f)
        * Matrix4::Scale(hSize * 0.5f)
        * Matrix4::Rotation(90, Vector3(1, 0, 0)));

    r.SetTextureMatrix(Matrix4::Translation(Vector3(waterCycle, 0.0f, waterCycle))
        * Matrix4::Scale(Vector3(10, 10, 10))
        * Matrix4::Rotation(waterRotate, Vector3(0, 0, 1)));

    r.UpdateShaderMatrices();
    mesh->Draw();

    glEnable(GL_CULL_FACE);
}


