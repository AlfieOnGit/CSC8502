#include "SkyBox.h"

#include "Manager/ShaderManager.h"
#include "Manager/TextureManager.h"

SkyBox::SkyBox() : SceneNode(Mesh::GenerateQuad())
{
    texture = TextureManager::GetSkyBoxTexture();
    if (!texture) throw std::runtime_error("SkyBox texture failed to load!");

    shader = ShaderManager::GetSkyBoxShader();
    if (!shader->LoadSuccess()) throw std::runtime_error("SkyBox shader failed to load!");
}

SkyBox::~SkyBox()
{
    glDeleteTextures(1, &texture);
}

void SkyBox::Draw(OGLRenderer& r)
{
    glDepthMask(GL_FALSE);
	
    r.BindShader(shader);
    r.UpdateShaderMatrices();
    //glUniform1i(glGetUniformLocation(shader->GetProgram(), "cubeTex"), 0);
    //glBindTexture(GL_TEXTURE_CUBE_MAP, texture);

    SceneNode::Draw(r);

    glDepthMask(GL_TRUE);
}

