#include "SkyBox.h"

SkyBox::SkyBox() : SceneNode(Mesh::GenerateQuad())
{
    texture = SOIL_load_OGL_cubemap(
        TEXDIR"Left.png", TEXDIR"Right.png", TEXDIR"Up.png",
        TEXDIR"Down.png", TEXDIR"Front.png", TEXDIR"Back.png",
        SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, 0);

    if (!texture) throw std::runtime_error("SkyBox texture failed to load!");
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
    glUniform1i(glGetUniformLocation(shader->GetProgram(), "cubeTex"), 0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, texture);

    SceneNode::Draw(r);

    glDepthMask(GL_TRUE);
}

